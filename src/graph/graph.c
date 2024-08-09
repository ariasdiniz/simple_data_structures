#include <stdlib.h>
#include <stdio.h>
#include "../../datastructures.h"

/**
 * @brief Prints the adjacent vertices of a single vertex.
 * 
 * Prints the IDs of the vertices adjacent to the given vertex.
 * This method is intended for internal use only.
 * 
 * @param v Pointer to the vertex.
 */
static void print_edge_single_vertex(vertex *v) {
  long long size = v->edges->size;
  long long id;
  edge *temp;
  for (long long i = 0; i < size; i++) {
    temp = (edge *)getfromindex(v->edges, i);
    id = temp->v1 == v ? temp->v2->id : v->id;
    printf("id: %lld | ", id);
  }
}

graph *create_graph() {
  graph *g = malloc(sizeof(graph));
  if (g == NULL) {
    return NULL;
  }
  g->vertexes = createlist();
  g->edges = createlist();

  if (g->vertexes == NULL || g->edges == NULL) {
    return NULL;
  }

  return g;
}

long long add_vertex(graph *graph, void *value) {
  vertex *v = malloc(sizeof(vertex));
  if (v == NULL) {
    return -1;
  }
  v->value = value;
  v->id = graph->vertexes->size;
  v->edges = createlist();
  addtolist(graph->vertexes, v);
  return v->id;
}

long long add_edge(graph *graph, long long id_v1, long long id_v2, float weigth) {
  if (id_v1 == id_v2) {
    return -1; // Self-loop not allowed
  }
  vertex *v1 = (vertex *)getfromindex(graph->vertexes, id_v1);
  vertex *v2 = (vertex *)getfromindex(graph->vertexes, id_v2);

  if (*(long long *)v1 == -1 || *(long long *)v2 == -1) {
    return -1; // Invalid vertex ID
  }

  edge *e = malloc(sizeof(edge));

  if (e == NULL) {
    return -1;
  }

  e->v1 = v1;
  e->v2 = v2;
  e->weigth = weigth;

  addtolist(v1->edges, e);
  addtolist(v2->edges, e);
  addtolist(graph->edges, e);

  return 0;
}

void print_edges(graph *graph) {
  vertex *v;
  for (long long i = 0; i < graph->vertexes->size; i++) {
    v = (vertex *)getfromindex(graph->vertexes, i);
    printf("vertex: %lld | ", v->id);
    print_edge_single_vertex(v);
    printf("\n");
  }
}

void *get_vertex(graph *graph, long long id) {
  if (graph == NULL || id < 0 || id >= graph->vertexes->size) {
    return NULL;
  }
  return ((vertex *)getfromindex(graph->vertexes, id))->value;
}

long long delete_graph(graph *graph) {
  vertex *v;
  edge *e;
  for (long long i = 0; i < graph->vertexes->size; i++) {
    v = (vertex *)getfromindex(graph->vertexes, i);
    deletelist(v->edges);
    free(v);
  }
  for (long long i = 0; i < graph->edges->size; i++) {
    free(getfromindex(graph->edges, i));
  }
  deletelist(graph->vertexes);
  deletelist(graph->edges);
  free(graph);
  return 0;
}
