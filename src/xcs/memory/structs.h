/*
  structs.h
  Codeus Tech
  Authored on   December 13, 2019
  Last Modified December 13, 2019
*/

/*
  Contains structures related to Memory Use
*/

#ifndef MEMORY_STRUCTS_H
#define MEMORY_STRUCTS_H

//  Linux Libraries
#include <string.h>
#include <stdlib.h>

//  XCS Libraries
#include <xcs/std/typedefs.h>

extern void yyerror(const char* error);


/*
  MemoryVariableNode
    * Used for holding temporary structures created from a memory address
    * Has an identifier and a containing ADR
*/
class MemoryVariableNode
{
  Identifier identifier;
  ADR reg; 
  MemoryVariableNode* left;
  MemoryVariableNode* right;
  MemoryVariableNode* parent = NULL;

  ErrorCode destroy_tree(MemoryVariableNode *leaf)
  {
    if (leaf != NULL)
    {
      destroy_tree(leaf->left);
      destroy_tree(leaf->right);
      delete leaf;
    }

    //  Return Success
    return 0;
  }

public:
//  CONSTRUCTORS
  MemoryVariableNode(Identifier ident, ADR adr, MemoryVariableNode* parent) 
  {
    identifier = strdup(ident);
    reg = adr;

    free(ident);
  }
  ~MemoryVariableNode()
  {
    destroy_tree(this);
  }

  Identifier get_identifier() { return identifier; }
  ADR get_register() { return reg; }

  ErrorCode add_variable(Identifier ident, ADR adr)
  {

    if (strcmp(ident, identifier) < 0)
      if ( left == NULL )
        left = new MemoryVariableNode(ident, adr, this); 
      else left->add_variable(ident, adr);
    else if (strcmp(ident, identifier) > 0)
      if ( right == NULL )
        right = new MemoryVariableNode(ident, adr, this);
      else right->add_variable(ident, adr);
    else
      yyerror("Memory Variable already defined with identifier");

    //  return Success
    return 0;
  }

  ErrorCode insert(MemoryVariableNode* node)
  {
    if (strcmp(node->get_identifier(), identifier) < 0)
      if ( left == NULL )
        left = node;
      else 
        return left->insert(node);
    else if (strcmp(node->get_identifier(), identifier) > 0)
      if ( right == NULL )
        right = node;
      else 
        return right->insert(node);
    else
      yyerror("Memory Variable already defined with identifier");

    //  Return Success
    return 0;
  }

  MemoryVariableNode* find(Identifier ident)
  {
    if (strcmp(ident, identifier) < 0)
      if ( left == NULL )
        return 0;
      else 
        return left->find(ident);
    else if (strcmp(ident, identifier) > 0)
      if (right == NULL )
        return 0;
      else 
        return right->find(ident);
    else
      return this;
  }


};


#endif
