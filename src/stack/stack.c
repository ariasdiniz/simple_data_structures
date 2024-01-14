#include "stack.h"
#include <stdlib.h>

/*
  Create a new Stack.

  @return Return a pointer to the newly created Stack.
  Don't forget to free memory after usage with deletestack(stack).
*/
struct Stack *createstack() {
  struct Stack *stack = malloc(sizeof(struct Stack));
  if (stack == NULL) {
    return NULL;
  }
  stack->size = 0;
  stack->top = NULL;
}

/*
  Safely delete the Stack freeing the memory.
  If you used this structure to store in the values pointers for
  other manually allocated memory adresses, please free all pointers
  before calling this method.
  @param stack A pointer to a Stack.
  @return Return 0 when successful. Return NULL if Stack is empty or NULL.
*/
void *deletestack(struct Stack *stack) {
  if (stack == NULL) {
    return NULL;
  }
  if (stack->size == 0 && stack->top == NULL) {
    free(stack);
    return 0;
  }
  struct StackItem *item = stack->top;
  struct StackItem *temp;
  while (item != NULL) {
    temp = item->next;
    free(item);
    item = temp;    
  }
  free(stack);
  return 0;
}

/*
  Add a new element to the Stack.
  @param stack A pointer to a Stack.
  @param value A pointer to a value to be stored.
  @return Return 0 if successful. Return NULL if Stack is NULL or empty,
  or in case of error in memory allocation.
*/
void *addtostack(struct Stack *stack, void *value) {
  if (stack == NULL || value == NULL) {
    return NULL;
  }
  struct StackItem *item = malloc(sizeof(struct StackItem));
  if (item == NULL) {
    return NULL;
  }
  item->next = stack->top;
  item->value = value;
  stack->top = item;
  stack->size++;
  return 0;
}

/*
  Removes the top element of the Stack and return a pointer to it's value.
  Don't forget to free this pointer afterward, if it point to a manually
  allocated memory address.
  @param stack A pointer to a Stack.
  @return A pointer to the value stored. Return NULL if the Stack is empty.
*/
void *popfromstack(struct Stack *stack) {
  if (stack == NULL || stack->size == 0) {
    return NULL;
  }
  struct StackItem *item = stack->top;
  void *value = item->value;
  stack->top = stack->top->next;
  stack->size--;
  free(item);
  return value;
}
