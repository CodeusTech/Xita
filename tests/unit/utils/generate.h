/*
  generate.h (Testing Utility)
  Codeus Tech
  Authored on   August 26, 2021
  Last Modified August 29, 2021
*/

/*
  Contains functionality for producing random Xita data (for testing)

  TABLE OF CONTENTS
  =================
  1.) Generate Random Identifier
  2.) Generate Random Constructor
  3.) Interface Functions for Use in Unit Testing
*/

#pragma once

#include <iostream>
#include <ctime>
#include <unistd.h>
#include <stdlib.h>


/*
  This produces a valid random identifier (Xita Compliant)
*/
char* generate_random_identifier(const int len) {
    
    //  TODO:
    //    Right now, this always generates a string of length `len`.
    //    It should be changed to give a random length for identifier returned

    char* tmp_s = (char*) malloc(len+1);
    
    static const char alpha[] =
        "_abcdefghijklmnopqrstuvwxyz";
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

/*
  This produces a valid random constructor (Xita Compliant)
*/
char* generate_random_constructor(const int len) {
    
    //  TODO:
    //    Right now, this always generates a string of length `len`.
    //    It should be changed to give a random length for identifier returned

    char* tmp_s = (char*) malloc(len+1);
    
    static const char alpha[] =
        "ABCDEFGHIJKLMNOPQRSTUVWXYZ";
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

/*
  3.) Interface Functions for Use in Unit Testing
*/
//  Data Generation
#define GivenSomeIdentifier(name) Identifier name = generate_random_identifier(MAX_IDENTIFIER_SIZE);
#define GivenDuplIdentifier(other, name) Identifier name = strndup(other, strlen(other));
#define GivenSomeConstructor(name) Constructor name = generate_random_constructor(MAX_CONSTRUCTOR_SIZE);

