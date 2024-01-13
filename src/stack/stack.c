#include "stack.h"
#include <stdlib.h>

struct Stack *createstack() {
  struct Stack *stack = malloc(sizeof(struct Stack));
  if (stack == NULL) {
    return NULL;
  }
  stack->size = 0;
  stack->top = NULL;
}

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

void *popfromstack(struct Stack *stack) {
  if (stack == NULL || stack->size == 0) {
    return NULL;
  }
  struct StackItem *item = stack->top;
  stack->top = stack->top->next;
  stack->size--;
  return item->value;
}
