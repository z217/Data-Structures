#include "Stack.h"
#include <stdbool.h>
#include <stdlib.h>

struct node {
  ElementType Element;
  PtrToNode Next;
};

Stack Make_Stack(void) {
  Stack S = malloc(sizeof(Node));
  S->Next = NULL;
  return S;
}

void Stack_Initialize(Stack S) { S->Next = NULL; }

bool Stack_Empty(const Stack S) { return S->Next; }

unsigned Stack_Size(const Stack S) {
  PtrToNode P = S->Next;
  unsigned count = 0;
  while (P) {
    ++count;
    P = P->Next;
  }
  return count;
}

bool Stack_Full(const Stack S) {
  PtrToNode P = malloc(sizeof(Node));
  if (P) return false;
  return true;
}

bool Stack_Push(ElementType X, const Stack S) {
  PtrToNode temp = malloc(sizeof(Node));
  if (!temp) return false;
  temp->Element = X;
  temp->Next = S->Next;
  S->Next = temp;
  return true;
}

ElementType Stack_Top(const Stack S) { return S->Next->Element; }

void Stack_Pop(const Stack S) {
  PtrToNode temp = S->Next;
  S->Next = temp->Next;
  free(temp);
}