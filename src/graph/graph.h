#ifndef ARIA_DATA_STRUCTURES_GRAPH_H
#define ARIA_DATA_STRUCTURES_GRAPH_H

#include "../linkedlist/list.h"

/**
 *@brief A simple edge for the graph data structure
 */
typedef struct {
  float weigth;
  int v1;
  int v2;
} edge;

/**
 *@brief The graph data structure
 */
typedef struct {
  LinkedList *vertexes;
  LinkedList *edges;
} graph;

graph *create_graph();
int add_vertex(graph *graph, void *value);
int add_edge(graph *graph, int id_v1, int id_v2, float weigth);
void *get_vertex(graph *graph, int id);
void print_edges(graph *graph);
int delete_graph(graph *graph);

#endif // ARIA_DATA_STRUCTURES_GRAPH_H