#include "HashQuad.h"

enum KindofEntry { Legitimate, Empty, Deleted };

struct hashentry {
  ElementType Element;
  enum KindofEntry Info;
};

struct hashtbl {
  int TableSize;
  Cell* Cells;
};

static int NextPrime(int);
static bool isPrime(int);
static int Hash(ElementType, int);


HashTable HashQuadInitialize(int TableSize) {
  if (TableSize < MIN_TABLE_SIZE) return NULL;
  HashTable H = (HashTable)malloc(sizeof(HashTbl));
  if (!H) return NULL;
  H->TableSize = NextPrime(TableSize);
  H->Cells = (Cell*)malloc(sizeof(Cell) * H->TableSize);
  if (!H->Cells) return NULL;
  for (int i = 0; i < H->TableSize; ++i) H->Cells[i].Info = Empty;
  return H;
}

void HashQuadClear(HashTable H) {
  free(H->Cells);
  free(H);
}

Position HashQuadFind(ElementType E, HashTable H) {
  Position P = Hash(E, H->TableSize);
  int CollisionNum = 0;
  while (H->Cells[P].Info != Empty && H->Cells[P].Element != E){
    P += 2 * ++CollisionNum - 1;
    if ((int)P >= H->TableSize) P -= H->TableSize;
  }
  return P;
}

void HashQuadInsert(ElementType E, HashTable H) {
  Position P;
  P = HashQuadFind(E, H);
  if (H->Cells[P].Info != Legitimate) {
    H->Cells[P].Info = Legitimate;
    H->Cells[P].Element = E;
  }
}

void HashQuadErase(ElementType E, HashTable H) {
  Position P = HashQuadFind(E, H);
  if (H->Cells[P].Info == Legitimate) H->Cells[P].Info = Empty;
}

ElementType HashQuadRetrieve(Position P, HashTable H) {
  return H->Cells[P].Element;
}

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