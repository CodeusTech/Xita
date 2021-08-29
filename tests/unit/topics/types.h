/*
  types.h (Unit Test)
  Codeus Tech
  Authored on   August 27, 2021
  Last Modified August 27, 2021
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

    SUCCESSFUL_ACCEPT
  }

  bool shouldAcceptTypesWithNullSize(void)
  {
    TestWithNewContext

    test(context.declareType( generate_random_identifier(MAX_IDENTIFIER_SIZE), 0 ))
      expect(SUCCESS)

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

