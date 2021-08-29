/*
  manager.cpp
  Codeus Tech
  Authored on   April 18, 2020
  Last Modified  July 03, 2021
*/

/*
  Contains implementations for ContextManager Class


  Table of Contents
  =================
  1.) 
  2.) Public Operations
    2.a) Module Operations
    2.b) Assembly Operations
    2.c) Register Stack Operations
    2.d) Scope Handling
    2.e) Operators
  3.) Identifier Handling
    3.a) Type Operations
    3.b) Typeclass Operations
    3.c) Constant Operations
    3.d) Function Operations
*/

#include "manager.h"
#include "../expressions/primitives/primitives.h"

/*
  Constructors
*/
ContextManager::ContextManager()
{
  //  Add Root Module/Scope
  modules.push_back(ModuleNode(0, ModuleType::XCSL_SOURCE, 0, this));
  _context = &modules[0];

  initializePrimitives(*this);

  //  Set Type
  LastType(TYPE_ARBITRARY);

  l.log('D', "ContextManager", "Context Manager has been initialized");
}



/*
  2.) Public Operations
*/

//  2.a) Module Operations
  /*
    importModule()
      Creates a new ModuleNode for holding the new reference frame and
      connects into the root ModuleNode (e.g. the compiled target file).
  */
  ErrorCode ContextManager::importModule(ModuleType mtype)
  {
    int index = modules.size();
    modules.push_back(ModuleNode(_next_mid++, mtype, modules.back().Id(), this));
    _context = &modules[index];
    l.log('D', "Modules", "Module Imported and Context Shifted Accordingly");

    return SUCCESS;
  }

  ErrorCode ContextManager::executeModule() { /* Down the Road */ return SUCCESS; }


// 2.c) Register Stacks

  /*
    rsPush(TYPE)
      This method allocates an inactive (unused) CPU register in the register stack
      and returns the associated integer code used for data manipulation.

      This is a fundamental operation of the XCS system and can be called many times 
      in a function's lifetime.  Each push operation provides an independent data element.
  */
  ADR ContextManager::rsPush(TypeID tid)
  { 
    LastType(tid); 
    return _context->rsPush(tid); 
  }

  /*
    rsCopy(TYPE, ADR)
      This method allocates an inactive (unused) CPU register in the register stack
      and copies the data/type held in `ADR` into the freshly allocated register.

      This occurs when the original data is needed an arbitrary number of times,
      but the copied data entries need to be treated as independent elements (e.g. parameters).
  */
  ErrorCode ContextManager::rsCopy(TypeID tid, ADR src) 
  { 
    //  Get a new register
    ADR dest = rsPush(tid);

    //  Copy Data from src to dest
    char* str = (char*) malloc(50);
    sprintf(str, "  mov   %s, %s", get_reg(dest, 8*TypeSize(tid)), get_reg(src, 8*TypeSize(tid)));  

    addInstruction(str);

    return SUCCESS; 
  }

  /*
    rsMerge(TYPE, ADR)
      This method merges the data/type held in `ADR` into the current register stack.
      If `ADR` is already allocated, it will merge the data into an unallocated register, instead.

      ADRs are merged into the current register stack when the return value of a 'child' function
      call is used in the body of a 'parent' function.
  */
  ADR ContextManager::rsMerge(TypeID tid, ADR reg)
  {
    LastType(tid);
    return _context->rsMerge(tid, reg);
  }


//  2.d) Scope Handling
  /*
    concludeExpression()
      This method is called when `;;` is encountered in XCSL.
      It ends the current expression and prepares the next one for execution.
  */
  ErrorCode ContextManager::concludeExpression()
  { 
    LastType(TYPE_ARBITRARY); 
    LastData((Arbitrary) TYPE_ARBITRARY);
    LastExpression(EXP_LITERAL);

    assembly.concludeExpression();
    return _context->concludeExpression(); 
  }


