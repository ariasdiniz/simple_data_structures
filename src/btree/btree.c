#include <stdlib.h>
#include "../../datastructures.h"

static void delete_tree_node(TreeNode* node) {
  if (node->right != NULL) delete_tree_node(node->right);
  if (node->left != NULL) delete_tree_node(node->left);
  free(node);
}

BinaryTree* create_tree() {
  BinaryTree* t = malloc(sizeof(BinaryTree));
  if (t == NULL) return NULL;
  
  t->depth = 0;
  t->head = NULL;
  return t;
}

void destroy_tree(BinaryTree* tree) {
  if (tree == NULL) return;
  
  delete_tree_node(tree->head);
  free(tree);
}

long long add_tree_node(BinaryTree* tree, void* value, treeEval func) {
  if (tree == NULL || value == NULL || func == NULL) return -1;

  TreeNode* new_node = malloc(sizeof(TreeNode));
  if (new_node == NULL) return -1;

  new_node->left = NULL;
  new_node->right = NULL;
  new_node->node_val = func(value);
  new_node->value = value;

  if (tree->head == NULL) {
    tree->head = new_node;
    tree->depth++;
    return new_node->node_val;
  }

  TreeNode* parent, *child = tree->head;
  while (child != NULL) {
    parent = child;
    if (new_node->node_val > child->node_val) {
      child = child->right;
      continue;
    }
    child = child->left;
  }
  if (new_node->node_val > parent->node_val) {
    parent->right = new_node;
    tree->depth++;
    return new_node->node_val;
  }
  parent->left = new_node;
  tree->depth++;
  return new_node->node_val;
}

void* get_tree_node(BinaryTree* tree, long long value) {
  if (tree == NULL || tree->head == NULL) return NULL;
  TreeNode* node = tree->head;
  for (long long depth = 0; depth < tree->depth; depth++) {
    if (node->node_val == value) return node->value;
    if (node->node_val > value) {
      node = node->left;
      continue;
    }
    if (node->node_val < value) {
      node = node->right;
      continue;
    }
    break;
  }
  return NULL;
}