#ifndef ARIA_DATA_STRUCTURES_HASH_H
#define ARIA_DATA_STRUCTURES_HASH_H

#define ARIA_DATA_STRUCTURES_HASH_MAX_SIZE 1000
#include "../linkedlist/list.h"

struct HashItem {
  int index;
  struct LinkedList *list;
};

struct HashTable {
  struct HashItem *bucket[ARIA_DATA_STRUCTURES_HASH_MAX_SIZE];
};

#endif // ARIA_DATA_STRUCTURES_HASH_H