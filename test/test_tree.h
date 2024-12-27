#ifndef ARIA_DATA_STRUCTURES_TEST_TREE
#define ARIA_DATA_STRUCTURES_TEST_TREE

#include "../datastructures.h"
#include <assert.h>
#include <stdio.h>

long long sample_eval_func(void* value) {
    return *(long long*)value;
}

void test_create_tree() {
    BinaryTree* tree = create_tree();
    assert(tree != NULL);
    assert(tree->head == NULL);
    assert(tree->n_nodes == 0);
    destroy_tree(tree);
    printf("test_create_tree passed\n");
}

void test_destroy_tree() {
    // Test destroying an empty tree
    BinaryTree* tree = create_tree();
    destroy_tree(tree);

    // Test destroying a tree with nodes
    tree = create_tree();
    long long values[] = {10, 20, 30};
    for (int i = 0; i < 3; i++) {
        add_tree_node(tree, &values[i], sample_eval_func);
    }
    destroy_tree(tree);

    // Test with NULL
    destroy_tree(NULL);

    printf("test_destroy_tree passed\n");
}

void test_add_tree_node() {
    BinaryTree* tree = create_tree();
    long long values[] = {20, 10, 30};

    // Test adding nodes
    for (int i = 0; i < 3; i++) {
        assert(add_tree_node(tree, &values[i], sample_eval_func) == values[i]);
    }

    // Test tree structure
    assert(tree->head != NULL);
    assert(tree->head->node_val == 20);
    assert(tree->head->left->node_val == 10);
    assert(tree->head->right->node_val == 30);
    assert(tree->n_nodes == 3);

    // Test with NULL inputs
    assert(add_tree_node(NULL, &values[0], sample_eval_func) == -1);
    assert(add_tree_node(tree, NULL, sample_eval_func) == -1);
    assert(add_tree_node(tree, &values[0], NULL) == -1);

    destroy_tree(tree);
    printf("test_add_tree_node passed\n");
}

void test_get_tree_node() {
    BinaryTree* tree = create_tree();
    long long values[] = {20, 10, 30};

    for (int i = 0; i < 3; i++) {
        add_tree_node(tree, &values[i], sample_eval_func);
    }

    // Test getting nodes by value
    assert(get_tree_node(tree, 20) == &values[0]);
    assert(get_tree_node(tree, 10) == &values[1]);
    assert(get_tree_node(tree, 30) == &values[2]);

    // Test non-existent value
    assert(get_tree_node(tree, 40) == NULL);

    // Test with NULL tree
    assert(get_tree_node(NULL, 20) == NULL);

    destroy_tree(tree);
    printf("test_get_tree_node passed\n");
}

void runtreetests() {
    printf("----------STARTING BINARY TREE TESTS----------\n");
    test_create_tree();
    test_destroy_tree();
    test_add_tree_node();
    test_get_tree_node();
    printf("---------FINISHING BINARY TREE TESTS----------\n");
}

#endif // ARIA_DATA_STRUCTURES_TEST_TREE
