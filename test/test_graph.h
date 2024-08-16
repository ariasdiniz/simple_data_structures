#include <stdio.h>
#include <stdlib.h>
#include <assert.h>
#include "../datastructures.h"

void test_create_graph() {
    graph *g = create_graph();
    assert(g != NULL);
    assert(g->vertexes != NULL);
    assert(g->vertexes->size == 0);
    printf("test_create_graph passed.\n");
    delete_graph(g);
}

void test_add_vertex() {
    graph *g = create_graph();
    long long id = add_vertex(g, 1);
    assert(id == 0);
    assert(*(int *)get_vertex(g, id) == 1);
    printf("test_add_vertex passed.\n");
    delete_graph(g);
}

void test_add_edge() {
    graph *g = create_graph();
    add_vertex(g, (void *)1);
    add_vertex(g, (void *)2);
    assert(add_edge(g, 0, 1, 1) == 0);
    // test if add edge to two identical ids returns -1
    assert(add_edge(g, 1, 1, 1) == -1);
    long long v1 = (long long)get_vertex(g, 0);
    long long v2 = (long long)get_vertex(g, 1);
    void *v3 = get_vertex(g, 10);
    void *v4 = get_vertex(g, -10);
    assert(v1 == 1);
    assert(v2 == 2);
    assert(v3 ==NULL);
    assert(v4 == NULL);
    printf("test_add_edge passed.\n");
    delete_graph(g);
}

void test_print_edges() {
    graph *g = create_graph();
    add_vertex(g, (void *)1);
    add_vertex(g, (void *)2);
    add_edge(g, 0, 1, 1);
    printf("Printing edges:\n");
    print_edges(g);
    printf("test_print_edges passed.\n");
    delete_graph(g);
}

void rungraphtests() {
    printf("----------STARTING GRAPH TESTS----------\n");
    test_create_graph();
    test_add_vertex();
    test_add_edge();
    test_print_edges();
    printf("----------FINISHING GRAPH TESTS----------\n");
}
