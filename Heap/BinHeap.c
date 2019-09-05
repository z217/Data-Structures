#include "BinHeap.h"

struct heap {
  int Capacity;
  int Size;
  ElementType* Elements;
};

PriorityQueue BinHeapInitialize(int MaxElements) {
  if (MaxElements < MIN_PRIORITYQUEUE_SIZE) return NULL;
  PriorityQueue PQ = (PriorityQueue)malloc(sizeof(Heap));
  if (!PQ) return NULL;
  PQ->Elements = (ElementType*)malloc((MaxElements + 1) * sizeof(ElementType));
  if (!PQ->Elements) return NULL;
  PQ->Capacity = MaxElements;
  PQ->Size = 0;
  PQ->Elements[0] = MIN_DATA;
  return PQ;
}

void BinHeapClear(PriorityQueue PQ) {
  free(PQ->Elements);
  free(PQ);
}

void BinHeapInsert(ElementType E, PriorityQueue PQ) {
  if (BinHeapIsFull(PQ)) return;
  int i;
  for (i = ++PQ->Size; PQ->Elements[i / 2] > E; i /= 2)
    PQ->Elements[i] = PQ->Elements[i / 2];
  PQ->Elements[i] = E;
}

ElementType BinHeapDeleteMin(PriorityQueue PQ) {
  if (BinHeapIsEmpty(PQ)) return PQ->Elements[0];
  ElementType minElement = PQ->Elements[1];
  ElementType lastElement = PQ->Elements[PQ->Size--];
  int i, child;
  for (i = 1; i * 2 < PQ->Size; i = child) {
    child = i * 2;
    if (child != PQ->Size && PQ->Elements[child + 1] < PQ->Elements[child])
      ++child;
    if (lastElement > PQ->Elements[child])
      PQ->Elements[i] = PQ->Elements[child];
    else
      break;
  }
  PQ->Elements[i] = lastElement;
  return minElement;
}

ElementType BinHeapFindMin(PriorityQueue PQ) {
  if (BinHeapIsEmpty(PQ)) return PQ->Elements[0];
  return PQ->Elements[1];
}

bool BinHeapIsEmpty(PriorityQueue PQ) {
  if (PQ->Size)
    return false;
  else
    return true;
}
bool BinHeapIsFull(PriorityQueue PQ) {
  if (PQ->Size == PQ->Capacity)
    return true;
  else
    return false;
}