#ifndef _LEFTHEAP_H_
#define _LEFTHEAP_H_
#include <stdbool.h>
#include <stdlib.h>

#define MIN_DATA 0

struct treenode;
typedef struct treenode TreeNode;
typedef TreeNode* PriorityQueue;
typedef int ElementType;

PriorityQueue LeftHeapInitialize(void);
ElementType LeftHeapFindMin(PriorityQueue);
bool LeftHeapEmpty(PriorityQueue);
PriorityQueue LeftHeapMerge(PriorityQueue, PriorityQueue);

#define LeftHeapInsert(E, PQ) (PQ = LeftHeapInsert1((E), PQ))
#define LeftHeapDeleteMin(PQ) (PQ = LeftHeapDeleteMin1(PQ))

PriorityQueue LeftHeapInsert1(ElementType, PriorityQueue);
PriorityQueue LeftHeapDeleteMin1(PriorityQueue);

#endif  // !_LEFTHEAP_H_
