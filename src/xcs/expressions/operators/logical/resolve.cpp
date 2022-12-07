/*
  resolve.cpp
  Codeus Tech
  Authored on   October 27, 2020
  Last Modified December 7, 2022
*/

/*
  FORWARD DECLARATIONS

  Contains extended definitions for Logical Operator Functionalities
*/

#include "lt.h"
#include "gt.h"
#include "eq.h"

#include "and.h"
#include "or.h"
#include "xor.h"

#include "../../../context/manager.h"


/*
    BOOLEAN LOGIC OPERATORS
*/
char* LogicalNotOperator::resolve(RegisterStack* rs)
{
  //  STUB STUB STUB  (TODO: IMPLEMENT THIS!!!)
  char* top = get_reg(rs->top(), 32);
  char* str = (char*) malloc(50);
  unsigned long long mangle = get_mangle();

  sprintf (str, "  cmp   %s, #1", top);
  manager->context->addInstruction(str);
  sprintf (str, "  blt  true_%llu", mangle);
  manager->context->addInstruction(str);
  sprintf (str, "  mov %s, #0", top);
  manager->context->addInstruction(str);
  sprintf (str, "  b  finish_%llu", mangle);
  manager->context->addInstruction(str);
  sprintf (str, "  true_%llu:", mangle);
  manager->context->addInstruction(str);
  sprintf (str, "  mov %s, #1", top);
  manager->context->addInstruction(str);
  sprintf (str, "  finish_%llu:", mangle);
  manager->context->addInstruction(str);

  free(top);

  l.log('D', "Operators", "Resolved 'Boolean NOT' Operation");

  //  TODO:  Replace w/ ErrorCode
  return strdup(string("").c_str());
}

char* LogicalANDOperator::resolve(RegisterStack* rs)
{
  char* top = get_reg(rs->top(), 32);
  char* sec = get_reg(rs->sec(), 32);
  char* str = (char*) malloc(50);
  unsigned long long mangle = get_mangle();

  sprintf (str, "  cmp   %s, #1", sec);
  manager->context->addInstruction(str);
  sprintf (str, "  blt  false_%llu", mangle);
  manager->context->addInstruction(str);
  sprintf (str, "  cmp   %s, #1", top);
  manager->context->addInstruction(str);
  sprintf (str, "  blt  false_%llu", mangle);
  manager->context->addInstruction(str);
  sprintf (str, "  mov %s, #1", sec);
  manager->context->addInstruction(str);
  sprintf (str, "  b  finish_%llu", mangle);
  manager->context->addInstruction(str);
  sprintf (str, "  false_%llu:", mangle);
  manager->context->addInstruction(str);
  sprintf (str, "  mov %s, #0", sec);
  manager->context->addInstruction(str);
  sprintf (str, "  finish_%llu:", mangle);
  manager->context->addInstruction(str);

  rs->pop();
  free(top);
  free(sec);

  l.log('D', "Operators", "Resolved 'Boolean AND' Operation");

  //  TODO:  Replace w/ ErrorCode
  return strdup(string("").c_str());
}

char* LogicalOROperator::resolve(RegisterStack* rs)
{
  //  STUB STUB STUB  (TODO: IMPLEMENT THIS!!!)
  char* top = get_reg(rs->top(), 32);
  char* sec = get_reg(rs->sec(), 32);
  char* str = (char*) malloc(50);
  unsigned long long mangle = get_mangle();

  sprintf (str, "  cmp   %s, #0", sec);
  manager->context->addInstruction(str);
  sprintf (str, "  bgt  true_%llu", mangle);
  manager->context->addInstruction(str);
  sprintf (str, "  cmp   %s, #0", top);
  manager->context->addInstruction(str);
  sprintf (str, "  bgt  true_%llu", mangle);
  manager->context->addInstruction(str);
  sprintf (str, "  mov %s, #0", sec);
  manager->context->addInstruction(str);
  sprintf (str, "  b  finish_%llu", mangle);
  manager->context->addInstruction(str);
  sprintf (str, "  true_%llu:", mangle);
  manager->context->addInstruction(str);
  sprintf (str, "  mov %s, #1", sec);
  manager->context->addInstruction(str);
  sprintf (str, "  finish_%llu:", mangle);
  manager->context->addInstruction(str);

  rs->pop();
  free(top);
  free(sec);

  l.log('D', "Operators", "Resolved 'Boolean AND' Operation");

  //  TODO:  Replace w/ ErrorCode
  return strdup(string("").c_str());
}


