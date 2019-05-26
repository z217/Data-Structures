#include "Forward_List.h"
#include <stdlib.h>

struct node {
  ElementType Element;
  Position Next;
};

Forward_List Make_Forward_List(void) {
  Forward_List L = malloc(sizeof(Node));
  L->Next = NULL;
  return L;
}

void Forward_List_Initialize(Forward_List L) { L->Next = NULL; }

bool Forward_List_Empty(const Forward_List L) { return L->Next; }

bool Forward_List_Full(const Forward_List L) {
  Position P = malloc(sizeof(Node));
  if (P) {
    free(P);
    return false;
  } else
    return true;
}

bool Forward_List_Last(Position P, const Forward_List L) {
  return P->Next;
}

unsigned Forward_List_Size(const Forward_List L) {
  Position P = L->Next;
  unsigned count = 0;
  while (P) {
    ++count;
    P = P->Next;
  }
  return count;
}

Position Forward_List_At(const Forward_List L, unsigned n) {
  if (n > Forward_List_Size(L)) return NULL;
  unsigned count = 0;
  Position P = L;
  while (n > count++) P = P->Next;
  return P;
}

Position Forward_List_Find(ElementType X, const Forward_List L) {
  Position P;
  P = L->Next;
  while (P && P->Element != X) P = P->Next;
  return P;
}

Position Forward_List_Back(const Forward_List L) {
  Position P = L;
  while (P->Next) P = P->Next;
  return P;
}

Position Forward_List_Front(const Forward_List L) { return L->Next; }

Position Forward_List_Find_Previous(ElementType X, const Forward_List L) {
  Position P = L;
  while (P->Next && P->Next->Element != X) P = P->Next;
  return P;
}

bool Forward_List_Push_Back(ElementType X, const Forward_List L) {
  Position P = malloc(sizeof(Node));
  if (!P) return false;
  P->Element = X;
  P->Next = NULL;
  Forward_List_Back(L)->Next = P;
  return true;
}

bool Forward_List_Push_Front(ElementType X, Forward_List L) {
  Position P = malloc(sizeof(Node));
  if (!P) return false;
  P->Element = X;
  P->Next = L->Next;
  L->Next = P;
  return true;
}

bool Forward_List_Insert(ElementType X, const Forward_List L, Position P) {
  Position temp = malloc(sizeof(Node));
  if (!temp) return false;
  temp->Element = X;
  temp->Next = P->Next->Next;
  P->Next = temp;
  return true;
}

void Forward_List_Clear(Forward_List L) {
  Position P = L->Next, temp;
  while (!P) {
    temp = P;
    P = P->Next;
    free(temp);
  }
  L->Next = NULL;
}

void Forward_List_Erase(ElementType X, const Forward_List L) {
  Position P = Forward_List_Find_Previous(X, L), temp;
  if (!Forward_List_Last(P, L)) {
    temp = P->Next;
    P->Next = temp->Next;
    free(temp);
  }
}

void Forward_List_Pop_Back(const Forward_List L) {
  Position P = L->Next;
  while (P->Next) P = P->Next;
  free(P->Next);
  P->Next = NULL;
}

void Forward_List_Pop_Front(const Forward_List L) {
  Position P = L->Next;
  L->Next = P->Next;
  free(P);
}

ElementType Forward_List_Retrieve(const Position P) { return P->Element; }

void Forward_List_Traverse(const Forward_List L, void (*p)(ElementType X)) {
  Position P = L->Next;
  while (P) {
    (*p)(P->Element);
    P = P->Next;
  }
}