// 2.e) Operators
  /*
    resolveOperator(OID)
      This method is called when an operator is encountered.
      It routes the request to the OperatorManager, along with the Operator ID code.
      If it valid operation/operands in this context, it performs the operation.
  */
  ErrorCode ContextManager::resolveOperator(OperatorID oid) 
  { 
    LastExpression(EXP_LITERAL);
    char* ret = operators.solveOperator(oid, _context->rsCurrent()); 
    if (ret)  { addInstruction(ret); free(ret); }
    else      { return 1; /* FAILURE */ }
    return SUCCESS;
  }

  /*
    TypeCheck() -> Boolean
      This performs a TypeCheck operation, most frequently used in `is` expressions
  */
  bool ContextManager::TypeCheck()
  {
    TypeID left;
    TypeID right;

    right = rsType();
    left  = rsSecType();

    if (left == right) return true;
    if (_context->_IsAliased(right, left)) 
    {
      string str = "Type check succeeded for " + string(resolveTypeIdentifier(left)) + " as type alias for:  " + string(resolveTypeIdentifier(right));
      l.log('d', "TypeCheck", str);
      return true;
    }

    return false;
  }

/*
  3.) Identifier Operations
*/

/*
  3.a) Type Operations
*/

 //  Declarations

  /*
    declareTypeParameter (IDENT)
      Adds a parameter with name: `IDENT` to the current Type declaration
  */
  ErrorCode ContextManager::declareTypeParameter(Identifier ident) 
  { 
    string tmp = string(ident);
    ErrorCode rtn = _context->_declareTypeParameter(_next_tid++, ident);
    if ((rtn == SUCCESS))
    {
      string str = "Declared Type Parameter: " + tmp;
      l.log('d',"DeclType", str);
    }
    return rtn; 
  }

  /*
    declareTypeAlias (TYPE)
      Declares current type declaration as an alias for `TYPE`
  */
  ErrorCode ContextManager::declareTypeAlias(TypeID tid) 
  {
    l.log('d', "DeclType", "Aliased current type declaration for: " + string(resolveTypeIdentifier(tid))); 
    return _context->_declareTypeAlias(tid); 
  }

  /*
    declareTypeElement (IDENT, TYPE)
      Declares a new element in the current constructor with name `IDENT`.
  */
  ErrorCode ContextManager::declareTypeElement(Identifier ident, TypeID tid) 
  {
    return _context->_declareTypeElement(ident, tid); 
    }

  //  Resolutions
  /*
    resolveType (IDENT)
      Searches current context for a type with requested identifier: `IDENT`
      If found, returns the TypeID number
        otherwise, returns Null
  */
  TypeID ContextManager::resolveType(Identifier ident)
  {
    TypeID tid;

    if ((tid = resolveTypeParameter(ident)))
      return LastType(tid);

    if ((tid = _context->_resolveTypeclass(ident)))
      return LastType(tid);

    if ((tid = _context->_resolveType(ident)))
      return LastType(tid);

    for (unsigned long i = 0; i < _context->imported.size(); ++i)
      if ((tid = modules[_context->imported[i]]._resolveType(ident)))
        return LastType(tid);

    std::string str = "Failed to Resolve Type: " + string(ident);
    l.log('E', "ExpType", str);

    return NULL;
  }

  /*
    resolveTypeParameter (IDENT)
      Searches current type declaration for a parameter named `IDENT`
      If found, returns the TypeID
        otherwise, returns Null
  */
  TypeID ContextManager::resolveTypeParameter(Identifier ident) 
  { 
    TypeID tid = _context->_resolveTypeParameter(ident);
    if (tid)
    {
      string str = "Resolved Type Parameter: " + string(ident);
      l.log('d', "ExpType", str);
      return tid;
    }
    return NULL;
  }

 /*
  resolveConstructor (IDENT)
    Searches current context for a Type Constructor named `IDENT`
    If found, returns the ConstructorID
      otherwise, returns Null
 */
 ConstructorID ContextManager::resolveConstructor(Identifier ident)
 {
   unsigned long* rtn = _context->_resolveTypeConstructor(ident);
   
   if (rtn[0])
   {
     
     LastType(rtn[0]);
     LastConstructor(rtn[1]);

     std::string str = "Resolved Constructor: " + string(ident);

     l.log('D', "Constructors", str);

     free(rtn);
     return LastConstructor();
   }

   std::string str = "Failed to Resolve Constructor: " + string(ident);
   l.log('E', "ExpStruct", str);

   return NULL;
 }

  /*
    resolveTypeElement (IDENT)
      Searches current context for a sub-element named `IDENT`.
      If found, the data is pushed onto the current register stack and Type ID is returned
        otherwise, returns Null
        NOTE:  This may need to be changed, because one error case returns 0
  */
  TypeID ContextManager::resolveTypeElement(Identifier ident)
  {
    TypeID tid = _context->_resolveTypeElement(ident, LastConstructor(), LastType());
    if (tid) 
    {
      if (XCS_VERBOSE) printf("Accessed Record: %s\n", ident); 
      //  Set Current Type
      LastType(tid);

      switch(tid)
      {
        case TYPE_INTEGER:
          
        default:
          std::string str = "Record type is unrecognized: " + string(ident);
          l.log('E', "ExpStruct", str);
          return 0;
      }


      /*
        TODO: Use Relative Positioning in Type to determine which element needs to be extracted

        e.g., in `complex_nodefault`, (Person) x.name should return the first expression.
        
        Additionally, this needs to be "smart" enough to detect when a type has > XYZ number of elements to start using SRAM, rather than registers
      */

      std::string str = "Accesed Record: " + string(ident) + " of type: " + string(resolveTypeIdentifier(tid));
      l.log('D', "ExpStruct", str);
      return tid;
    }

    /*
      TODO: Check other child module nodes for this element identifier
    */
    std::string str = "Failed to Access Record: " + string(ident);
    l.log('E', "ExpStruct", str);

    return NULL;
  }


