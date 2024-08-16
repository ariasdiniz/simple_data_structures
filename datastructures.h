#ifndef ARIA_DATA_STRUCTURES_H
#define ARIA_DATA_STRUCTURES_H

// LinkedList

struct Node {
  void *value;
  struct Node *next;
};

typedef struct LinkedList {
  struct Node *head;
  struct Node *tail;
  long long size;
} LinkedList;

/*
  Create a new LinkedList.

  @return struct LinkedList* A pointer to the newly created LinkedList.
  Return NULL on failure to allocate memory.
  Don't forget to free memory after usage with deletelist(list).
*/
struct LinkedList *createlist();

/*
  Free the memory allocated by createlist().

  @param list A pointer to a LinkedList.
  @return void* Returns 0 when successful. -1 when the list param is NULL.
*/
int deletelist(struct LinkedList *list);

/*
  Add a new element at the bottom of the list.

  @param list A pointer to a LinkedList.
  @param value A void pointer to the value to be added to the list.
  @return Returns 0 if successful. Returns -1 when an error occur.
*/
int addtolist(struct LinkedList *list, void *value);

/*
  Gets the value of an specific index in the provided list.

  @param list A pointer to a LinkedList.
  @param index An integer representing the index.
  @returns Returns a pointer to the value of the index. return NULL in case of error.
*/
void *getfromindex(struct LinkedList *list, long long index);

/*
  Remove an index from the provided list.

  @param list A pointer to a LinkedList.
  @param index An integer representing the index to be removed.
  @return Return 0 when successful. return -1 in case of error.
*/
int removefromindex(struct LinkedList *list, long long index);

// ------------------------------------------------
// HashTable

#define ARIA_DATA_STRUCTURES_HASH_MAX_SIZE 1000

typedef struct HashTable {
  LinkedList *bucket[ARIA_DATA_STRUCTURES_HASH_MAX_SIZE];
} HashTable;

/*
  Create a new HashTable and return a pointer to it.
  Don't forget to free it's memory calling deletehash on it
  after usage.
  @return Return a pointer to the newly created HashTable.
  return NULL if memory allocation failed.
*/
HashTable *createhash();

/*
  Safely deletes the HashTable, freeing the memory of all of it's elements.
  @param hash A pointer to a HashTable.
  @return Return 0 if successful. return -1 if hash is NULL.
*/
int deletehash(HashTable *hash);

/*
  Gets a value from a hash using the provided key.
  @param hash A pointer to the HashTable.
  @param key A char pointer representing the key.
  @return Return a pointer to the value. return NULL if hash is NULL
  or if the provided key does not have a value.
*/
void *getfromhash(HashTable *hash, char *key);

/*
  Add a new key-value pair to the HashTable.
  @param hash A pointer to the HashTable.
  @param key A char pointer to the key.
  @param value A pointer to the value.
  @return Return 0 if successful. return -1 if hash is NULL or
  in case of failure of memory allocation.
*/
int addtohash(HashTable *hash, char *key, void *value);

/*
  Update the value of an existing key in the HashTable.
  @param hash A pointer to a HashTable.
  @param key A char pointer to an existing key.
  @param new_value A pointer to the new value.
  @return Return 0 if successfull, -1 the hash is NULL or the key don't exist.
*/
int updatehashitem(HashTable *hash, char *key, void *new_value);

// ------------------------------------------------
// Queue

struct QueueItem {
  void *value;
  struct QueueItem *next;
  struct QueueItem *prev;
};

typedef struct Queue {
  struct QueueItem *first;
  struct QueueItem *last;
  long long size;
} Queue;

/*
  Create a new Queue.

  @return Return a pointer to the newly created Queue.
  Return NULL in case of failure on memory allocation.
  Don't forget to free memory after usage with deletequeue(queue).
*/
struct Queue *createqueue();

/*
  Safely delete the queue freeing the memory.
  If you used this structure to store in the values pointers for
  other manually allocated memory adresses, please free all pointers
  before calling this method.
  @param queue A pointer to a Queue.
  @return Return 0 when successful. return -1 if queue is empty or NULL.
*/
int deletequeue(struct Queue *queue);

/*
  Add a new element to the queue.
  @param queue A pointer to a Queue.
  @param value A pointer to a value to be stored.
  @return Return 0 if successful. return -1 if queue is NULL or empty,
  or in case of error in memory allocation.
*/
int addtoqueue(struct Queue *queue, void *value);

/*
  Removes the first element of the queue and return a pointer to it's value.
  Don't forget to free this pointer afterward, if it polong long to a manually
  allocated memory address.
  @param queue A pointer to a queue.
  @return A pointer to the value stored. return NULL if the queue is empty.
*/
void *popfromqueue(struct Queue *queue);

// --------------------------------------------------
// Stack

struct StackItem {
  void *value;
  struct StackItem *next;
};

/*
  The Stack data structure.
*/
typedef struct Stack {
  struct StackItem *top;
  long long size;
} Stack;


/*
  Create a new Stack.

  @return Return a pointer to the newly created Stack.
  Return NULL in case of error in memory allocation.
  Don't forget to free memory after usage with deletestack(stack).
*/
struct Stack *createstack();

/*
  Safely delete the Stack freeing the memory.
  If you used this structure to store in the values pointers for
  other manually allocated memory adresses, please free all pointers
  before calling this method.
  @param stack A pointer to a Stack.
  @return Return 0 when successful. return -1 if Stack is empty or NULL.
*/
int deletestack(struct Stack *stack);

/*
  Add a new element to the Stack.
  @param stack A pointer to a Stack.
  @param value A pointer to a value to be stored.
  @return Return 0 if successful. return -1 if Stack is NULL or empty,
  or in case of error in memory allocation.
*/
int addtostack(struct Stack *stack, void *value);

/*
  Removes the top element of the Stack and return a pointer to it's value.
  Don't forget to free this pointer afterward, if it polong long to a manually
  allocated memory address.
  @param stack A pointer to a Stack.
  @return A pointer to the value stored. return NULL if the Stack is empty.
*/
void *popfromstack(struct Stack *stack);

// ---------------------------------------------------
// Graph

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

/**
 * @brief Creates a new graph.
 * 
 * Allocates memory for a new graph structure and initializes it with an empty list of vertices.
 * 
 * @return A pointer to the newly created graph, or NULL if memory allocation fails.
 */
graph *create_graph();

/**
 * @brief Adds a vertex to the graph.
 * 
 * Allocates memory for a new vertex, assigns it a unique ID, and adds it to the graph's list of vertices.
 * 
 * @param graph Pointer to the graph structure.
 * @param value Pointer to the value to be stored in the new vertex.
 * @return The ID of the newly added vertex, or -1 if memory allocation fails.
 */
long long add_vertex(graph *graph, void *value);

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
int add_edge(graph *graph, long long id_v1, long long id_v2, float weigth);

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
void *get_vertex(graph *graph, long long id);

/**
 * @brief Prints the adjacency list representation of the graph.
 * 
 * Prints the ID of each vertex followed by the IDs of its adjacent vertices.
 * 
 * @param graph Pointer to the graph structure.
 */
void print_edges(graph *graph);

/**
 * @brief Deletes the graph and frees allocated memory.
 * 
 * Frees memory allocated for each vertex and the graph structure itself.
 * 
 * @param graph Pointer to the graph structure.
 * @return Always returns 0.
 */
int delete_graph(graph *graph);

#endif // ARIA_DATA_STRUCTURES_H
