/*
  anchors.h
  Cody Fagley
  Authored on   March 17, 2019
  Last Modified March 17, 2019
*/

/*
  Contains Functionality for Handling Regular Expression Anchor Patterns

  Table of Contents
  =================
  1.) Anchor Shorthand
    1.a) Start Anchor
    1.b) End Anchor
*/

#ifndef REGEX_ANCHORS_H
#define REGEX_ANCHORS_H


/*
  1.) Anchor Shorthand
*/

/* 1.a) Start Anchor

  Returns:
    0, if Successful
*/
int regex_anchor_start()
{
  char anchor_start = '^';
  //  STUB STUB STUB

  /*
    TODO:
     * Error Check
     * Matches strings that start with ^(exp)
      - where, exp is some regular expression
  */

  return 0;
}

/* 1.b) End Anchor

  Returns:
    0, if Successful
*/
int regex_anchor_end()
{
  const char regex_end   = '$';
  //  STUB STUB STUB

  /*
    TODO:
     * Error Check
     * Matches strings that end with (exp)$
      - where, exp is some regular expression
  */

  return 0;
}


#endif

