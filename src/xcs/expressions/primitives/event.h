/*
  event.h
  Codeus Tech
  Authored on   April 22, 2020
  Last Modified April 22, 2020
*/

/*
  Contains structures/implementations for XCS Event primitives


  TABLE OF CONTENTS
  =================
  1.) Initialize Event Primitives
  2.) Push Event Primitive


  NOTE: Putting the cart before the horse on this one.  Will need working Process Scheduler to implement.
        Put here anyways so we can build with it in mind, long-term.
*/

#pragma once

#include <xcs/std/includes.h>
#include <xcs/context/manager.h>


/*
  1.) Initialize Event Primitives
*/

ErrorCode initializeEventPrimitives(ContextManager context)
{
  char* name = (char*) malloc(50);

  sprintf(name, "event"); context.declareType(name, 1);          
  sprintf(name, "Event"); context.declareTypeConstructor(name); 

  return SUCCESS;
}


