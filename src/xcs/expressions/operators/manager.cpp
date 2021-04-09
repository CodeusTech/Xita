/*
  manager.cpp (Operators)
  Codeus Tech
  Authored on   March 3, 2021
  Last Modified March 3, 2021
*/

/*
  Extended implementations for operator manager
*/

#include "manager.h"
#include "../../context/manager.h"


char* OperatorManager::solveOperator(OperatorID oid, RegisterStack* rs)
{ 
  switch (oid)
  {
    //  2.e.I) Arithmetic
    case OPERATOR_ADDITION:         //  Addition
      return addition.resolve(rs);
    case OPERATOR_SUBTRACT:         //  Subtraction
      return subtract.resolve(rs);
    case OPERATOR_MULTIPLY:         //  Multiplication
      return multiply.resolve(rs);   
    case OPERATOR_DIVISION:         //  Division
      return division.resolve(rs);
    case OPERATOR_MODULUS:          //  Modulus (Remainder of Division)
      l.log('d', "Operators", "Resolved Modulus Operation");
      return SUCCESS;

    //  2.e.II) Bitwise
    case OPERATOR_BIT_AND:          //  Bitwise AND
      return bitwise_and.resolve(rs);
    case OPERATOR_BIT_OR:           //  Bitwise OR
      return bitwise_or.resolve(rs);
    case OPERATOR_BIT_XOR:          //  Bitwise Exclusive OR
      return bitwise_xor.resolve(rs);
    case OPERATOR_BIT_SHL:          //  Shift Bits Left
      return bitwise_shl.resolve(rs);
    case OPERATOR_BIT_SHR:          //  Shift Bits Right
      return bitwise_shr.resolve(rs);

    //  2.e.III) Logical
    case OPERATOR_AND:              //  Logical AND
      return logical_and.resolve(rs);
    case OPERATOR_OR:               //  Logical OR
      return logical_or.resolve(rs);
    case OPERATOR_XOR:              //  Logical Exclusive OR
      return logical_xor.resolve(rs);
    case OPERATOR_GT:               //  Greater Than
      return logical_gt.resolve(rs);
    case OPERATOR_GTE:              //  Greater Than or Equal To
      return logical_gte.resolve(rs);
    case OPERATOR_LT:               //  Less Than
      return logical_lt.resolve(rs);
    case OPERATOR_LTE:              //  Less Than or Equal To
      return logical_lte.resolve(rs);
    case OPERATOR_EQ:               //  Equal To
      return logical_eq.resolve(rs);
    case OPERATOR_NEQ:              //  Not Equal To
      return logical_neq.resolve(rs);

    case OPERATOR_MEM_GET:
      return resolveMemoryGet(rs);
    case OPERATOR_MEM_SET:
      return resolveMemorySet(rs);

    default:
      //  Default Operator
      l.log('e', "Operators", "Unrecognized operator node resolved");  
      return NULL; 
  }
      l.log('e', "Operators", "Unrecognized operator node resolved");  
  return NULL;
}
