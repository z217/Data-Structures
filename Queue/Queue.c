#include "Queue.h"
#include <stdbool.h>
#include <stdlib.h>

struct node {
  ElementType Element;
  struct node *Next;
};

struct queue {
  PtrToNode Front;
  PtrToNode Back;
  unsigned Size;
};

Queue Make_Queue(void) {
  Queue Q = (Queue)malloc(sizeof(struct queue));
  Q->Front = Q->Back = NULL;
  Q->Size = 0;
  return Q;
}

void Queue_Initialize(Queue Q) {
  Q->Front = Q->Back = NULL;
  Q->Size = 0;
}

bool Queue_Empty(const Queue Q) { return !Q->Size; }

unsigned Queue_Size(const Queue Q) { return Q->Size; }

bool Queue_EnQueue(const ElementType X, Queue Q) {
  PtrToNode P = (PtrToNode)malloc(sizeof(Node));
  if (!P) return false;
  P->Element = X;
  P->Next = NULL;
  if (Queue_Empty(Q))
    Q->Front = P;
  else
    Q->Back->Next = P;
  Q->Back = P;
  ++Q->Size;
  return true;
}

bool Queue_Push(const ElementType X, Queue Q) {
  PtrToNode P = (PtrToNode)malloc(sizeof(Node));
  if (!P) return false;
  P->Element = X;
  P->Next = NULL;
  if (Queue_Empty(Q))
    Q->Front = P;
  else
    Q->Back->Next = P;
  Q->Back = P;
  ++Q->Size;
  return true;
}

bool Queue_DeQueue(ElementType *i, Queue Q) {
  PtrToNode P = Q->Front;
  if (!P) return false;
  *i = Q->Front->Element;
  Q->Front = Q->Front->Next;
  free(P);
  --Q->Size;
  if (Queue_Empty(Q)) Q->Back = NULL;
  return true;
}

bool Queue_Pop(Queue Q) {
  PtrToNode P = Q->Front, P_ = Q->Back;
  if (!P) return false;
  if (!P->Next)
    P = NULL;
  else {
    while (P->Next != Q->Back) P = P->Next;
    P->Next = NULL;
  }
  free(P_);
  Q->Back = P;
  --Q->Size;
  return true;
}

PtrToNode Queue_Front(const Queue Q) { return Q->Front; }

PtrToNode Queue_Back(const Queue Q) { return Q->Back; }

ElementType Queue_Retrieve(const PtrToNode P) { return P->Element; }

void Queue_Clear(Queue Q) {
  PtrToNode P = Q->Front, P_;
  while (P) {
    P_ = P;
    P = P->Next;
    free(P_);
    --Q->Size;
  }
  Q->Front = Q->Back = NULL;
}