/*
    ARITHMETIC COMPARISON OPERATORS
*/

/*
  LESS THAN
*/
char* LessThanOperator::resolve(RegisterStack* rs)
{
  //  STUB STUB STUB  (TODO: IMPLEMENT THIS!!!)
  char* top = get_reg(rs->top(), 32);
  char* sec = get_reg(rs->sec(), 32);
  char* str = (char*) malloc(50);
  unsigned long long mangle = get_mangle();

  sprintf (str, "  cmp   %s, %s", sec, top);
  manager->context->addInstruction(str);
  sprintf (str, "  blt  true_%llu", mangle);
  manager->context->addInstruction(str);
  sprintf (str, "  mov %s, #0", sec);
  manager->context->addInstruction(str);
  sprintf (str, "  b  finish_%llu", mangle);
  manager->context->addInstruction(str);
  sprintf (str, "  true_%llu:", mangle);
  manager->context->addInstruction(str);
  sprintf (str, "  mov %s, #1", sec);
  manager->context->addInstruction(str);
  sprintf (str, "  finish_%llu:", mangle);
  manager->context->addInstruction(str);

  rs->pop();
  free(top);
  free(sec);

  l.log('D', "Operators", "Resolved 'Less Than' Operation");

  //  TODO:  Replace w/ ErrorCode
  return strdup(string("").c_str());
}

char* LessThanOrEqOperator::resolve(RegisterStack* rs)
{
  //  STUB STUB STUB  (TODO: IMPLEMENT THIS!!!)
  char* top = get_reg(rs->top(), 32);
  char* sec = get_reg(rs->sec(), 32);
  unsigned long long mangle = get_mangle();

  //  STUB:  Needs to be rebuilt using previous implementation.
  char* str = (char*) malloc(50);

  sprintf (str, "  cmp   %s, %s", sec, top);
  manager->context->addInstruction(str);
  sprintf (str, "  bgt  false_%llu", mangle);
  manager->context->addInstruction(str);
  sprintf (str, "  mov %s, #1", sec);
  manager->context->addInstruction(str);
  sprintf (str, "  b  finish_%llu", mangle);
  manager->context->addInstruction(str);
  sprintf (str, "  false_%llu:", mangle);
  manager->context->addInstruction(str);
  sprintf (str, "  mov %s, #0", sec);
  manager->context->addInstruction(str);
  sprintf (str, "  finish_%llu:", mangle);
  manager->context->addInstruction(str);

  rs->pop();
  l.log('D', "Operators", "Resolved 'Less Than or Equal To' Operation");

  free(top);
  free(sec);

  //  TODO:  Replace w/ ErrorCode
  return strdup(string("").c_str());
}

/*
  GREATER THAN
*/
char* GreaterThanOperator::resolve(RegisterStack* rs)
{
  //  STUB STUB STUB  (TODO: IMPLEMENT THIS!!!)
  char* top = get_reg(rs->top(), 32);
  char* sec = get_reg(rs->sec(), 32);
  char* str = (char*) malloc(50);
  unsigned long long mangle = get_mangle();

  sprintf (str, "  cmp   %s, %s", sec, top);
  manager->context->addInstruction(str);
  sprintf (str, "  bgt  true_%llu", mangle);
  manager->context->addInstruction(str);
  sprintf (str, "  mov %s, #0", sec);
  manager->context->addInstruction(str);
  sprintf (str, "  b  finish_%llu", mangle);
  manager->context->addInstruction(str);
  sprintf (str, "  true_%llu:", mangle);
  manager->context->addInstruction(str);
  sprintf (str, "  mov %s, #1", sec);
  manager->context->addInstruction(str);
  sprintf (str, "  finish_%llu:", mangle);
  manager->context->addInstruction(str);

  rs->pop();
  free(top);
  free(sec);

  l.log('D', "Operators", "Resolved 'Less Than' Operation");

  //  TODO:  Replace w/ ErrorCode
  return strdup(string("").c_str());
}

