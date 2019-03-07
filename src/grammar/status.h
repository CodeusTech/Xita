/*
  status.h
  Cody Fagley
  Authored on   March 7, 2019
  Last Modified March 7, 2019
*/

/*
  Contains Status Codes for XCSL Grammar Parser

  Table of Contents
  =================
  1.) Standard Operation
  2.) Datatype Errors
  3.) Functional Errors
*/

#ifndef GRAMMAR_STATUS_H
#define GRAMMAR_STATUS_H


/*
  1.) Standard Operation
*/
#define GRAMMAR_RUNNING             0 // Running Successfully

/*
  2.) Datatype Errors
*/
#define GRAMMAR_ERROR_TYPECHECK   100 // Type Check Error
#define GRAMMAR_ERROR_TYPEUNDEF   101 // Undefined Type Error

/*
  3.) Functional Errors
*/
#define GRAMMAR_ERROR_EXPUNDEF    200 // Undefined Expression Error


#endif
