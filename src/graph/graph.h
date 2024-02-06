#ifndef ARIA_DATA_STRUCTURES_GRAPH_H
#define ARIA_DATA_STRUCTURES_GRAPH_H

#include "../linkedlist/list.h"

typedef struct {
  LinkedList *vertexes;
} graph;

graph *create_graph();
int add_vertex(graph *graph, void *value);
int add_edge(graph *graph, int id_v1, int id_v2);
void print_edge_single_vertex(graph *graph, int id);
void print_edges(graph *graph);
int delete_graph(graph *graph);

#endif // ARIA_DATA_STRUCTURES_GRAPH_H