#include "hash.h"
#include <stdlib.h>

HashTable *createhash() {
  HashTable *hash = malloc(sizeof(HashTable) * ARIA_DATA_STRUCTURES_HASH_MAX_SIZE);
  if (hash == NULL) {
    return NULL;
  }
  for (int i=0; i<ARIA_DATA_STRUCTURES_HASH_MAX_SIZE; i++) {
    hash->bucket[i] = NULL;
  }
  return hash;
}

HashTable *deletehash(HashTable *hash) {
  if (hash == NULL) {
    return NULL;
  }
  for (int i=0; i<ARIA_DATA_STRUCTURES_HASH_MAX_SIZE; i++) {
    free(hash->bucket[i]);
  }
  free(hash);
  return 0;
}

unsigned int hashfunc(char *str) {
    unsigned int hashValue = 0;
    for (; *str != '\0'; str++) {
        hashValue = 31 * hashValue + *str;
    }
    return hashValue % ARIA_DATA_STRUCTURES_HASH_MAX_SIZE;
}

void *addtohash(HashTable *hash, char *value) {
  if (hash == NULL) {
    return NULL;
  }
  LinkedList *temp = hash->bucket[hashfunc(value)];
  unsigned int index = hashfunc(value);
  hash->bucket[index] = temp == NULL ? createlist() : temp;
  addtolist(hash->bucket[index], value);
  return index;
}
