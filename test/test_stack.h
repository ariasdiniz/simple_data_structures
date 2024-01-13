#include "../src/stack/stack.h"
#include <assert.h>
#include <stdlib.h>
#include <stdio.h>

void test_createstack() {
  struct Stack *stack = createstack();
  assert(stack != NULL);  // Check if stack is created
  assert(stack->size == 0);  // Initial size should be 0
  assert(stack->top == NULL);  // Top should be NULL initially
  deletestack(stack);
  printf("test_createstack passed\n");
}

void test_deletestack() {
  struct Stack *stack = createstack();
  deletestack(stack);  // Should be able to delete an empty stack

  stack = createstack();
  addtostack(stack, malloc(sizeof(int)));  // Add an item
  deletestack(stack);  // Should be able to delete a non-empty stack
  printf("test_deletestack passed\n");
}

void test_addtostack() {
  struct Stack *stack = createstack();
  int value = 10;
  addtostack(stack, &value);
  assert(stack->size == 1);  // Size should be 1 after adding
  assert(stack->top->value == &value);  // Top item should be the one added
  deletestack(stack);
  printf("test_addtostack passed\n");
}

void test_popfromstack() {
  struct Stack *stack = createstack();
  int value = 10;
  addtostack(stack, &value);
  int *poppedValue = popfromstack(stack);
  assert(poppedValue == &value);  // Popped value should match the added value
  assert(stack->size == 0);  // Stack should be empty after popping
  assert(stack->top == NULL);  // Top should be NULL after popping
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
