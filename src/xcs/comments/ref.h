/*
  ref.h
  Cody Fagley
  Authored on   March 5, 2019
  Last Modified March 5, 2019
*/

/*
  Contains Structures/Operations for Reference Comments

  Table of Contents
  =================
  1.) Declare Reference
  2.) Reference Guide
*/

#ifndef COMMENTS_REF_H
#define COMMENTS_REF_H


/* 1) Declare Referece

  Returns:
    0, if Successful
*/
int decl_ref_comment(char* ref)
{
  printf("Reference Guide Declared.\n");

  //  Sanity Check
  //printf("%s\n", ref);

  //  Prevent Memory Leak
  free(ref);

  return 0;
}


/* 2.) Reference Guide

  Returns:
    0, if Successful
*/
int exp_ref_comment()
{
  printf("Reference Guide Invoked.\n");

  return 0;
}


#endif
