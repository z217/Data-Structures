#include "Queue.h"
#include <stdbool.h>
#include <stdlib.h>

struct node {
  ElementType Element;
  struct node *Next;
};

struct queue {
  PtrToNode Front;
  PtrToNode Rear;
  unsigned Items;
};

Queue Make_Queue(void) {
  Queue Q = (Queue)malloc(sizeof(struct queue));
  Q->Front = Q->Rear = NULL;
  Q->Items = 0;
  return Q;
}

void Queue_Initialize(Queue Q) {
  Q->Front = Q->Rear = NULL;
  Q->Items = 0;
}

bool Queue_Empty(const Queue Q) { return !Q->Items; }

unsigned Queue_Size(const Queue Q) { return Q->Items; }

bool Queue_EnQueue(const ElementType X, Queue Q) {
  PtrToNode P = (PtrToNode)malloc(sizeof(Node));
  if (!P) return false;
  P->Element = X;
  P->Next = NULL;
  if (Queue_Empty(Q))
    Q->Front = P;
  else
    Q->Rear->Next = P;
  Q->Rear = P;
  Q->Items++;
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
    Q->Rear->Next = P;
  Q->Rear = P;
  Q->Items++;
  return true;
}

bool Queue_DeQueue(ElementType *i, Queue Q) {
  PtrToNode P = Q->Front;
  if (!P) return false;
  *i = Q->Front->Element;
  Q->Front = Q->Front->Next;
  free(P);
  Q->Items--;
  if (Queue_Empty(Q)) Q->Rear = NULL;
  return true;
}

bool Queue_Pop(Queue Q) {
  PtrToNode P = Q->Front, P_ = Q->Rear;
  if (!P) return false;
  if (!P->Next)
    P = NULL;
  else {
    while (P->Next != Q->Rear) P = P->Next;
    P->Next = NULL;
  }
  free(P_);
  Q->Rear = P;
  Q->Items--;
  return true;
}

ElementType Queue_Front(const Queue Q) { return Q->Front->Element; }

ElementType Queue_Back(const Queue Q) { return Q->Rear->Element; }

void Queue_Clear(Queue Q) {
  PtrToNode P = Q->Front, P_;
  while (P) {
    P_ = P;
    P = P->Next;
    free(P_);
    Q->Items--;
  }
  Q->Front = Q->Rear = NULL;
}