#ifndef ARIA_DATA_STRUCTURES_GRAPH_H
#define ARIA_DATA_STRUCTURES_GRAPH_H

#include "../linkedlist/list.h"

typedef struct {
  LinkedList *vertexes;
} graph;

graph *create_graph();
long long add_vertex(graph *graph, void *value);
long long add_edge(graph *graph, long long id_v1, long long id_v2);
void *get_vertex(graph *graph, long long id);
void print_edges(graph *graph);
long long delete_graph(graph *graph);

#endif // ARIA_DATA_STRUCTURES_GRAPH_H