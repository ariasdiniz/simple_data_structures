#ifndef ARIA_DATA_STRUCTURES_LIST_H
#define ARIA_DATA_STRUCTURES_LIST_H

struct Node {
  void *value;
  struct Node *next;
};

typedef struct LinkedList {
  struct Node *head;
  struct Node *tail;
  long long size;
} LinkedList;

struct LinkedList *createlist();
void *deletelist(struct LinkedList *list);
void *addtolist(struct LinkedList *list, void *value);
void *getfromindex(struct LinkedList *list, long long index);
void *removefromindex(struct LinkedList *list, long long index);

#endif // ARIA_DATA_STRUCTURES_LIST_H