/*
  3.b) Typeclass Operations
*/

  ErrorCode ContextManager::implementTypeclass(Identifier ident)
  {
    l.log('d', "ImplTypeclass", "Current Type Declaration implements " + string(ident));

    return SUCCESS;
  }

/*
  3.c) Constant Operations
*/

  /*
    declareConstant (IDENT)
      This method adds a new ConstantNode to the current context, named `IDENT`.
      The new ConstantNode is prepped for holding statically-computed constant data.
  */
  ErrorCode ContextManager::declareConstant(Identifier ident)
  {
    //  Grab Value from Constant Address
    //    and push into the Register Stack
    char* str = (char*) malloc(300);
    
    DataInstance last = data.getData();

    switch (last.tid)
    {
      case TYPE_NULL:
      case TYPE_ARBITRARY:
      case TYPE_LIST:         //  TODO:  Lists should EVENTUALLY be able to be constant
        free (str);
        l.log('W', "DeclConst", string("Type not supported for Constant Declarations"));
        return ERR_TYPE_UNSUPPORTED;
      case TYPE_INTEGER:
      case TYPE_U32:
      case TYPE_I32:
        sprintf(str, "%s: .word %llu", ident, (unsigned long long) last.value);
        addConstant(str);
        break;
      case TYPE_I8:
      case TYPE_U8:
      case TYPE_CHAR:
        sprintf(str, "%s: .byte %llu", ident, (unsigned long long) last.value);
        addConstant(str);
        break;
      case TYPE_STRING:
        sprintf(str, "%s: .ascii \"%s\"", ident, (char*) last.value);
        addConstant(str);
        break;
      default:
        int chk = _context->typeCheck(last.tid);
        if (chk)
        {
          free (str);
          l.log('W', "DeclConst", string("Type not defined"));
          return ERR_TYPE_UNDEFINED;
        }
        
    }

    free (str);

    return _context->declareConstant(_next_cid++, ident, data.getData().tid, data.getData().value);
  }

  /*
    resolveConstant (IDENT)
      This method determines if there is a constant value named `IDENT`.
      If the current context does have it, the ConstantID is returned.
        otherwise, it returns Null
  */
  ConstantID ContextManager::resolveConstant(Identifier ident)
  {
    //  TODO:  Check OTHER module contexts
    ConstantNode* node = _context->resolveConstant(ident);
    ConstantID cid = node->Id();

    addData(node->Type(), node->Value());

    if (!cid) return NULL;

    //  Constant Found -- Resolve Here
    //  Push Type
    rsPush(cid);
    char* top = get_reg(rsTop(), 32); //  TODO: Fix Size (32), use type size instead

    char* str = (char*) malloc(300);
    sprintf(str, "  ldr   %s, =%s", top, ident);
    addInstruction(str); free(str);

    std::string _str = "Resolved constant "; 
    _str.append(ident); 
    _str += " as type " + string(resolveTypeIdentifier(LastType()));

    l.log('D', "ExpConst", _str);

    return cid;
  }

