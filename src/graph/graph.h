#ifndef ARIA_DATA_STRUCTURES_GRAPH_H
#define ARIA_DATA_STRUCTURES_GRAPH_H

#include "../linkedlist/list.h"

/**
 * @brief A simple vertex for the graph data structure
 */
typedef struct {
  long long id;
  void *value;
  LinkedList *edges;
} vertex;

/**
 *@brief A simple edge for the graph data structure
 */
typedef struct {
  float weigth;
  vertex *v1;
  vertex *v2;
} edge;

/**
 *@brief The graph data structure
 */
typedef struct {
  LinkedList *vertexes;
  LinkedList *edges;
} graph;

graph *create_graph();
long long add_vertex(graph *graph, void *value);
long long add_edge(graph *graph, long long id_v1, long long id_v2, float weigth);
void *get_vertex(graph *graph, long long id);
void print_edges(graph *graph);
long long delete_graph(graph *graph);

#endif // ARIA_DATA_STRUCTURES_GRAPH_H