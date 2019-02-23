/*
  avl_tree.h
  Cody Fagley
  Authored on   February 21, 2019
  Last Modified February 23, 2019
*/

/*
  Contains Structures/Operations for Self-Balancing AVL Trees

  Table of Contents
  =================
  1.) Structures
    1.a) AVL Node
  2.) Node Operations
    2.a) Get Data
    2.b) Get Height
    2.c) Get Left Tree
    2.d) Get Right Tree
  3.) Tree Operations
    3.a) Insert Node
    3.b) Remove Node
  4.) Find Value in Tree
    4.a) Find Integer Value
    4.b) Find Double Value
    4.c) Find Boolean Value
    4.d) Find Character Value
    4.e) Find String Value
*/

#ifndef ALLOCATOR_AVLTREE_H
#define ALLOCATOR_AVLTREE_H

#include "stdbool.h"

/*
  1.) Structures
*/

/* 1.a) AVL Node

*/
typedef int node;


/*
  2.) Node Operations
*/

/* 2.a) Get Data

  Returns:
    p?, where 'p?' is pointer/data of some type
*/
void* get_data(node tree)
{
  //  STUB STUB STUB

  return 0;
}

/* 2.b) Get Height
 
  Returns:
    0, if node is a leaf
    h, where 'h' is longest distance to leaf
*/
unsigned int get_height(node tree)
{
  // STUB STUB STUB

  return 0;
}

/* 2.c) Get Left Tree

  Returns:
    0, if left tree is a Leaf
    p, where p is a pointer to left tree
*/
node get_left(node tree)
{
  //  STUB STUB STUB

  return tree;
}

/* 2.d) Get Right Tree

  Returns:
    0, if right tree is a Leaf
    p, where p is a pointer to right tree
*/
node get_right(node tree)
{
  //  STUB STUB STUB

  return tree;
}

/*
  3.) Tree Operations
*/

/* 3.a) Insert Node
  
  Returns:
    p, where p is a pointer to tree with inserted node
*/
node avl_insert(node tree, node insert_me)
{
  //  STUB STUB STUB

  return tree;
}

/* 3.b) Remove Node
  Returns:
    0, If Node Successfully Removed (and is now a leaf)
    p, where 'p' is a pointer to tree with removed node
*/
node avl_remove(node tree, node remove_me)
{
  //  STUB STUB STUB

  return tree;
}

/*
  4.) Find Value in Tree
*/

/* 4.a) Find Integer Value

  Returns:
    0, if Value isn't Found
    p, where 'p' is pointer to node with Value
*/
node avl_find_int(node tree, int val )
{
  //  STUB STUB STUB

  return tree;
}

/* 4.b) Find Double Value

  Returns:
    0, if Value isn't Found
    p, where 'p' is pointer to node with Value
*/
node avl_find_double(node tree, double val )
{
  //  STUB STUB STUB

  return tree;
}

/* 4.c) Find Boolean Value

  Returns:
    0, if Value isn't Found
    p, where 'p' is pointer to node with Value
*/
node avl_find_bool(node tree, bool val )
{
  //  STUB STUB STUB

  return tree;
}

/* 4.d) Find Character Value

  Returns:
    0, if Value isn't Found
    p, where 'p' is pointer to node with Value
*/
node avl_find_char(node tree, char val )
{
  //  STUB STUB STUB

  return tree;
}

/* 4.e) Find String Value

  Returns:
    0, if Value isn't Found
    p, where 'p' is pointer to node with Value
*/
node avl_find_str(node tree, char* val )
{
  //  STUB STUB STUB

  return tree;
}



#endif
