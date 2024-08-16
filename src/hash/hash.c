#include "../../datastructures.h"
#include <stdlib.h>
#include <stdio.h>
#include <string.h>

typedef struct KeyValue {
  char *key;
  void *value;
} KeyValue;

HashTable *createhash() {
  HashTable *hash = malloc(sizeof(HashTable));
  if (hash == NULL) {
    return NULL;
  }
  for (long long i = 0; i < ARIA_DATA_STRUCTURES_HASH_MAX_SIZE; i++) {
    hash->bucket[i] = NULL;
  }
  return hash;
}

int deletehash(HashTable *hash) {
  if (hash == NULL) {
    return -1;
  }
  LinkedList *list;
  KeyValue *kv;
  for (long long i = 0; i < ARIA_DATA_STRUCTURES_HASH_MAX_SIZE; i++) {
    list = hash->bucket[i];
    if (hash->bucket[i] != NULL) {
      for (long long j = 0; j < list->size; j++) {
        kv = getfromindex(list, j);
        free(kv->key);
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

int addtohash(HashTable *hash, char *key, void *value) {
  if (hash == NULL) {
    return -1;
  }
  unsigned long long index = hashfunc(key);
  LinkedList *temp = hash->bucket[index];
  KeyValue *kv = malloc(sizeof(KeyValue));
  if (kv == NULL) {
    return -1;
  }
  kv->key = strdup(key);
  kv->value = value;
  hash->bucket[index] = temp == NULL ? createlist() : temp;
  addtolist(hash->bucket[index], kv);
  return 0;
}

void *getfromhash(HashTable *hash, char *key) {
  if (hash == NULL) {
    return NULL;
  }
  unsigned long long index = hashfunc(key);
  LinkedList *item = hash->bucket[index];
  if (item == NULL) {
    return NULL;
  }
  void *value;
  for (long long i = 0; i < item->size; i++) {
    value = getfromindex(item, i);
    if (strcmp(((KeyValue *)value)->key, key) == 0) {
      return ((KeyValue *)value)->value;
    }
  }
  return NULL;
}

int updatehashitem(HashTable *hash, char *key, void *new_value) {
  if (hash == NULL) {
    return -1;
  }
  unsigned long long index = hashfunc(key);
  LinkedList *item = hash->bucket[index];
  if (item == NULL) {
    return -1;
  }
  void *value;
  for (long long i = 0; i < item->size; i++) {
    value = getfromindex(item, i);
    if (strcmp(((KeyValue *)value)->key, key) == 0) {
      ((KeyValue *)value)->value = new_value;
      return 0;
    }
  }
  return -1;
}
