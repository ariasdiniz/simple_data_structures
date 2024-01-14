#include "hash.h"
#include <stdlib.h>
#include <stdio.h>

typedef struct KeyValue {
  char *key;
  char *value;
} KeyValue;

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
  LinkedList *list;
  for (int i=0; i<ARIA_DATA_STRUCTURES_HASH_MAX_SIZE; i++) {
    list = hash->bucket[i]->list;
    if (hash->bucket[i] != NULL) {
      for (int i=0; i<list->size; i++) {
        free(getfromindex(list, i));
      }
      deletelist(list);
    }
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

void *addtohash(HashTable *hash, char *key, char *value) {
  if (hash == NULL) {
    return NULL;
  }
  unsigned int index = hashfunc(key);
  LinkedList *temp = hash->bucket[index];
  KeyValue *kv = malloc(sizeof(KeyValue));
  if (kv == NULL) {
    return NULL;
  }
  kv->key = key;
  kv->value = value;
  hash->bucket[index] = temp == NULL ? createlist() : temp;
  addtolist(hash->bucket[index], kv);
  return 0;
}
