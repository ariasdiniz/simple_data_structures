#include "list.h"
#include <stdlib.h>
#include <stdio.h>

/*
  Create a new LinkedList.

  @return struct LinkedList* A pointer to the newly created LinkedList.
  Don't forget to free memory after usage with deletelist(list).
*/
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

/*
  Free the memory allocated by createlist().

  @param list A pointer to a LinkedList.
  @return void* Returns 0 when successful. NULL when the list param is NULL.
*/
void *deletelist(struct LinkedList *list) {
  if (list == NULL) {
    return NULL;
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

/*
  Add a new element at the bottom of the list.

  @param list A pointer to a LinkedList.
  @param value A void pointer to the value to be added to the list.
  @return Returns 0 if successful. Returns NULL when an error occur.
*/
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

/*
  Gets the value of an specific index in the provided list.

  @param list A pointer to a LinkedList.
  @param index An integer representing the index.
  @returns Returns a pointer to the value of the index. Return NULL in case of error.
*/
void *getfromindex(struct LinkedList *list, int index) {
  if (list == NULL || index > list->size - 1 || index < 0) {
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

/*
  Remove an index from the provided list.

  @param list A pointer to a LinkedList.
  @param index An integer representing the index to be removed.
  @return Return 0 when successful. Return NULL in case of error.
*/
void *removefromindex(struct LinkedList *list, int index) {
  if (list == NULL || index >= list->size || index < 0) {
    return NULL;
  }
  struct Node *node = list->head;
  struct Node *temp;
  if (index == 0) {
    list->head = node->next;
    free(node);
    list->size--;
    return 0;
  }
  for (int i=0; i < index; i++) {
    temp = node;
    node = node->next;
  }
  temp->next = node->next;
  free(node);
  list->size--;
  return 0;
}