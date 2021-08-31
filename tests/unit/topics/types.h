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
    SomeIdentifier(ident)
    SomeConstructor(construct)
    SomeIdentifier(element)

    test (context.declareType( ident ))
      expect (SUCCESS)

    test (context.declareTypeConstructor(construct))
      expect (SUCCESS)

    test (context.declareTypeElement( element, TYPE_INTEGER ))
      expect (SUCCESS)

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

    SomeIdentifier(ident)

    test(context.declareType( ident, 0 ))
      expect(SUCCESS)

    free(ident);

    SUCCESSFUL_ACCEPT
  }

  bool shouldRejectTypesWithDuplicateIdentifiers(void)
  {
    TestWithNewContext

    //  Produce Random Identifier and Declare Type
    SomeIdentifier(ident)
    
    test (context.declareType( ident, 0 ))
      expect (SUCCESS)
    
    //  Declare another type with the same identifier
    test (context.declareType( ident, 0 ))
      expect (ERR_TYPE_ALREADY_DECL)

    free(ident);

    SUCCESSFUL_REJECT
  }

  bool shouldRejectRecordsWithUndefinedType(void)
  {
    TestWithNewContext

    //  Produce Random Identifier and Declare Type
    SomeIdentifier(ident)
    SomeConstructor(construct)
    SomeIdentifier(element)

    test (context.declareType( ident ))
      expect (SUCCESS)

    test (context.declareTypeConstructor(construct))
      expect (SUCCESS)

    test (context.declareTypeElement( element, random()+17 ))
      expect (ERR_TYPE_UNDEFINED)

    free(ident);
    free(construct);

    SUCCESSFUL_REJECT
  }


public:
  UT_TypesSystem () { }

  void Describe() override
  {
    description = 
      this ->
                shouldAcceptCorrectlyFormedTypeDeclarations()
        and_it  shouldAcceptTypesWithNullSize()

        but_it  shouldRejectTypesWithDuplicateIdentifiers()
        _and_it shouldRejectRecordsWithUndefinedType()
    _____


    ValidateDescription();
  }


};

