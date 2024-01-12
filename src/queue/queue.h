#ifndef ARIA_DATA_STRUCTURES_QUEUE_H
#define ARIA_DATA_STRUCTURES_QUEUE_H

struct QueueItem {
  void *value;
  struct QueueItem *next;
};

struct Queue {
  struct QueueItem *first;
  struct QueueItem *last;
  int size;
};

void *createqueue();
void *deletequeue();
void *addtoqueue();
void *popfromqueue();

#endif // ARIA_DATA_STRUCTURES_QUEUE_H