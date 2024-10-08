#ifndef ARIA_DATA_STRUCTURES_TEST_LIST
#define ARIA_DATA_STRUCTURES_TEST_LIST

#include "../datastructures.h"
#include <assert.h>
#include <stdio.h>

void test_createlist() {
  LinkedList *list = createlist();
  assert(list != NULL);
  assert(list->head == NULL);
  assert(list->tail == NULL);
  assert(list->size == 0);
  deletelist(list);
  printf("test_createlist passed\n");
}

void test_deletelist() {
  // Test deletion on an empty list
  LinkedList *emptyList = createlist();
  assert(deletelist(emptyList) == 0);

  // Test deletion on a list with multiple elements
  LinkedList *list = createlist();
  long long values[] = {10, 20, 30};
  for (long long i = 0; i < 3; i++) {
  addtolist(list, &values[i]);
  }
  assert(deletelist(list) == 0);

  // Test with NULL
  assert(deletelist(NULL) == -1);

  printf("test_deletelist passed\n");
}

void test_addtolist() {
  LinkedList *list = createlist();
  long long value = 10;
  long long nullValue;

  // Test adding to an empty list
  assert(addtolist(list, &value) == 0);
  assert(list->size == 1);

  // Test adding to a non-empty list
  assert(addtolist(list, &value) == 0);
  assert(list->size == 2);

  // Test adding NULL as value
  assert(addtolist(list, &nullValue) == 0);

  // Test with NULL list pointer
  assert(addtolist(NULL, &value) == -1);

  deletelist(list);
  printf("test_addtolist passed\n");
}

void test_getfromindex() {
  LinkedList *list = createlist();
  long long values[] = {10, 20, 30};
  for (long long i = 0; i < 3; i++) {
  addtolist(list, &values[i]);
  }

  // Test getting first and last elements
  assert(getfromindex(list, 0) == &values[0]);
  assert(getfromindex(list, 2) == &values[2]);

  // Test with index greater than size
  assert(getfromindex(list, 3) == NULL);

  // Test with negative index
  assert(getfromindex(list, -1) == NULL);

  // Test with NULL list pointer
  assert(getfromindex(NULL, 0) == NULL);

  deletelist(list);
  printf("test_getfromindex passed\n");
}

void test_removefromindex() {
  LinkedList *list = createlist();
  long long values[] = {10, 20, 30};
  for (long long i = 0; i < 3; i++) {
  addtolist(list, &values[i]);
  }

  // Test removing first, middle, last
  assert(removefromindex(list, 0) == 0);
  assert(removefromindex(list, 1) == 0); // Now middle after first removal
  assert(removefromindex(list, 0) == 0); // Now last

  // Test removing from list with one element
  LinkedList *singleItemList = createlist();
  long long singleValue = 40;
  addtolist(singleItemList, &singleValue);
  assert(removefromindex(singleItemList, 0) == 0);

  // Test with index greater than size
  assert(removefromindex(list, 3) == -1);

  // Test with negative index
  assert(removefromindex(list, -1) == -1);

  // Test with NULL list pointer
  assert(removefromindex(NULL, 0) == -1);

  deletelist(list);
  deletelist(singleItemList);
  printf("test_removefromindex passed\n");
}

void runlisttests() {
  printf("----------STARTING LINKED LIST TESTS----------\n");
  test_createlist();
  test_deletelist();
  test_addtolist();
  test_getfromindex();
  test_removefromindex();
  printf("---------FINISHING LINKED LIST TESTS----------\n");
}

#endif //ARIA_DATA_STRUCTURES_TEST_LIST_H
