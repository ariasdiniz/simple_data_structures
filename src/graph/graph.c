#include <stdlib.h>
#include <stdio.h>
#include "graph.h"

typedef struct {
  int id;
  void *value;
  LinkedList *edges;
} vertex;

graph *create_graph() {
  graph *g = malloc(sizeof(graph));
  if (g == NULL) {
    return NULL;
  }
  g->vertexes = createlist();
  return g;
}

int add_vertex(graph *graph, void *value) {
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

int add_edge(graph *graph, int id_v1, int id_v2) {
  vertex *v1 = (vertex *)getfromindex(graph->vertexes, id_v1);
  vertex *v2 = (vertex *)getfromindex(graph->vertexes, id_v2);

  if (*(int *)v1 == -1 || *(int *)v2 == -1) {
    return -1;
  }

  addtolist(v1->edges, v2);
  addtolist(v2->edges, v1);

  return 0;
}

void print_edge_single_vertex(vertex *v) {
  int size = v->edges->size;
  vertex *temp;
  for (int i = 0; i < size; i++) {
    temp = (vertex *)getfromindex(v->edges, i);
    printf("id: %d | ", temp->id);
  }
}

void print_edges(graph *graph) {
  vertex *v;
  for (int i = 0; i < graph->vertexes->size; i++) {
    v = (vertex *)getfromindex(graph->vertexes, i);
    printf("vertex: %d | ", v->id);
    print_edge_single_vertex(v);
    printf("\n");
  }
}

int delete_graph(graph *graph) {
  vertex *v;
  for (int i = 0; i < graph->vertexes->size; i++) {
    v = (vertex *)getfromindex(graph->vertexes, i);
    deletelist(v->edges);
    free(v);
  }
  deletelist(graph->vertexes);
  free(graph);
}
