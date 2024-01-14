#ifndef ARIA_DATA_STRUCTURES_HASH_H
#define ARIA_DATA_STRUCTURES_HASH_H

#define ARIA_DATA_STRUCTURES_HASH_MAX_SIZE 1000
#include "../linkedlist/list.h"

struct HashItem {
  int index;
  LinkedList *list;
};

typedef struct HashTable {
  struct HashItem *bucket[ARIA_DATA_STRUCTURES_HASH_MAX_SIZE];
} HashTable;

HashTable *createhash();
HashTable *deletehash(HashTable *hash);

#endif // ARIA_DATA_STRUCTURES_HASH_H