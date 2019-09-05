#ifndef _BINHEAP_H_
#define _BINHEAP_H_
#include <stdbool.h>
#include <stdlib.h>

#define MIN_PRIORITYQUEUE_SIZE 0
#define MIN_DATA 0

struct heap;
typedef struct heap Heap;
typedef Heap* PriorityQueue;
typedef int ElementType;

PriorityQueue BinHeapInitialize(int);
void BinHeapClear(PriorityQueue);
void BinHeapInsert(ElementType, PriorityQueue);
ElementType BinHeapDeleteMin(PriorityQueue);
ElementType BinHeapFindMin(PriorityQueue);
bool BinHeapIsEmpty(PriorityQueue);
bool BinHeapIsFull(PriorityQueue);

#endif  // !_BINHEAP_H_
