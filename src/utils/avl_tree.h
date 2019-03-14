/*
  avl_tree.h
  Cody Fagley
  Authored on   February 21, 2019
  Last Modified February 23, 2019
*/

/*
  Contains Structures/Operations for Self-Balancing AVL Trees


  Reference/Documentation
  =======================
  https://www.geeksforgeeks.org/avl-tree-set-1-insertion/


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
    3.a) New Tree
    3.b) Rotate Right
    3.c) Rotate Left
    3.d) Insert Node
    3.e) Remove Node
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
typedef struct avl_node
{
  struct avl_node* left;
  struct avl_node* right;
  int height;
  unsigned int size;
  void* data;
} Tree;


/*
  2.) Node Operations
*/

/* 2.a) Get Data

  Returns:
    p?, where 'p?' is pointer/data of some type
*/
void* get_data(Tree tree) { return tree.data; };

/* 2.b) Get Height
 
  Returns:
    0, if tree is a leaf
    h, where 'h' is longest distance to leaf
*/
unsigned int get_height(Tree* tree) 
{
  if (tree == NULL) return 0;
  else              return tree->height; 
};

/* 2.c) Get Left Tree

  Returns:
    0, if left tree is a Leaf
    p, where p is a pointer to left tree
*/
Tree* get_left(Tree* tree)
{
  if (tree == NULL) return NULL;
  else              return tree->left;
}

/* 2.d) Get Right Tree

  Returns:
    0, if right tree is a Leaf
    p, where p is a pointer to right tree
*/
Tree* get_right(Tree* tree)
{
  if (tree == NULL) return NULL;
  else              return tree->right;
}


/*
  3.) Tree Operations
*/

/* 3.a) New Tree

  Returns:
    p(s), where p is a pointer to a new tree of size s
*/
Tree* tree_new(unsigned int size, void* data)
{
  //  Allocate Memory
  Tree* tree = (Tree*) malloc (sizeof(Tree));

  //  Set Initial Values
  tree->left = NULL;
  tree->right = NULL;
  tree->height = 1;
  tree->size = size;

  //  Set Data Pointer (Assumes parameter data has already been allocated)
  tree->data = data;

  return tree;
}

/* 3.b) Rotate Right

  Returns:
    p, where p is a pointer to a tree post-rotation (right)
*/
Tree* tree_shr(Tree* tree)
{
  // STUB STUB STUB

  return tree;
}

/* 3.c) Rotate Left

  Returns:
    p, where p is a pointer to a tree post-rotation (left)
*/
Tree* tree_shl(Tree* tree)
{
  // STUB STUB STUB

  return tree;
}

/* 3.d) Insert Node
  
  Returns:
    p, where p is a pointer to tree with inserted node
*/
Tree* tree_insert(Tree* tree, Tree* node)
{
  //  STUB STUB STUB

  return tree;
}

/* 3.e) Remove Node
  Returns:
    0, If Node Successfully Removed (and is now a leaf)
    p, where 'p' is a pointer to tree with removed node
*/
Tree avl_remove(Tree tree, Tree node)
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
    p, where 'p' is pointer to Tree with Value
*/
Tree avl_find_int(Tree tree, int val )
{
  //  STUB STUB STUB

  return tree;
}

/* 4.b) Find Double Value

  Returns:
    0, if Value isn't Found
    p, where 'p' is pointer to Tree with Value
*/
Tree avl_find_double(Tree tree, double val )
{
  //  STUB STUB STUB

  return tree;
}

/* 4.c) Find Boolean Value

  Returns:
    0, if Value isn't Found
    p, where 'p' is pointer to Tree with Value
*/
Tree avl_find_bool(Tree tree, bool val )
{
  //  STUB STUB STUB

  return tree;
}

/* 4.d) Find Character Value

  Returns:
    0, if Value isn't Found
    p, where 'p' is pointer to Tree with Value
*/
Tree avl_find_char(Tree tree, char val )
{
  //  STUB STUB STUB

  return tree;
}

/* 4.e) Find String Value

  Returns:
    0, if Value isn't Found
    p, where 'p' is pointer to Tree with Value
*/
Tree avl_find_str(Tree tree, char* val )
{
  //  STUB STUB STUB

  return tree;
}



#endif
