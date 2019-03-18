/*
  alloc.h
  Cody Fagley
  Authored on   March 13, 2019
  Last Modified March 14, 2019
*/

/*
  Contains Operations for XCS Internal Memory Allocator

  Table of Contents
  =================
  1.) Structures
    1.a) Memory Block
    1.b) Active Memory Tree
    1.c) Get Left Memory Branch
    1.d) Get Right Memory Branch
    1.e) Get Branch Height
    1.f) Get Address
    1.g) Get Data Size
    1.h) Get Data Payload
  2.) Miscellaneous Utilities
    2.a) Find Max
  3.) AVL Operations
    3.a) New Memory Block
    3.b) Rotate Right
    3.c) Rotate Left
  4.) Memory Allocation
    4.a) Check if Allocated
    4.b) Allocate Memory
    4.c) Free Memory
*/

#ifndef MEMORY_ALLOC_H
#define MEMORY_ALLOC_H



/*
  1.) Structures
*/

/*
  1.a) Memory Block
*/

typedef struct mem_block
{
  struct mem_block* left;
  struct mem_block* right;
  unsigned int height;
  unsigned long addr;
  unsigned long size;
  void* data;
} MemoryBlock;

//  1.b) Active Memory Tree
extern MemoryBlock* ActiveMemory;

/* 1.c) Get Left Memory Branch

  Returns:
    Left Memory Branch
*/
MemoryBlock* mem_left(MemoryBlock* node)
{
  if (node == NULL) return NULL;
  else              return node->left;
}

/* 1.d) Get Right Memory Branch

  Returns:
    Left Memory Branch
*/
MemoryBlock* mem_right(MemoryBlock* node)
{
  if (node == NULL) return NULL;
  else              return node->right;
}

/* 1.e) Get Branch Height

  Returns:
    Height of Branch
*/
unsigned int mem_height(MemoryBlock* node)
{
  if (node == NULL) return 0;
  else              return node->height;
}

/* 1.f) Get Address

  Returns:
    Starting Address for Active Memory Block
*/
unsigned long mem_addr(MemoryBlock* node)
{
  if (node == NULL) return 0;
  else              return node->addr;
}

/* 1.g) Get Data Size

  Returns:
    Size of Data Element (in Bytes)
*/
unsigned long mem_size(MemoryBlock* node)
{
  if (node == NULL) return 0;
  else              return node->size;
}

/* 1.h) Get Data Payload

*/
void* mem_data(MemoryBlock* node)
{
  if (node == NULL) return NULL;
  else              return node->data;
}


/*
  2.) Misc. Utilities
*/

/* 2.a) Find Max

  Returns:
    The larger of the two integers
*/
unsigned long max(unsigned long a, unsigned long b) { return (a > b)? a : b; } 


/*
  3.) AVL Operations
*/

/* 3.a) New Memory Block

  Returns: 
    Pointer to new Memory Block Node
*/

MemoryBlock* mem_new(unsigned long size, void* data)
{
  //  Allocate Memory
  MemoryBlock* mem = (MemoryBlock*) malloc (sizeof(MemoryBlock));

  //  Set Initial Values
  mem->left = NULL;
  mem->right = NULL;
  mem->height = 1;
  mem->addr = rand(); //  TODO:  Add Safety Checks
  mem->size = size;

  //  Set Data Pointer (Assumes parameter data has already been allocated)
  mem->data = data;

  return mem;
}

/* 3.b) Rotate Right

  Returns:
    p, where p is a pointer to a tree post-rotation (right)
*/
MemoryBlock* mem_rotate_right(MemoryBlock* mem)
{
  //  Gather Necessary Branches
  MemoryBlock* left = mem_left(mem);
  MemoryBlock* left_prime = mem_right(left);

  //  Perform Rotation Right
  left->right = mem;
  mem->left = left_prime;

  //  Reset Tree Heights
  mem->height = max(mem_height(mem->left), mem_height(mem->right)) + 1;
  left->height = max(mem_height(left->left), mem_height(left->right)) + 1;

  //  Return New Root Node (left)
  return left;
}

/* 3.c) Rotate Left

  Returns:
    p, where p is a pointer to a tree post-rotation (left)
*/
MemoryBlock* mem_rotate_left(MemoryBlock* mem)
{
  //  Gather Necessary Branches
  MemoryBlock* right = mem_right(mem);
  MemoryBlock* right_prime = mem_left(right);

  //  Perform Rotation Left
  right->left = mem;
  mem->right = right_prime;

  //  Resent Tree Heights
  mem->height = max(mem_height(mem->left), mem_height(mem->right)) + 1;
  right->height = max(mem_height(right->left), mem_height(right->right)) + 1;

  return right;
}


/*
  4.) Memory Allocation
*/

/* 4.a) Check if Allocated

  Returns:
    0, if Successful
*/
int xcs_is_alloc()
{
  /*
    TOP  holds memory address, addr
    NEXT holds size s (in bytes)
  */

  //  Error Check

  /*
    Top Register holds:
      0, if Address is Allocated
      addr, 
  */

  return 0;
}

/* 4.b) Allocate Memory

  'xcs_alloc' essentially performs AVL Insert on Active Memory Tree

  Returns:
    0, if Successful
*/
int xcs_alloc()
{
  /*
    TOP holds size (in bytes) to Allocate
  */

  //  Error Check Size

  /*
    Generate Random Number using GPIO
  */
  xcs_is_alloc(); // Check if already allocated


  /*
    End of Call:
      TOP holds Allocated Memory Block
  */

  //  Return Success
  return 0;
}

/* 4.c) Free Memory

  Returns:
    0, if Successful
*/
int xcs_free()
{
  /*
    Top Register Holds an Allocated Memory Address
  */

  //  Error Check

  /*
    End of Call:
      Deallocate TOP and Decrement Register Stack
  */
  return 0;
}


#endif