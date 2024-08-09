#include "../../datastructures.h"
#include <stdlib.h>

struct Queue *createqueue() {
  struct Queue *queue = malloc(sizeof(struct Queue));
  if (queue == NULL) {
    return NULL;
  }
  queue->first = NULL;
  queue->last = NULL;
  queue->size = 0;
  return queue;
}

void *deletequeue(struct Queue *queue) {
  if (queue == NULL) {
    return (void *)-1;
  }
  if (queue->size == 0) {
    free(queue);
    return 0;
  }
  struct QueueItem *next;
  struct QueueItem *actual = queue->last;
  for (long long i=0; i < queue->size; i++) {
    next = actual->next;
    free(actual);
    actual = next;
  }
  free(queue);
  return 0;
}

void *addtoqueue(struct Queue *queue, void *value) {
  if (queue == NULL) {
    return (void *)-1;
  }
  struct QueueItem *item = malloc(sizeof(struct QueueItem));
  if (item == NULL) {
    return (void *)-1;
  }
  item->value = value;
  item->prev = NULL;
  if (queue->size == 0) {
    item->next = NULL;
    queue->first = item;
    queue->last = item;
    queue->size++;
    return 0;
  }
  item->next = queue->last;
  queue->last->prev = item;
  queue->last = item;
  queue->size++;
  return 0;
}

void *popfromqueue(struct Queue *queue) {
  if (queue == NULL) {
    return NULL;
  }
  struct QueueItem *item = queue->first;
  void *value = item->value;
  if (item == queue->last) {
    queue->first = NULL;
    queue->last = NULL;
    queue->size--;
    free(item);
    return value;
  }
  queue->first = item->prev;
  queue->size--;
  free(item);
  return value;
}
