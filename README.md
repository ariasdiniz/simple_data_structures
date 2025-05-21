#Data Structures

## Overview
Data Structures is a C library providing efficient implementations of common data structures, accessible via a single header file `datastructures.h`. This library was created for educational purposes. Do not use it in production code.

## Features
- **Hash Table**: Efficient key-value storage.
- **Linked List**: Dynamic linear data storage.
- **Queue**: FIFO (First-In-First-Out) data structure.
- **Stack**: LIFO (Last-In-First-Out) data structure.
- **Graph**: Simple graph data structure.

## Getting Started
### Prerequisites
- A C compiler (e.g., GCC, Clang).

### Installation
1. Clone or download this repository.
2. Include `datastructures.h` in your C project.

OR

1. Clone or download this repository.
2. Run the `install` script.
3. Include and link the library in your C project.

### Usage Examples
#### Hash Table
```c
#include "datastructures.h"

// Creating a hash table
HashTable *myHash = createhash();
// Adding key-value pairs
addtohash(myHash, "key1", "value1");
addtohash(myHash, "key2", "value2");
// Retrieving a value
char *value = getfromhash(myHash, "key1");
// Deleting the hash table
deletehash(myHash);
```

#### Linked List
```c
#include "datastructures.h"

// Creating a linked list
struct LinkedList *myList = createlist();
// Adding elements
addtolist(myList, "data1");
addtolist(myList, "data2");
// Getting an element
char *data = getfromindex(myList, 1);
// Deleting the linked list
deletelist(myList);
```

#### Queue
```c
#include "datastructures.h"

// Creating a queue
struct Queue *myQueue = createqueue();
// Adding elements
addtoqueue(myQueue, "item1");
addtoqueue(myQueue, "item2");
// Removing an element
char *item = popfromqueue(myQueue);
// Deleting the queue
deletequeue(myQueue);
```

#### Stack
```c
#include "datastructures.h"

// Creating a stack
struct Stack *myStack = createstack();
// Adding elements
addtostack(myStack, "element1");
addtostack(myStack, "element2");
// Removing an element
char *element = popfromstack(myStack);
// Deleting the stack
deletestack(myStack);
```

#### Graph
```c
#include "datastructures.h"

// Creating a graph
graph *myGraph = create_graph();
// Adding vertices
int vertex1_id = add_vertex(myGraph, "value1");
int vertex2_id = add_vertex(myGraph, "value2");
// Adding edges
add_edge(myGraph, vertex1_id, vertex2_id);
// Get the value from the vertex
get_vertex(my_graph, vertex1_id) // Returns "value1"
// Printing the adjacency list
print_edges(myGraph);
// Deleting the graph
delete_graph(myGraph);
```

## API Reference
### Hash Table
- `HashTable *createhash()`: Creates a new HashTable.
- `int deletehash(HashTable *hash)`: Deletes a HashTable.
- `int addtohash(HashTable *hash, char *key, void *value)`: Adds a key-value pair to HashTable.
- `int updatehashitem(HashTable *hash, char *key, voud *new_value)`: Update a value of a key in the HashTable
- `char *getfromhash(HashTable *hash, char *key)`: Retrieves value for a given key from HashTable.

### Linked List
- `struct LinkedList *createlist()`: Creates a new LinkedList.
- `int deletelist(struct LinkedList *list)`: Deletes a LinkedList.
- `int addtolist(struct LinkedList *list, void *value)`: Adds a new element to LinkedList.
- `void *getfromindex(struct LinkedList *list, int index)`: Gets a value from LinkedList by index.

### Queue
- `struct Queue *createqueue()`: Creates a new Queue.
- `int deletequeue(struct Queue *queue)`: Deletes a Queue.
- `int addtoqueue(struct Queue *queue, void *value)`: Adds a new element to Queue.
- `void *popfromqueue(struct Queue *queue)`: Removes and returns the first element of Queue.

### Stack
- `struct Stack *createstack()`: Creates a new Stack.
- `int deletestack(struct Stack *stack)`: Deletes a Stack.
- `int addtostack(struct Stack *stack, void *value)`: Adds a new element to Stack.
- `void *popfromstack(struct Stack *stack)`: Removes and returns the top element of Stack.

### Graph
- `graph *create_graph()`: Creates a new graph.
- `int add_vertex(graph *graph, void *value)`: Adds a vertex to the graph.
- `int add_edge(graph *graph, int id_v1, int id_v2)`: Adds an undirected edge between two vertices in the graph.
- `void print_edges(graph *graph)`: Prints the adjacency list representation of the graph.
- `void *get_vertex(graph *graph, int id)`: Get the value in the vertex with the specified ID.
- `int delete_graph(graph *graph)`: Deletes the graph and frees allocated memory.