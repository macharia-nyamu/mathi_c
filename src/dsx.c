/*
* Mathi C Library
* Copyright (c) 2025 Macharia Nyamū
* Licensed under the MIT License. See LICENSE file in the project root for details.
*/

#include "mathi/dsx.h"
#include <stdlib.h>

/* Placeholder structs */
struct Stack { void **items; size_t size; size_t capacity; };
struct Queue { void **items; size_t size; size_t capacity; };
struct Heap { void **items; size_t size; int (*cmp)(void*,void*); };
struct Graph { int vertices; int **edges; };
struct Trie {};
struct HashMap {};

/* Stack */
Stack* stack_new() { return calloc(1, sizeof(Stack)); }
int stack_push(Stack *s, void *item) { return 0; }
void* stack_pop(Stack *s) { return NULL; }
int stack_is_empty(Stack *s) { return 1; }
void stack_free(Stack *s) { free(s); }

/* Queue */
Queue* queue_new() { return calloc(1, sizeof(Queue)); }
int queue_enqueue(Queue *q, void *item) { return 0; }
void* queue_dequeue(Queue *q) { return NULL; }
int queue_is_empty(Queue *q) { return 1; }
void queue_free(Queue *q) { free(q); }

/* Heap */
Heap* heap_new(int (*cmp)(void*,void*)) { Heap *h = calloc(1,sizeof(Heap)); h->cmp=cmp; return h; }
int heap_insert(Heap *h, void *item) { return 0; }
void* heap_extract(Heap *h) { return NULL; }
int heap_is_empty(Heap *h) { return 1; }
void heap_free(Heap *h) { free(h); }

/* Graph */
Graph* graph_new(int vertices) { return calloc(1,sizeof(Graph)); }
int graph_add_edge(Graph *g, int src, int dest) { return 0; }
int* graph_neighbors(Graph *g, int vertex, int *num_neighbors) { *num_neighbors=0; return NULL; }
void graph_free(Graph *g) { free(g); }

/* Trie */
Trie* trie_new() { return calloc(1,sizeof(Trie)); }
int trie_insert(Trie *t, const char *key, void *value) { return 0; }
void* trie_search(Trie *t, const char *key) { return NULL; }
void trie_free(Trie *t) { free(t); }

/* HashMap */
HashMap* hashmap_new() { return calloc(1,sizeof(HashMap)); }
int hashmap_set(HashMap *h, const char *key, void *value) { return 0; }
void* hashmap_get(HashMap *h, const char *key) { return NULL; }
int hashmap_has_key(HashMap *h, const char *key) { return 0; }
void hashmap_free(HashMap *h) { free(h); }