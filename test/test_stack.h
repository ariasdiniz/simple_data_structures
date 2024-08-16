#include "../datastructures.h"
#include <assert.h>
#include <stdlib.h>
#include <stdio.h>
#include <stdint.h>

void test_createstack() {
  Stack *stack = createstack();
  assert(stack != NULL);
  assert(stack->size == 0);
  assert(stack->top == NULL);
  deletestack(stack);
  printf("test_createstack passed\n");
}

void test_deletestack() {
  Stack *stack = createstack();
  deletestack(stack);

  stack = createstack();
  int i = 1;
  addtostack(stack, (void *)(intptr_t)i);
  deletestack(stack);
  printf("test_deletestack passed\n");
}

void test_addtostack() {
  Stack *stack = createstack();
  int value = 10;
  addtostack(stack, (void *)(intptr_t)value);
  assert(stack->size == 1);
  assert((int)(intptr_t)stack->top->value == value);
  deletestack(stack);
  printf("test_addtostack passed\n");
}

void test_popfromstack() {
  Stack *stack = createstack();
  long long value = 10;
  addtostack(stack, &value);
  long long *poppedValue = popfromstack(stack);
  assert(poppedValue == &value);
  assert(stack->size == 0);
  assert(stack->top == NULL);
  assert(popfromstack(stack) == NULL);
  deletestack(stack);
  printf("test_popfromstack passed\n");
}

void runstacktests() {
  printf("---------STARTING STACK TESTS----------\n");
  test_createstack();
  test_deletestack();
  test_addtostack();
  test_popfromstack();
  printf("---------FINISHING STACK TESTS----------\n");
}
