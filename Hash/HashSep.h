#ifndef _HASHSEP_H_
#define _HASHSEP_H_

#include <stdbool.h>
#include <stdlib.h>

#define MIN_TABLE_SIZE 0

struct listnode;
struct hashtbl;
typedef struct listnode ListNode;
typedef struct hashtbl HashTbl;
typedef ListNode* List;
typedef List Position;
typedef HashTbl* HashTable;
typedef int ElementType;

HashTable HashSepInitialize(int);
void HashSepClear(HashTable);
Position HashSepFind(ElementType, HashTable);
bool HashSepInsert(ElementType, HashTable);
bool HashSepErase(ElementType, HashTable);
ElementType HashSepRetrieve(Position);

#endif  // !_HASHSEP_H_
