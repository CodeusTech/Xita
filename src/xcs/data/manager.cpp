/*
  manager.cpp (Data Manager)
  Codeus Tech
  Authored on   May 27, 2020
  Last Modified May 27, 2020
*/

/*
  Contains functional implementions for managing data/value transfer in backend
*/

#include "manager.h"

#include "../context/manager.h"


/*
  Refresh Data Manager's value stack
*/
ErrorCode DataManager::newData(TypeID tid, Arbitrary value)
{
  data.clear();
  data.push_back(DataInstance(tid, value));

  return SUCCESS;
}

/*
  Add the last two data elements on the stack, if possible
*/
ErrorCode DataManager::addData(TypeID tid, Arbitrary value)
{
  if (data.back().tid == TYPE_ARBITRARY)
  {
    data.back().tid = tid;

    /*
      TODO: Handle Arbitrary Type Situations
    */
    data.back().value = value;

    return SUCCESS;
  }

  switch (data.back().tid)
  {
    //  General Integer
    case TYPE_INTEGER:
      if (tid > TYPE_INTEGER && tid < TYPE_U8)
        data.back().tid = tid;
    //  Signed 8-Bit Integer
    case TYPE_I8:
      if (tid > TYPE_I8 && tid < TYPE_U8)
        data.back().tid = tid;
    //  Signed 16-Bit Integer
    case TYPE_I16:
      if (tid > TYPE_I16 && tid < TYPE_U8)
        data.back().tid = tid;
    //  Signed 32-Bit Integer
    case TYPE_I32:
      if (tid > TYPE_I32 && tid < TYPE_U8)
        data.back().tid = tid;
    //  Signed 64-Bit Integer
    case TYPE_I64:
      if (tid >= TYPE_ARBITRARY && tid < TYPE_U8)
        data.back().value = (Arbitrary) ((long long) data.back().value + (long long) value);
      break;
    //  Unsigned 8-Bit Integer
    case TYPE_U8:
      if (tid > TYPE_U8 && tid < TYPE_REAL)
        data.back().tid = tid;
    //  Unsigned 16-Bit Integer
    case TYPE_U16:
      if (tid > TYPE_U16 && tid < TYPE_REAL)
        data.back().tid = tid;
    //  Unsigned 32-Bit Integer
    case TYPE_U32:
      if (tid > TYPE_U32 && tid < TYPE_REAL)
        data.back().tid = tid;
    //  Unsigned 64-Bit Integer
    case TYPE_U64:
      if (tid == TYPE_ARBITRARY || tid == TYPE_INTEGER ||
          (tid >= TYPE_U8 && tid < TYPE_REAL ))
        data.back().value = (Arbitrary) ((unsigned long long) data.back().value + (unsigned long long) value);
      break;
    //  Strings
    case TYPE_STRING:
      data.back().tid = tid;
      strcat((char*)data.back().value, (char*)value);
      //  TODO:
      // data.back().value = ???
    default:
      break;
  }

  return SUCCESS;
}

ErrorCode DataManager::addData(Identifier ident)
{
  /*
    TODO:  Need to Error and Type Check
  */
  ConstantNode* cn = _context->resolveConstantNode(ident);

  return addData(cn->Type(), cn->Value());
}


