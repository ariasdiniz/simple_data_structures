#include "stack.h"
#include <stdlib.h>

struct StackItem {
  void *value;
  struct StackItem *next;
};

/*
  The Stack data structure.
*/
struct Stack {
  struct StackItem *top;
  int size;
};

struct Stack *createstack() {
  struct Stack *stack = malloc(sizeof(struct Stack));
  if (stack == NULL) {
    return NULL;
  }
  stack->size = 0;
  stack->top = NULL;
}

void *destroystack(struct Stack *stack) {
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