char* GreaterThanOrEqOperator::resolve(RegisterStack* rs)
{
  //  STUB STUB STUB  (TODO: IMPLEMENT THIS!!!)
  char* top = get_reg(rs->top(), 32);
  char* sec = get_reg(rs->sec(), 32);
  unsigned long long mangle = get_mangle();

  //  STUB:  Needs to be rebuilt using previous implementation.
  char* str = (char*) malloc(50);

  sprintf (str, "  cmp   %s, %s", sec, top);
  manager->context->addInstruction(str);
  sprintf (str, "  blt  false_%llu", mangle);
  manager->context->addInstruction(str);
  sprintf (str, "  mov %s, #1", sec);
  manager->context->addInstruction(str);
  sprintf (str, "  b  finish_%llu", mangle);
  manager->context->addInstruction(str);
  sprintf (str, "  false_%llu:", mangle);
  manager->context->addInstruction(str);
  sprintf (str, "  mov %s, #0", sec);
  manager->context->addInstruction(str);
  sprintf (str, "  finish_%llu:", mangle);
  manager->context->addInstruction(str);

  rs->pop();
  l.log('D', "Operators", "Resolved 'Less Than or Equal To' Operation");

  free(top);
  free(sec);

  //  TODO:  Replace w/ ErrorCode
  return strdup(string("").c_str());
}

/*
  EQUAL TO
*/
char* EqualToOperator::resolve(RegisterStack* rs)
{
  //  STUB STUB STUB  (TODO: IMPLEMENT THIS!!!)
  char* top = get_reg(rs->top(), 32);
  char* sec = get_reg(rs->sec(), 32);
  char* str = (char*) malloc(50);
  unsigned long long mangle = get_mangle();

  sprintf (str, "  cmp   %s, %s", sec, top);
  manager->context->addInstruction(str);
  sprintf (str, "  beq  true_%llu", mangle);
  manager->context->addInstruction(str);
  sprintf (str, "  mov %s, #0", sec);
  manager->context->addInstruction(str);
  sprintf (str, "  b  finish_%llu", mangle);
  manager->context->addInstruction(str);
  sprintf (str, "  true_%llu:", mangle);
  manager->context->addInstruction(str);
  sprintf (str, "  mov %s, #1", sec);
  manager->context->addInstruction(str);

  rs->pop();
  free(top);
  free(sec);

  l.log('D', "Operators", "Resolved 'Less Than' Operation");

  //  TODO:  Replace w/ ErrorCode
  return strdup(string("").c_str());
}

char* NotEqualOperator::resolve(RegisterStack* rs)
{
  //  STUB STUB STUB  (TODO: IMPLEMENT THIS!!!)
  char* top = get_reg(rs->top(), 32);
  char* sec = get_reg(rs->sec(), 32);
  unsigned long long mangle = get_mangle();

  //  STUB:  Needs to be rebuilt using previous implementation.
  char* str = (char*) malloc(50);

  sprintf (str, "  cmp   %s, %s", sec, top);
  manager->context->addInstruction(str);
  sprintf (str, "  beq  false_%llu", mangle);
  manager->context->addInstruction(str);
  sprintf (str, "  mov   %s, #1", sec);
  manager->context->addInstruction(str);
  sprintf (str, "  b  finish_%llu", mangle);
  manager->context->addInstruction(str);
  sprintf (str, "  false_%llu:", mangle);
  manager->context->addInstruction(str);
  sprintf (str, "  mov %s, #0", sec);
  manager->context->addInstruction(str);
  sprintf (str, "  finish_%llu:", mangle);
  manager->context->addInstruction(str);

  rs->pop();
  l.log('D', "Operators", "Resolved 'Less Than or Equal To' Operation");

  free(top);
  free(sec);

  //  TODO:  Replace w/ ErrorCode
  return strdup(string("").c_str());
}
