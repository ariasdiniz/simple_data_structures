#ifndef GENERIC_LINKED_LIST_LIST_H
#define GENERIC_LINKED_LIST_LIST_H

struct Node {
  void *value;
  struct Node *next;
};

struct LinkedList {
  struct Node *head;
  struct Node *tail;
  int size;
};

struct LinkedList *createlist();
void *deletelist(struct LinkedList *list);
void *addtolist(struct LinkedList *list, void *value);
void *getfromindex(struct LinkedList *list, int index);
void *removefromindex(struct LinkedList *list, int index);

#endif // GENERIC_LINKED_LIST_LIST_H