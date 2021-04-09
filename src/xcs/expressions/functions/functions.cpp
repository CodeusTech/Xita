/*
  functions.cpp
  Codeus Tech
  Authored on   April 20, 2020
  Last Modified April 20, 2020
*/

/*
  Contains functionality for handling XCS Function Declarations
*/

#include "functions.h"

/*
  Constructors
*/
FunctionNode::FunctionNode(FunctionID fid, ModuleID context, Identifier ident)
{
  _fid = fid;
  _context = context;
  _ident = strdup(ident); free(ident);

  _rtn_type = TYPE_ARBITRARY;

  std::string str = "Function " + string(_ident) + " has been Initialized";
  l.log('d', "DeclFunct", str);
}

TypeID* FunctionNode::TypeSignature()
{
  TypeID* sig = (TypeID*) malloc(sizeof(TypeID)*(CountParameters()+1));
  sig[0] = _rtn_type;
  for (unsigned long i = 0; i < CountParameters(); ++i)
    sig[i+1] = parameters[i].Type();
  return sig;
}

/*
  Declarations
*/
//  Parameters
ErrorCode FunctionNode::declareParameter(Identifier ident, ADR reg)
{ 
  Index i = parameters.size();
  parameters.push_back( FunctionParameterNode(ident, reg, i) ); 

  std::string _str = "Parameter " + string(parameters.back().Ident()) + " declared, using register: " + to_string(reg);
  l.log('D', "DeclFunct", _str);

  return SUCCESS; 
}


/*
  Resolutions
*/
FunctionParameterNode* FunctionNode::resolveParameter(Identifier ident)
{
  for (unsigned long i = 0; i < parameters.size(); ++i)
    if (strcmp(ident, parameters[i].Ident()) == 0)
      return &parameters[i];
  return 0;
}



