#ifndef ARIA_DATA_STRUCTURES_TEST_QUEUE_H
#define ARIA_DATA_STRUCTURES_TEST_QUEUE_H

#include "../datastructures.h"
#include <assert.h>
#include <stdlib.h>
#include <stdio.h>

void test_createqueue() {
  Queue *queue = createqueue();
  assert(queue != NULL);
  assert(queue->size == 0);
  assert(queue->first == NULL);
  assert(queue->last == NULL);
  deletequeue(queue);
  printf("test_createqueue passed\n");
}

void test_addtoqueue() {
  Queue *queue = createqueue();
  long long value = 10;
  addtoqueue(queue, &value);
  assert(queue->first == queue->last);
  assert(queue->size == 1);

  long long secondValue = 20;
  addtoqueue(queue, &secondValue);
  assert(queue->last != queue->first);
  assert(queue->size == 2);

  deletequeue(queue);
  printf("test_addtoqueue passed\n");
}

void test_popfromqueue() {
  Queue *queue = createqueue();
  long long value = 10;
  addtoqueue(queue, &value);
  long long secondValue = 20;
  addtoqueue(queue, &secondValue);

  void *poppedItem = popfromqueue(queue);
  assert(poppedItem == &value);
  assert(queue->size == 1);
  assert(queue->first != NULL);

  assert(popfromqueue(queue) == &secondValue);
  assert(popfromqueue(queue) == NULL);

  deletequeue(queue);
  printf("test_popfromqueue passed\n");
}

void test_deletequeue() {
  Queue *queue = createqueue();
  addtoqueue(queue, 0);
  assert((int)deletequeue(queue) == 0);
  printf("test_deletequeue passed\n");
}

void runqueuetests() {
  printf("----------STARTING QUEUE TESTS----------\n");
  test_createqueue();
  test_addtoqueue();
  test_popfromqueue();
  test_deletequeue();
  printf("---------FINISHING QUEUE TESTS----------\n");
}

#endif // ARIA_DATA_STRUCTURES_TEST_QUEUE_H