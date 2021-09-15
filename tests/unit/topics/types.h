/*
  types.h (Unit Test)
  Codeus Tech
  Authored on   August 27, 2021
  Last Modified August 30, 2021
*/

/*
  Contains Unit-Testing scenarios for ensuring Types System stays robust and deliberate
*/

#pragma once

#include "../UnitTest.h"

class UT_TypesSystem
  : XitaUnitTester
{

  bool shouldAcceptCorrectlyFormedTypeDeclarations(void)
  {
    TestWithNewContext

    //  Produce Random Identifier and Declare Type
    GivenSomeIdentifier(ident)
    GivenSomeConstructor(construct)
    GivenSomeIdentifier(element)

    expect (context.declareType( ident ))
      to_succeed

    expect (context.declareTypeConstructor(construct))
      to_succeed

    expect (context.declareTypeElement( element, TYPE_INTEGER ))
      to_succeed

    /*
      NOTE!!!
      TODO:
        The other Xita Identifier systems (e.g. Functions, Constants)
        free the identifier memory upon `context.declare*()` call.
        Type/Constructor Declarations should be consistent and do the same.
    */
    free(ident);
    free(construct);


    SUCCESSFUL_ACCEPT
  }

  bool shouldAcceptTypesWithNullSize(void)
  {
    TestWithNewContext

    GivenSomeIdentifier(ident)

    expect(context.declareType( ident, 0 ))
      to_succeed

    free(ident);

    SUCCESSFUL_ACCEPT
  }

  bool shouldRejectTypesWithDuplicateIdentifiers(void)
  {
    TestWithNewContext

    //  Produce Random Identifier and Declare Type
    GivenSomeIdentifier(ident)
    
    expect (context.declareType( ident, 0 ))
      to_succeed
    
    //  Declare another type with the same identifier
    expect (context.declareType( ident, 0 ))
      to_be (ERR_TYPE_ALREADY_DECL)

    free(ident);

    SUCCESSFUL_REJECT
  }

  bool shouldRejectRecordsWithUndefinedType(void)
  {
    TestWithNewContext

    //  Produce Random Identifier and Declare Type
    GivenSomeIdentifier(ident)
    GivenSomeConstructor(construct)
    GivenSomeIdentifier(element)

    expect (context.declareType( ident ))
      to_succeed

    expect (context.declareTypeConstructor(construct))
      to_succeed

    expect (context.declareTypeElement( element, random()+17 ))
      to_be (ERR_TYPE_UNDEFINED)

    free(ident);
    free(construct);

    SUCCESSFUL_REJECT
  }


public:
  UT_TypesSystem () { }

  this_describes (types)
        it shouldAcceptCorrectlyFormedTypeDeclarations()
    and_it shouldAcceptTypesWithNullSize()

    but_it shouldRejectTypesWithDuplicateIdentifiers()
    _and_it shouldRejectRecordsWithUndefinedType()
  _____



};

