#include <stdlib.h>
#include "../../datastructures.h"

BinaryTree* create_tree() {
  BinaryTree* t = malloc(sizeof(BinaryTree));
  if (t == NULL) return NULL;
  
  t->depth = 0;
  t->head = NULL;
  return t;
}
