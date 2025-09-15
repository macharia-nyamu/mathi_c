/**
 * Mathi C Library - Advanced Data Structures (DSX)
 * 
 * This header provides advanced data structures including generic stacks, queues,
 * deques, heaps (priority queues), graphs, tries, and hashmaps.
 * 
 * Status codes:
 * 0 - SUCCESS
 * 1 - MEMORY_ERROR
 * 2 - INDEX_OUT_OF_BOUNDS
 * 3 - KEY_NOT_FOUND
 * 4 - TYPE_MISMATCH
 * 5 - UNKNOWN_ERROR
 * 
 * @file dsx.h
 * @author Macharia Nyamū
 * @date 2025
 * @license MIT
 * 
 * Licensed under the MIT License. You may obtain a copy of the License at
 * https://opensource.org/licenses/MIT
 */

#ifndef MATHI_DSX_H
#define MATHI_DSX_H

#include <stddef.h>
#include <stdbool.h>

/* ----- Stack ----- */
typedef struct Stack Stack;
Stack* stack_new();
int stack_push(Stack *s, void *item);
void* stack_pop(Stack *s);
int stack_is_empty(Stack *s);
void stack_free(Stack *s);

/* ----- Queue / Deque ----- */
typedef struct Queue Queue;
Queue* queue_new();
int queue_enqueue(Queue *q, void *item);
void* queue_dequeue(Queue *q);
int queue_is_empty(Queue *q);
void queue_free(Queue *q);

/* ----- Priority Queue / Heap ----- */
typedef struct Heap Heap;
Heap* heap_new(int (*cmp)(void*,void*));
int heap_insert(Heap *h, void *item);
void* heap_extract(Heap *h);
int heap_is_empty(Heap *h);
void heap_free(Heap *h);

/* ----- Graph ----- */
typedef struct Graph Graph;
Graph* graph_new(int vertices);
int graph_add_edge(Graph *g, int src, int dest);
int* graph_neighbors(Graph *g, int vertex, int *num_neighbors);
void graph_free(Graph *g);

/* ----- Trie ----- */
typedef struct Trie Trie;
Trie* trie_new();
int trie_insert(Trie *t, const char *key, void *value);
void* trie_search(Trie *t, const char *key);
void trie_free(Trie *t);

/* ----- HashMap ----- */
typedef struct HashMap HashMap;
HashMap* hashmap_new();
int hashmap_set(HashMap *h, const char *key, void *value);
void* hashmap_get(HashMap *h, const char *key);
int hashmap_has_key(HashMap *h, const char *key);
void hashmap_free(HashMap *h);

#endif