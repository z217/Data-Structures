#include "HashSep.h"

struct listnode {
  ElementType Element;
  Position Next;
};

struct hashtbl {
  int TableSize;
  List* Lists;
};

static int NextPrime(int);
static bool isPrime(int);
static int Hash(ElementType, int);

HashTable HashSepInitialize(int size) {
  if (size < MIN_TABLE_SIZE) return NULL;
  HashTable H = (HashTable)malloc(sizeof(HashTbl));
  if (!H) return NULL;
  H->TableSize = NextPrime(size);
  H->Lists = malloc(sizeof(List) * H->TableSize);
  if (!H->Lists) return NULL;
  for (int i = 0; i < H->TableSize; ++i) {
    H->Lists[i] = (List)malloc(sizeof(ListNode));
    if (!H->Lists[i])
      return NULL;
    else
      H->Lists[i]->Next = NULL;
  }
  return H;
}

void HashSepClear(HashTable H) {
  for(int i = 0; i < H->TableSize; ++i){
    Position P = H->Lists[i];
    while (P) {
      Position temp = P;
      P = P->Next;
      free(temp);
    }
  }
  free(H);
}

Position HashSepFind(ElementType E, HashTable H) {
  List L = H->Lists[Hash(E, H->TableSize)];
  Position P = L->Next;
  while (P && P->Element != E) P = P->Next;
  return P;
}

bool HashSepInsert(ElementType E, HashTable H) {
  Position P = HashSepFind(E, H);
  if (!P) P = (Position)malloc(sizeof(ListNode));
  if (!P)
    return false;
  else {
    List L = H->Lists[Hash(E, H->TableSize)];
    P->Next = L->Next;
    P->Element = E;
    L->Next = P;
    return true;
  }
}

bool HashSepErase(ElementType E, HashTable H) {
  Position P = HashSepFind(E, H);
  if (!P) return true;
  else {
    List L = H->Lists[Hash(E, H->TableSize)];
    while (L->Next && L->Next->Element != E) L = L->Next;
    P = L->Next;
    L->Next = P->Next;
    free(P);
    return true;
  }
}

ElementType HashSepRetrieve(Position P) { return P->Element; }

bool isPrime(int num) {
  if (num == 2 || num == 3) {
    return true;
  }
  if (num % 6 != 1 && num % 6 != 5) {
    return false;
  }
  for (int i = 5; i * i <= num; i += 6) {
    if (num % i == 0 || num % (i + 2) == 0) {
      return false;
    }
  }
  return true;
}

int NextPrime(int n) {
  bool state = isPrime(n);
  while (!state) {
    state = isPrime(++n);
  }
  return n;
}

int Hash(ElementType E, int i) { return E % i; }