/*
  3.d) Function Operations
*/
  /*
    declareFunction (IDENT)
      This method creates a new function of name `IDENT` and adds to current context.
  */
  ErrorCode ContextManager::declareFunction(Identifier ident) 
  {
    FunctionID fid = _next_fid++;
    assembly.initFunction(ident, fid);
    return _context->declareFunction(fid, ident);
  }

  ErrorCode ContextManager::declareFunctionParameter(Identifier ident)
  {
    rsPush(TYPE_ARBITRARY); //  Allocate a register for the parameter

    if (XCS_VERBOSE) printf ("Declared Function Parameter: %s\n", ident);
    
    return _context->declareFunctionParameter(ident);
  }

  /*
    endDeclareFunction()
      This method is called when a function declaration ends.
      It sets all final metadata for a function call, e.g. type signature, etc.
  */
  ErrorCode ContextManager::endDeclareFunction()
  {
    char* ident;
    string logstr;
    if ((ident = _context->endDeclareFunction(LastType())))
    {
      //  Conclude Function Assembly
      assembly.endFunction();

      logstr = "Function " + string(ident) + " declared, with Type Signature: " + TypeSignature();
      l.log('D', "DeclFunct", logstr);

      if (XCS_VERBOSE) printf("Declared Function: %s\n", ident);
    } else
    {
      yyerror(string("Function Declaration Failed").c_str());
    }
    return SUCCESS;
  }

  /*
    resolveFunction (IDENT)
      This method determines if there is a valid function declaration of name `IDENT`
        and that accepts parameters that match the current loaded arguments.
      If a matching function declaration is found, it returns the matching FunctionID
        otherwise, it returns Null
  */
  FunctionID ContextManager::resolveFunction(Identifier ident)
  {
    //  Executed when function is called
    char* str = (char*) malloc(50);

    //  First check current context
    FunctionNode* node = _context->resolveFunction(ident, arguments);
    if (node)
    {
      /*
        TODO: Compare Parameter/Argument Count/Types for handling overloaded functions
      */

      //  Handle Arguments
      char* arg_reg; char* param_reg; int i = 0;
      while (!arguments.empty())
      {
        ArgumentNode arg = resolveArgument();
        _context->rsRemove(arguments.size());
        arg_reg = get_reg(arg.reg, 8*4);                      /* TODO: Replace w/ Type Size */
        param_reg = get_reg(node->ParameterRegister(i), 8*4); /* TODO: Replace w/ Type Size */

        sprintf (str, "  mov   %s, %s", param_reg, arg_reg);
        addInstruction(str);
        i++;

      
        free(arg_reg); free(param_reg);
      }

      sprintf(str, "  bl    __%lu_%s", node->Id(), ident);
      addInstruction(str);

      
      rsMerge(node->Type(), node->Register());
      LastExpression(EXP_FUNCTION);

      std::string _str = "Resolved function "; _str.append(ident); _str += " resolved as type " + string(resolveTypeIdentifier(LastType()));
      if (XCS_VERBOSE) printf ("Resolved Function: %s\n", node->Ident());
      l.log('D', "ExpFunct", _str);

      free (str);
      return node->Id();
    }

    //  TODO: Check Child (Imported) Module Nodes

    free (str);
    return NULL;
  }

  /*
    resolveFunctionParameter (IDENT)
      This method determines if the current function declaration has a parameter named `IDENT`.
      If it does, the TypeID is returned for the matching parameter
        otherwise, returns Null
  */
  TypeID ContextManager::resolveFunctionParameter(Identifier ident)
  { 
    FunctionParameterNode* param = _context->resolveFunctionParameter(ident); 
    if (param)
    {
      rsCopy(param->Type(), param->Register());  //  Add Data/Type to Register Stack 
      LastExpression(EXP_PARAMETER);                  //  Set Status Variables  -- DEPRECATED???
      LastIndex(param->getIndex());                   //  Set Last Seen Index   -- DEPRECATED???

      if (XCS_VERBOSE) printf("Parameter Encountered: %s\n", ident);
      string str = "Resolved parameter " + string(ident) + " of type " + resolveTypeIdentifier(LastType()) + " in register: " + to_string(param->Register());
      l.log('d', "ExpFunct", str);
      return LastType();
    }
    return NULL;
  }

  TypeID ContextManager::resolveMemoryVariable(Identifier ident)
  {
    MemoryVariable* mem = memory.getMemoryVariable(ident);
    if (mem)
    {
      char* sec = get_reg(rsTop(), 64);
      ADR reg = rsPush(mem->Type());
      LastExpression(EXP_MEMORY);
      char* top = get_reg(reg, 32);
      char* str = (char*) malloc(50);

      sprintf(str, "  ldr %s, [%s]", top, sec);
      addInstruction(str);

      if (XCS_VERBOSE) printf("Memory Variable Encountered: %s\n", ident);

      free(str); free(top); free(sec);
      //  NOTE:  Might be erroneous...
      //         'Sec' might need to get popped here.
      return mem->Type();
    }
    return NULL;
  }


  /*
    Function Type Signatures
  */
  /*
    TypeSignature()
      This method returns a string that matches the type signature for current function declaration
      The returned string is formatted like:
          a -> b -> c
      Where `a` and `b` are parameters and `c` is the return value.  

      A practical example might be -- `let sum x y = x + y`:
          int -> int -> int
        NOTE:  this will eventually be `number -> number -> number`
  */
  string ContextManager::TypeSignature()
  {
    Index index;
    string _str = "( ";
    TypeID* tsig = _context->TypeSignature();

    for (Index i = 0; i < _context->_CountFunctionParameters(); ++i)
    {
      index = i+1;  

      ParameterRestrictions restrict = _context->_ParamRestrictions(i);
      if (tsig[index] == TYPE_ARBITRARY )
      {
        if (!restrict.construct.empty())
        {
          _str += "(";
          for (Index j = 0; j < restrict.construct.size(); ++j)
          {
            _str += string(resolveConstructorIdentifier(restrict.construct[j]));
          }
          _str += ")";
        }
      }
      else
        _str += string(resolveTypeIdentifier(tsig[index]));
      _str += " -> ";
    }
    _str += string(resolveTypeIdentifier(tsig[0])) + " )";
    return _str;
  }



