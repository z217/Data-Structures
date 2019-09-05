#ifndef _AVLTREE_H_
#define _AVLTREE_H_
#include <stdbool.h>

#define ELEMENTSIZE 10

struct avlnode;
struct avltree;
struct elementtype;
typedef struct avlnode AvlNode;
typedef AvlNode *PtrToNode;
typedef struct avltree *AvlTree;
typedef struct elementtype ElementType;

struct elementtype {
  char Item[ELEMENTSIZE + 1];
};

struct avlnode {
  ElementType Element;
  PtrToNode Left;
  PtrToNode Right;
  int Height;
};

struct avltree {
  PtrToNode Root;
  int Size;
};

AvlTree Make_AvlTree();

void AvlTree_Initialize(AvlTree);

bool AvlTree_Empty(const AvlTree);

int AvlTree_Size(const AvlTree);

PtrToNode AvlTree_Find(const ElementType, const AvlTree);

PtrToNode AvlTree_Find_Min(const AvlTree);

PtrToNode AvlTree_Find_Max(const AvlTree);

PtrToNode AvlTree_Insert(const ElementType, AvlTree);

PtrToNode AvlTree_Delete(const ElementType, AvlTree);

void AvlTree_Clear(AvlTree);

void AvlTree_Traverse(AvlTree, void (*f)(ElementType));

#endif  // !_AVLTREE_H_
