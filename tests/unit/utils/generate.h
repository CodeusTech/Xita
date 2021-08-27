/*
  generate.h (Testing Utility)
  Codeus Tech
  Authored on   August 26, 2021
  Last Modified August 26, 2021
*/

/*
  Contains functionality for producing random Xita data (for testing)
*/

#pragma once

#include <iostream>
#include <ctime>
#include <unistd.h>
#include <stdlib.h>


char* xtest_random_identifier(const int len) {
    
    //  TODO:
    //    Right now, this always generates a string of length `len`.
    //    It should be changed to give a random length for identifier returned

    char* tmp_s = (char*) malloc(len+1);
    
    static const char alpha[] =
        "ABCDEFGHIJKLMNOPQRSTUVWXYZ"
        "abcdefghijklmnopqrstuvwxyz";
    static const char alphanum[] =
        "0123456789"
        "ABCDEFGHIJKLMNOPQRSTUVWXYZ"
        "abcdefghijklmnopqrstuvwxyz";
    
    srand( (unsigned) time(NULL) * getpid());

    tmp_s[0] = alpha[rand() % (sizeof(alpha) - 1)];

    for (int i = 1; i < (len-1); ++i) 
        tmp_s[i] = alphanum[rand() % (sizeof(alphanum) - 1)];
    
    tmp_s[len-1] = 0;
    return tmp_s;
    
}

