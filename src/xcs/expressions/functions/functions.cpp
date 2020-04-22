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

}


/*
  Declarations
*/
//  Parameters
ErrorCode FunctionNode::declareParameter(Identifier ident, ADR reg)
{ 
  parameters.push_back( FunctionParameterNode(ident, reg) ); 

  std::string _str = "Parameter "; _str.append(_ident); _str += " declared";
  l.log('D', "Functions", _str);

  return SUCCESS; 
}


/*
  Resolutions
*/
//  Resolve Function
FunctionID FunctionNode::resolve()
{
  //  Executed when function is called
  char* str = (char*) malloc(50);

  /*
    TODO: Load Parameters Here
  */

  sprintf(str, "  bl    __%lu_%s", _fid, _ident);
  add_command(str);
  
  /*
    TODO: Handle Return Value Registers
  */

  std::string _str = "Function "; _str.append(_ident); _str += " resolved";
  l.log('D', "Functions", _str);

  free (str);
  return _fid;
}


unsigned long FunctionNode::resolveParameter(Identifier ident)
{

  std::string _str = "Parameter "; _str.append(_ident); _str += " resolved";
  l.log('D', "Functions", _str);

  return 0; //  STUB
}

