#include "../src/hash/hash.h"
#include <assert.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

HashTable *setup() {
  return createhash();
}

void teardown(HashTable *hash) {
  deletehash(hash);
}

void test_createhash() {
  HashTable *hash = setup();
  assert(hash != NULL);
  teardown(hash);
  printf("test_createhash passed\n");
}

void test_deletehash() {
  HashTable *hash = setup();
  assert(deletehash(hash) == 0);
  assert(deletehash(NULL) == -1);

  printf("test_deletehash passed\n");
}

void test_addtohash() {
  HashTable *hash = setup();
  assert(addtohash(hash, "key1", "value1") == 0);
  assert(addtohash(NULL, "key2", "value2") == -1);
  teardown(hash);
  printf("test_addtohash passed\n");
}

void test_getfromhash() {
  HashTable *hash = setup();
  addtohash(hash, "key1", "value1");
  char *value = getfromhash(hash, "key1");
  assert(value != -1 && strcmp(value, "value1") == 0);
  value = getfromhash(hash, "nonexistent");
  assert(strcmp(value, "\0") == 0);
  assert(strcmp(getfromhash(NULL, "key1"), "\0") == 0);
  teardown(hash);
  printf("test_getfromhash passed\n");
}

void runhashtests() {
  printf("----------STARTING HASHTABLE TESTS----------\n");
  test_createhash();
  test_deletehash();
  test_addtohash();
  test_getfromhash();
  printf("----------FINISHING HASHTABLE TESTS----------\n");
}
