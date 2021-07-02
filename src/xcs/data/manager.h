/*
  manager.h (Data Manager)
  Codeus Tech
  Authored on   May 27, 2020
  Last Modified May 27, 2020
*/

/*
  DataManager statically tracks data values as they pass through the compiler

  There are times when data is needed much later than when it was defined,
  and needs to be known at compile-time.  For this reason, we track data 
  as possible using a simple stack structure. 

  This is particularly important when a constant value is defined with
  several mathematical operations.  The compiler ensures the data ACTUALLY
  is constant by computing it statically and holding the computed value.
*/

#pragma once

#include <vector>

#include "instance.h"

class ContextManager;

using namespace std;

/*

*/
class DataManager
{
  /*
    Private (Inaccessible) Data
  */
  vector<DataInstance> data;
  ContextManager* _context;

public:
  DataManager(ContextManager* context) { _context = context; }

  ErrorCode newData(TypeID tid, Arbitrary value);
  ErrorCode addData(TypeID tid, Arbitrary value);
  ErrorCode addData(Identifier ident);

  DataInstance getData() { return data.back(); }
  DataInstance getData(Index i) { return data[data.size()-i-1]; }

};

