#include <stdio.h>
#include <stdlib.h>
#include <assert.h>
#include "../src/graph/graph.h"

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
    int id = add_vertex(g, (void *)1);
    assert(id == 0);
    assert(g->vertexes->size == 1);
    vertex *v = (vertex *)getfromindex(g->vertexes, 0);
    assert(v->id == 0);
    assert((int)(v->value) == 1);
    printf("test_add_vertex passed.\n");
    delete_graph(g);
}

void test_add_edge() {
    graph *g = create_graph();
    add_vertex(g, (void *)1);
    add_vertex(g, (void *)2);
    assert(add_edge(g, 0, 1) == 0);
    // test if add edge to two identical ids returns -1
    assert(add_edge(g, 1, 1) == -1);
    vertex *v1 = (vertex *)getfromindex(g->vertexes, 0);
    vertex *v2 = (vertex *)getfromindex(g->vertexes, 1);
    assert(v1->edges->size == 1);
    assert(v2->edges->size == 1);
    vertex *edge = (vertex *)getfromindex(v1->edges, 0);
    assert(edge->id == 1);
    printf("test_add_edge passed.\n");
    delete_graph(g);
}

void test_print_edges() {
    graph *g = create_graph();
    add_vertex(g, (void *)1);
    add_vertex(g, (void *)2);
    add_edge(g, 0, 1);
    printf("Printing edges:\n");
    print_edges(g);
    printf("test_print_edges passed.\n");
    delete_graph(g);
}

void rungraphtests() {
    test_create_graph();
    test_add_vertex();
    test_add_edge();
    test_print_edges();
}
