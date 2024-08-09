#include "../../datastructures.h"
#include <stdlib.h>
#include <stdio.h>
#include <string.h>

typedef struct KeyValue {
  char *key;
  char *value;
} KeyValue;

HashTable *createhash() {
  HashTable *hash = malloc(sizeof(HashTable));
  if (hash == NULL) {
    return (void *)-1;
  }
  for (long long i = 0; i < ARIA_DATA_STRUCTURES_HASH_MAX_SIZE; i++) {
    hash->bucket[i] = NULL;
  }
  return hash;
}

void *deletehash(HashTable *hash) {
  if (hash == NULL) {
    return (void *)-1;
  }
  LinkedList *list;
  KeyValue *kv;
  for (long long i = 0; i < ARIA_DATA_STRUCTURES_HASH_MAX_SIZE; i++) {
    list = hash->bucket[i];
    if (hash->bucket[i] != NULL) {
      for (long long j = 0; j < list->size; j++) {
        kv = getfromindex(list, j);
        free(kv->key);
        free(kv->value);
        free(kv);
      }
      deletelist(list);
    }
  }
  free(hash);
  return 0;
}

unsigned long long hashfunc(char *str) {
  unsigned long long hashValue = 0;
  for (; *str != '\0'; str++) {
    hashValue = 31 * hashValue + *str;
  }
  return hashValue % ARIA_DATA_STRUCTURES_HASH_MAX_SIZE;
}

void *addtohash(HashTable *hash, char *key, char *value) {
  if (hash == NULL) {
    return (void *)-1;
  }
  unsigned long long index = hashfunc(key);
  LinkedList *temp = hash->bucket[index];
  KeyValue *kv = malloc(sizeof(KeyValue));
  if (kv == NULL) {
    return (void *)-1;
  }
  kv->key = strdup(key);
  kv->value = strdup(value);
  hash->bucket[index] = temp == NULL ? createlist() : temp;
  addtolist(hash->bucket[index], kv);
  return 0;
}

char *getfromhash(HashTable *hash, char *key) {
  if (hash == NULL) {
    return "\0";
  }
  unsigned long long index = hashfunc(key);
  LinkedList *item = hash->bucket[index];
  if (item == NULL) {
    return "\0";
  }
  void *value;
  for (long long i = 0; i < item->size; i++) {
    value = getfromindex(item, i);
    if (strcmp(((KeyValue *)value)->key, key) == 0) {
      return ((KeyValue *)value)->value;
    }
  }
  return "\0";
}
