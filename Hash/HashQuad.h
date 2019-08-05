#ifndef _HASHQUAD_H_
#define _HASHQUAD_H_
#include <stdlib.h>
#include <stdbool.h>

#define MIN_TABLE_SIZE 0

struct hashtbl;
struct hashtntry;
typedef struct hashtbl HashTbl;
typedef struct hashentry HashEntry;
typedef unsigned Index;
typedef Index Position;
typedef HashTbl* HashTable;
typedef HashEntry Cell;
typedef int ElementType;

HashTable HashQuadInitialize(int);
void HashQuadClear(HashTable);
Position HashQuadFind(ElementType, HashTable);
void HashQuadInsert(ElementType, HashTable);
void HashQuadErase(ElementType, HashTable);
ElementType HashQuadRetrieve(Position, HashTable);

#endif  // !_HASHQUAD_H_
