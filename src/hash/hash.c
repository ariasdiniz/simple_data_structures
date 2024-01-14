#include "hash.h"
#include <stdlib.h>

#define CALL_HASHING_FUNCTION(a, b) a b

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
