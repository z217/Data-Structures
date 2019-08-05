#include "Tree.h"
#include <stdbool.h>
#include <stdlib.h>
#include <string.h>

static PtrToNode Find(const ElementType, const PtrToNode);
static PtrToNode Insert(const ElementType, PtrToNode, Tree);
static PtrToNode Delete(const ElementType, PtrToNode, Tree);
static void Clear(PtrToNode);
static void Traverse(PtrToNode, void (*f)(ElementType));  //ºóÐò±éÀú

Tree Make_Tree() {
  Tree T = (Tree)malloc(sizeof(struct tree));
  T->Root = NULL;
  T->Size = 0;
  return T;
}

void Tree_Initialize(Tree T) {
  T->Root = NULL;
  T->Size = 0;
}

bool Tree_Empty(const Tree T) { return T->Root; }

int Tree_Size(const Tree T) { return T->Size; }

PtrToNode Tree_Find(const ElementType X, const Tree T) {
  if (!T->Root) return NULL;
  return Find(X, T->Root);
}

PtrToNode Tree_Find_Min(const Tree T) {
  PtrToNode P = T->Root;
  if (!P) return NULL;
  while (P->Left) P = P->Left;
  return P;
}

PtrToNode Tree_Find_Max(const Tree T) {
  PtrToNode P = T->Root;
  if (!P) return NULL;
  while (P->Right) P = P->Right;
  return P;
}

PtrToNode Tree_Insert(const ElementType X, Tree T) {
  return T->Root = Insert(X, T->Root, T);
}

PtrToNode Tree_Delete(const ElementType X, Tree T) {
  return T->Root = Delete(X, T->Root, T);
}

void Tree_Clear(Tree T) {
  Clear(T->Root);
  T->Root = NULL;
  T->Size = 0;
}

void Tree_Traverse(const Tree T, void (*f)(ElementType)) {
  Traverse(T->Root, f);
}

static PtrToNode Find(const ElementType X, const PtrToNode P) {
  if (!P) return NULL;
  int temp = strcmp(P->Element.Item, X.Item);
  if (temp < 0)
    return Find(X, P->Left);
  else if (temp > 0)
    return Find(X, P->Right);
  else
    return P;
}

static PtrToNode Insert(const ElementType X, PtrToNode P, Tree T) {
  if (!P) {
    P = (PtrToNode)malloc(sizeof(TreeNode));
    if (!P) return P;
    P->Right = P->Left = NULL;
    strcpy_s(P->Element.Item, sizeof(char) * 10, X.Item);
    ++T->Size;
  } else {
    int temp = strcmp(P->Element.Item, X.Item);
    if (temp < 0)
      P->Left = Insert(X, P->Left, T);
    else if (temp > 0)
      P->Right = Insert(X, P->Right, T);
  }
  return P;
}

static PtrToNode Delete(const ElementType X, PtrToNode P, Tree T) {
  if (!P) return NULL;
  int temp = strcmp(P->Element.Item, X.Item);
  if (temp < 0)
    P->Left = Delete(X, P->Left, T);
  else if (temp > 0)
    P->Right = Delete(X, P->Right, T);
  else if (P->Left && P->Right) {
    PtrToNode P_ = P->Right;
    while (P_->Left) P_ = P_->Left;
    strcpy_s(P->Element.Item, sizeof(char) * 10, P_->Element.Item);
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
    Traverse(P->Right, f);
    (*f)(P->Element);
  }
}