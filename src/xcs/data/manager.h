/*
  manager.h (Data Manager)
  Codeus Tech
  Authored on   May 27, 2020
  Last Modified May 27, 2020
*/

/*
  The DATA MANAGER statically tracks data values as they pass through the compiler backend
*/

#pragma once

#include <vector>

#include "instance.h"

using namespace std;

/*

*/
class DataManager
{
  /*
    Private (Inaccessible) Data
  */
  vector<DataInstance> data;

public:

  ErrorCode newData(TypeID tid, Arbitrary value);
  ErrorCode addData(TypeID tid, Arbitrary value);

  DataInstance getData() { return data.back(); }
  DataInstance getData(Index i) { return data[data.size()-i-1]; }

};

#include "manager.cpp"
