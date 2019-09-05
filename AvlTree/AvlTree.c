#include "AvlTree.h"
#include <stdbool.h>
#include <stdlib.h>
#include <string.h>

#define MAX(X, Y) ((X) > (Y) ? (X) : (Y))

static int Height(const PtrToNode);
static PtrToNode Find(const ElementType, PtrToNode);
static PtrToNode Insert(const ElementType, PtrToNode, AvlTree);
static PtrToNode SingleRotateWithLeft(PtrToNode);
static PtrToNode SingleRotateWithRight(PtrToNode);
static PtrToNode DoubleRotateWithLeft(PtrToNode);
static PtrToNode DoubleRotateWithRight(PtrToNode);
static PtrToNode Delete(const ElementType, PtrToNode, AvlTree);
static void Clear(PtrToNode);
static void Traverse(PtrToNode, void (*f)(ElementType));

AvlTree Make_AvlTree() {
  AvlTree T = (AvlTree)malloc(sizeof(struct avltree));
  T->Size = 0;
  T->Root = NULL;
  return T;
}

void AvlTree_Initialize(AvlTree T) {
  T->Root = NULL;
  T->Size = 0;
}

bool Avltree_Empty(const AvlTree T) { return T->Root; }

int AvlTree_Size(const AvlTree T) { return T->Size; }

PtrToNode AvlTree_Find(const ElementType X, const AvlTree T) {
  return Find(X, T->Root);
}

PtrToNode AvlTree_Find_Min(const AvlTree T) {
  PtrToNode P = T->Root;
  if (!P) return NULL;
  while (P->Left) P = P->Left;
  return P;
}

PtrToNode AvlTree_Find_Max(const AvlTree T) {
  PtrToNode P = T->Root;
  if (!P) return NULL;
  while (P->Right) P = P->Right;
  return P;
}

PtrToNode AvlTree_Insert(const ElementType X, AvlTree T) {
  return T->Root = Insert(X, T->Root, T);
}

PtrToNode AvlTree_Delete(const ElementType X, AvlTree T) {
  return T->Root = Delete(X, T->Root, T);
}

void AvlTree_Clear(AvlTree T) {
  Clear(T->Root);
  T->Size = 0;
  T->Root = NULL;
}

void AvlTree_Traverse(AvlTree T, void (*f)(ElementType)) {
  Traverse(T->Root, f);
}

static int Height(const PtrToNode P) {
  if (P)
    return P->Height;
  else
    return -1;
}

static PtrToNode Find(const ElementType X, PtrToNode P) {
  if (!P) return NULL;
  int temp = strcmp(P->Element.Item, X.Item);
  if (temp > 0)
    return Find(X, P->Left);
  else if (temp < 0)
    return Find(X, P->Right);
  else
    return P;
}

static PtrToNode Insert(const ElementType X, PtrToNode P, AvlTree T) {
  if (!P) {
    P = (PtrToNode)malloc(sizeof(AvlNode));
    if (!P) return NULL;
    strcpy_s(P->Element.Item, sizeof(char) * ELEMENTSIZE, X.Item);
    P->Left = P->Right = NULL;
    P->Height = 0;
    ++T->Size;
  } else {
    int temp = strcmp(P->Element.Item, X.Item);
    if (temp > 0) {
      P->Left = Insert(X, P->Left, T);
      if (Height(P->Left) - Height(P->Right) == 2) {
        if (strcmp(P->Left->Element.Item, X.Item) > 0)
          P = SingleRotateWithLeft(P);
        else
          P = DoubleRotateWithLeft(P);
      }
    } else if (temp < 0) {
      P->Right = Insert(X, P->Right, T);
      if (Height(P->Right) - Height(P->Right) == 2) {
        if (strcmp(P->Right->Element.Item, X.Item) < 0)
          P = SingleRotateWithRight(P);
        else
          P = DoubleRotateWithRight(P);
      }
    }
  }
  P->Height = MAX(Height(P->Left), Height(P->Right)) + 1;
  return P;
}

static PtrToNode SingleRotateWithLeft(PtrToNode P) {
  PtrToNode P_ = P->Left;
  P->Left = P_->Right;
  P_->Right = P;
  P_->Height = MAX(Height(P_->Left), Height(P_->Right)) + 1;
  P->Height = MAX(Height(P->Left), Height(P->Right)) + 1;
  return P_;
}

static PtrToNode SingleRotateWithRight(PtrToNode P) {
  PtrToNode P_ = P->Right;
  P->Right = P_->Left;
  P->Left = P;
  P_->Height = MAX(Height(P_->Left), Height(P_->Right)) + 1;
  P->Height = MAX(Height(P->Left), Height(P->Right)) + 1;
  return P_;
}

static PtrToNode DoubleRotateWithLeft(PtrToNode P) {
  P->Left = SingleRotateWithRight(P->Left);
  return SingleRotateWithLeft(P);
}

static PtrToNode DoubleRotateWithRight(PtrToNode P) {
  P->Right = SingleRotateWithLeft(P->Right);
  return SingleRotateWithRight(P);
}

static PtrToNode Delete(const ElementType X, PtrToNode P, AvlTree T) {
  if (!P) return NULL;
  int temp = strcmp(P->Element.Item, X.Item);
  if (temp > 0) {
    P->Left = Delete(X, P->Left, T);
    if (Height(P->Right) - Height(P->Left) == 2)
      if (P->Right->Right)
        P = SingleRotateWithRight(P);
      else
        P = DoubleRotateWithRight(P);
  } else if (temp < 0) {
    P->Right = Delete(X, P->Right, T);
    if (Height(P->Left) - Height(P->Right) == 2)
      if (P->Left->Left)
        P = SingleRotateWithLeft(P);
      else
        P = DoubleRotateWithLeft(P);
  } else if (P->Left && P->Right) {
    PtrToNode P_ = P->Right;
    while (P_->Left) P_ = P_->Left;
    strcpy_s(P->Element.Item, sizeof(char) * ELEMENTSIZE, P_->Element.Item);
    P->Right = Delete(P->Element, P->Right, T);
  } else {
    PtrToNode P_ = P;
    if (P->Left)
      P = P->Left;
    else if (P->Right)
      P = P->Right;
    free(P_);
    --T->Size;
    if (!T->Size) P = NULL;
  }
  P->Height = MAX(Height(P->Left), Height(P->Right)) + 1;
  return P;
}

static void Clear(PtrToNode P) {
  if (P) {
    Clear(P->Left);
    Clear(P->Right);
    free(P);
  }
}

static void Traverse(PtrToNode P, void (*f)(ElementType)) {
  if (P) {
    Traverse(P->Left, f);
    (*f)(P->Element);
    Traverse(P->Right, f);
  }
}