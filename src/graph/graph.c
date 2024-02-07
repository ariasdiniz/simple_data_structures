/**
 * @file graph.c
 * @brief Implementation of a simple graph data structure.
 */

#include <stdlib.h>
#include <stdio.h>
#include "graph.h"

/**
 * @brief Prints the adjacent vertices of a single vertex.
 * 
 * Prints the IDs of the vertices adjacent to the given vertex.
 * This method is intended for internal use only.
 * 
 * @param v Pointer to the vertex.
 */
static void print_edge_single_vertex(vertex *v) {
  int size = v->edges->size;
  int id;
  edge *temp;
  for (int i = 0; i < size; i++) {
    temp = (edge *)getfromindex(v->edges, i);
    id = temp->v1 == v ? temp->v2->id : v->id;
    printf("id: %d | ", id);
  }
}

/**
 * @brief Creates a new graph.
 * 
 * Allocates memory for a new graph structure and initializes it with an empty list of vertices.
 * 
 * @return A pointer to the newly created graph, or NULL if memory allocation fails.
 */
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

/**
 * @brief Adds a vertex to the graph.
 * 
 * Allocates memory for a new vertex, assigns it a unique ID, and adds it to the graph's list of vertices.
 * 
 * @param graph Pointer to the graph structure.
 * @param value Pointer to the value to be stored in the new vertex.
 * @return The ID of the newly added vertex, or -1 if memory allocation fails.
 */
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

/**
 * @brief Adds an undirected edge between two vertices in the graph.
 * 
 * Adds an edge between two vertices identified by their IDs. The edge is added to both vertices' edge lists.
 * 
 * @param graph Pointer to the graph structure.
 * @param id_v1 ID of the first vertex.
 * @param id_v2 ID of the second vertex.
 * @return 0 if the edge is successfully added, -1 if either vertex ID is invalid or if the edge is a self-loop.
 */
int add_edge(graph *graph, int id_v1, int id_v2, float weigth) {
  if (id_v1 == id_v2) {
    return -1; // Self-loop not allowed
  }
  vertex *v1 = (vertex *)getfromindex(graph->vertexes, id_v1);
  vertex *v2 = (vertex *)getfromindex(graph->vertexes, id_v2);

  if (*(int *)v1 == -1 || *(int *)v2 == -1) {
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

/**
 * @brief Prints the adjacency list representation of the graph.
 * 
 * Prints the ID of each vertex followed by the IDs of its adjacent vertices.
 * 
 * @param graph Pointer to the graph structure.
 */
void print_edges(graph *graph) {
  vertex *v;
  for (int i = 0; i < graph->vertexes->size; i++) {
    v = (vertex *)getfromindex(graph->vertexes, i);
    printf("vertex: %d | ", v->id);
    print_edge_single_vertex(v);
    printf("\n");
  }
}

/**
 * @brief Get the value in the vertex with the specified ID
 *
 *  Return the value of the vertex with the specified ID. Remember
 *  to cast it to the correct type. Return NULL if graph is NULL,
 *  id is lower than 0 or id is greter than the number of vertexes
 *  in the graph.
 *
 *  @param graph A pointer to a graph where the vertex is
 *  @param id The id of the vertex
 */
void *get_vertex(graph *graph, int id) {
  if (graph == NULL || id < 0 || id >= graph->vertexes->size) {
    return NULL;
  }
  return ((vertex *)getfromindex(graph->vertexes, id))->value;
}

/**
 * @brief Deletes the graph and frees allocated memory.
 * 
 * Frees memory allocated for each vertex and the graph structure itself.
 * 
 * @param graph Pointer to the graph structure.
 * @return Always returns 0.
 */
int delete_graph(graph *graph) {
  vertex *v;
  edge *e;
  for (int i = 0; i < graph->vertexes->size; i++) {
    v = (vertex *)getfromindex(graph->vertexes, i);
    deletelist(v->edges);
    free(v);
  }
  for (int i = 0; i < graph->edges->size; i++) {
    free(getfromindex(graph->edges, i));
  }
  deletelist(graph->vertexes);
  deletelist(graph->edges);
  free(graph);
  return 0;
}
