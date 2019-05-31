#ifndef _TREE_H_
#define _TREE_H_
#include <stdbool.h>

struct treenode;
struct tree;
struct elementtype;
typedef struct treenode TreeNode;
typedef struct tree *Tree;
typedef struct elementtype ElementType;
typedef TreeNode *PtrToNode;

struct elementtype {
  char Item[11];
};

struct treenode {
  ElementType Element;
  PtrToNode Left;
  PtrToNode Right;
};

struct tree {
  PtrToNode Root;
  int Size;
};

Tree Make_Tree();

void Tree_Initialize(Tree);

bool Tree_Empty(const Tree);

int Tree_Size(const Tree);

PtrToNode Tree_Find(const ElementType, const Tree);

PtrToNode Tree_Find_Min(const Tree);

PtrToNode Tree_Find_Max(const Tree);

PtrToNode Tree_Insert(const ElementType, Tree);

PtrToNode Tree_Delete(const ElementType, Tree);

void Tree_Clear(Tree);

void Tree_Traverse(const Tree, void (*f)(ElementType));

#endif  // !_TREE_H_
