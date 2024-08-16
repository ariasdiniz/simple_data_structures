#include "../../datastructures.h"
#include <stdlib.h>

struct Stack *createstack() {
  struct Stack *stack = malloc(sizeof(struct Stack));
  if (stack == NULL) {
    return NULL;
  }
  stack->size = 0;
  stack->top = NULL;
  return stack;
}

int deletestack(struct Stack *stack) {
  if (stack == NULL) {
    return -1;
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

int addtostack(struct Stack *stack, void *value) {
  if (stack == NULL) {
    return -1;
  }
  struct StackItem *item = malloc(sizeof(struct StackItem));
  if (item == NULL) {
    return -1;
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
  void *value = item->value;
  stack->top = stack->top->next;
  stack->size--;
  free(item);
  return value;
}
