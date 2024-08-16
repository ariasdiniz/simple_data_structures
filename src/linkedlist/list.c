#include "../../datastructures.h"
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

int deletelist(struct LinkedList *list) {
  if (list == NULL) {
    return -1;
  }
  if (list->size == 0) {
    free(list);
    return 0;
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

int addtolist(struct LinkedList *list, void *value) {
  if (list == NULL) {
    return -1;
  }
  if (list->size == 0) {
    struct Node *node = malloc(sizeof(struct Node));
    if (node == NULL) {
      return -1;
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
    return -1;
  }
  node->value = value;
  node->next = NULL;
  list->tail->next = node;
  list->tail = node;
  list->size++;
  return 0;
}

void *getfromindex(struct LinkedList *list, long long index) {
  if (list == NULL || index > list->size - 1 || index < 0) {
    return NULL;
  }
  struct Node *node = list->head;
  for (long long i=0; i < index; i++) {
    node = node->next;
  }
  return node->value;
}

static void resetlist(struct LinkedList *list) {
  if (list->size == 0) {
    list->head = NULL;
    list->tail = NULL;
  }
}

int removefromindex(struct LinkedList *list, long long index) {
  if (list == NULL || index >= list->size || index < 0) {
    return -1;
  }
  struct Node *node = list->head;
  struct Node *temp;
  if (index == 0) {
    list->head = node->next;
    free(node);
    list->size--;
    resetlist(list);
    return 0;
  }
  for (long long i=0; i < index; i++) {
    temp = node;
    node = node->next;
  }
  temp->next = node->next;
  free(node);
  list->size--;
  resetlist(list);
  return 0;
}