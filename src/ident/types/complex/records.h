/*
  records.h
  Cody Fagley
  Authored on   February 21, 2019
  Last Modified February 21, 2019
*/

/*
  Contains Structures/Operations for handling Type Records

  Table of Contents
  =================
  1.) Records
    1.a) Start Record
    1.b) End Record
    1.c) Get Size
  2.) Elements
    2.a) Declare Element
*/

#ifndef TYPES_RECORDS_H
#define TYPES_RECORDS_H

/*
  1.) Records
*/

/* 1.a) Start Record

  Returns:
    0, if Successful
*/
ErrorCode start_record()
{
  "Started new record...\n";

  return 0;
}

/* 1.b) End Record

  Returns:
    0, if Successful
*/
ErrorCode end_record()
{
  "Ended Record\n";

  return 0;
}

/* 1.c) Get Record Size

  Returns:
    0, if UNSUCCESSFUL
    s, if Successful, where 's' is size of current record
*/
unsigned long elem_get_size(Identifier ident)
{
  //  STUB STUB STUB

  /*
    TODO:
     * Error Check
     * Search buffers for ident
     * Return Element size
  */

  //  Return Unsuccessful
  return 0;
}


/*
  2.) Elements
*/

/* 2.a) Declare Element

  Returns:
    0, if Successful
*/
ErrorCode decl_element(Identifier ident)
{
  //  STUB STUB STUB
  printf("Element Declared: %s\n", ident);

  /*
    TODO:
     * Error Check
     * Add Element Identifier to Buffers
     * Add Element Datasize to Buffers
      + Last encountered type at this point
  */

  //  Return Success
  return 0;
}


#endif

