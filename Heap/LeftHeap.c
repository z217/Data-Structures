#include "LeftHeap.h"

static PriorityQueue LeftHeapMerge1(PriorityQueue, PriorityQueue);

struct treenode {
  ElementType Element;
  PriorityQueue Left;
  PriorityQueue Right;
  int Npl;
};

PriorityQueue LeftHeapInitialize(void) {
  PriorityQueue PQ = (PriorityQueue)malloc(sizeof(TreeNode));
  PQ->Element = MIN_DATA;
  PQ->Left = PQ->Right = NULL;
  PQ->Npl = -1;
  return PQ;
}

ElementType LeftHeapFindMin(PriorityQueue PQ) {
  if (LeftHeapEmpty(PQ)) return MIN_DATA - 1;
  else
    return PQ->Element;
}

bool LeftHeapEmpty(PriorityQueue PQ) { return PQ->Npl == -1; }

PriorityQueue LeftHeapMerge(PriorityQueue PQ1, PriorityQueue PQ2) {
  if (!PQ1)
    return PQ2;
  else if (!PQ2)
    return PQ1;
  if (PQ1->Element < PQ2->Element)
    return LeftHeapMerge1(PQ1, PQ2);
  else
    return LeftHeapMerge1(PQ2, PQ1);
}

PriorityQueue LeftHeapInsert1(ElementType E, PriorityQueue PQ) {
  PriorityQueue node = (PriorityQueue)malloc(sizeof(TreeNode));
  if (!node) return NULL;
  else {
    node->Element = E;
    node->Npl = 0;
    node->Left = node->Right = NULL;
    PQ = LeftHeapMerge(node, PQ);
  }
}

PriorityQueue LeftHeapDeleteMin1(PriorityQueue PQ) {
  if (LeftHeapEmpty(PQ)) return PQ;
  PriorityQueue left = PQ->Left, right = PQ->Right;
  free(PQ);
  return LeftHeapMerge(left, right);
}

PriorityQueue LeftHeapMerge1(PriorityQueue PQ1, PriorityQueue PQ2) {
  if (!PQ1->Left)
    PQ1->Left = PQ2;
  else {
    PQ1->Right = LeftHeapMerge(PQ1->Right, PQ2);
    if (PQ1->Left->Npl < PQ1->Right->Npl) {
      PriorityQueue temp = PQ1->Left;
      PQ1->Left = PQ1->Right;
      PQ1->Right = temp;
    }
    PQ1->Npl = PQ1->Right->Npl + 1;
  }
  return PQ1;
}