/*
  Resolve Arbitrary Identifier Expression
*/
/*
  resolveExpression (IDENT)
    This method is used to determine what an identifier is referring in context.
    It will have a variety of behaviors, depending on if `IDENT` is a:
      * Function Parameter
      * Function Name
      * Constant value
    In all cases, it will place the data element linked with `IDENT` 
      on top of the current register stack
*/
unsigned long ContextManager::resolveExpression(Identifier ident) 
{
  unsigned long _id;

  if ((_id = resolveMemoryVariable(ident)))
    return _id;

  //  Resolve Parameter
  if ((_id = resolveFunctionParameter(ident)))
    return _id;

  //  Resolve Function
  if ((_id = resolveFunction(ident)))
    return _id;

  //  Resolve Constant
  if ((_id = resolveConstant(ident)))
    return _id;


  std::string _str = "Identifier '" + string(ident) + "' could not be resolved";
  l.log('W', "Identifiers", _str);

  return 0;
}


/*
  castExpression (IDENT)
    This method attempts to cast the current sub-expression (e.g. top of register stack)
      as given constructor, `IDENT`.
*/
unsigned long ContextManager::castExpression(Identifier constructor)
{

  //  Grab Last Expression's Infromation
  TypeID _tid = LastType();
  ConstructorID _cid = LastConstructor();
  Arbitrary _data = LastData();
  ADR _reg = rsTop();

  std::string _str;

  ConstructorID cid = resolveConstructor(constructor);
  if (cid)
  {
    switch(LastExpression())
    {
      case EXP_LITERAL:
        /* TODO: Cast Literal */
        
        _str = "Literal";
        break;
      case EXP_FUNCTION:
        /* TODO: Cast Function */
        
        _str = "Functional";
        break;
      case EXP_PARAMETER:
        /* TODO: Cast Parameter */
        _context->castParameter(cid, LastIndex());
        
        _str = "Parameter";
        break;
    }

    _str += " expression has been cast to " + string(resolveTypeIdentifier(LastType()));
    l.log('D', "TypeCast", _str);
    return cid; //  Will probably change
  }

  /*
    TODO: If previous_tid is compatible with cid's possible inputs
          Currently assumes it is compatible.
  */



  return 0;
}



