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
  struct Node *temp;
  if (node == NULL) {
    return NULL;
  }
  temp = list->head;
  while (1) {
    if (temp->next == NULL) {
      break;
    }
    temp = temp->next;
  }
  node->value = value;
  node->next = NULL;
  temp->next = node;
  list->size++;
  return 0;
}

void *getfromindex(struct LinkedList *list, int index) {
  if (index > list->size - 1 || index < 0) {
    return NULL;
  }
  struct Node *node = malloc(sizeof(struct Node));
  if (node == NULL) {
    return NULL;
  }
  node = list->head;
  for (int i=0; i < index; i++) {
    node = node->next;
  }
  return node->value;
}

void *removefromindex(struct LinkedList *list, int index) {
  if (list == NULL || index >= list->size || index < 0) {
    return NULL;
  }
  struct Node *node = list->head;
  struct Node *temp;
  for (int i=0; i < index; i++) {
    temp = node;
    node = node->next;
  }
  temp->next = node->next;
  free(node);
  list->size--;
  return 0;
}