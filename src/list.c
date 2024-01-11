#include "list.h"
#include <stdlib.h>
#include <stdio.h>

struct LinkedList *createlist() {
  struct LinkedList *list = malloc(sizeof(struct LinkedList));
  if (list == NULL) {
    return NULL;
  }
  list->head = NULL;
  list->tail = NULL;
  list->size = 0;
  return list;
}

void *deletelist(struct LinkedList *list) {
  if (list == NULL) {
    return NULL;
  }
  struct Node *node = list->head;
  struct Node *nextnode = list->head->next;
  while (nextnode != NULL) {
    free(node);
    node = nextnode;
    nextnode = node->next;
  }
  free(node);
  free(list);
  return 0;
}

void *addtolist(struct LinkedList *list, void *value) {
  if (list == NULL) {
    return NULL;
  }
  if (list->size == 0) {
    struct Node *node = malloc(sizeof(struct Node));
    if (node == NULL) {
      return NULL;
    }
    node->value = value;
    node->next = NULL;
    list->head = node;
    list->tail = node;
    list->size++;
    return 0;
  }
  struct Node *node = malloc(sizeof(struct Node));
  if (node == NULL) {
    return NULL;
  }
  node->value = value;
  node->next = NULL;
  list->tail->next = node;
  list->tail = node;
  return 0;
}

void *getfromindex(struct LinkedList *list, int index) {
  // Implement me
}

void *removefromindex(struct LinkedList *list, int index) {
  // Implement me
}