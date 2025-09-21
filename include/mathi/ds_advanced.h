/*
 * Mathi C Library - Advanced Data Structures
 * Heap, Graph, Trie
 *
 * Copyright (c) 2025 Macharia Nyamū
 * Licensed under the MIT License. See LICENSE file for details.
 */

#ifndef MATHI_DS_ADVANCED_H
#define MATHI_DS_ADVANCED_H

#include <stddef.h>   // For size_t
#include "mathi/ds.h" // Basic linked list & stack/queue


/**
 * @struct Heap
 * @brief Opaque structure representing a min/max heap.
 *        Supports dynamic insertion, extraction of top element.
 */
typedef struct Heap Heap;

/**
 * @brief Create a new heap with a custom comparison function.
 * @param cmp Pointer to comparison function (returns <0 if a<b, 0 if equal, >0 if a>b)
 * @return Pointer to Heap, or NULL on failure
 */
Heap* mathi_heap_new(int (*cmp)(void*, void*));

/**
 * @brief Insert an item into the heap.
 * @param h Pointer to Heap
 * @param item Pointer to data
 * @return 0 on success, 1 on failure
 */
int   mathi_heap_insert(Heap *h, void *item);

/**
 * @brief Extract the top element from the heap.
 * @param h Pointer to Heap
 * @return Pointer to top element, or NULL if heap is empty
 */
void* mathi_heap_extract(Heap *h);

/**
 * @brief Check if the heap is empty.
 * @param h Pointer to Heap
 * @return 1 if empty or NULL, 0 otherwise
 */
int   mathi_heap_is_empty(Heap *h);

/**
 * @brief Free all memory associated with the heap.
 * @param h Pointer to Heap
 */
void  mathi_heap_free(Heap *h);



/**
 * @struct Graph
 * @brief Opaque structure for adjacency-list graph.
 *        Supports dynamic edge addition and neighbor queries.
 */
typedef struct Graph Graph;

/**
 * @brief Create a new graph with a fixed number of vertices.
 * @param vertices Number of vertices
 * @return Pointer to Graph, or NULL on failure
 */
Graph* mathi_graph_new(int vertices);

/**
 * @brief Add a directed edge to the graph.
 * @param g Pointer to Graph
 * @param src Source vertex
 * @param dest Destination vertex
 * @return 0 on success, 2 if invalid parameters
 */
int mathi_graph_add_edge(Graph *g, int src, int dest);

/**
 * @brief Retrieve all neighbors of a given vertex.
 * @param g Pointer to Graph
 * @param vertex Vertex index
 * @param num_neighbors Output: number of neighbors
 * @return Pointer to dynamically allocated array of neighbor indices (must free after use)
 */
int* mathi_graph_neighbors(Graph *g, int vertex, int *num_neighbors);

/**
 * @brief Free all memory associated with the graph.
 * @param g Pointer to Graph
 */
void   mathi_graph_free(Graph *g);

/**
 * @struct Trie
 * @brief Opaque structure for a Trie (prefix tree).
 *        Stores arbitrary values with string keys.
 */
typedef struct Trie Trie;

/**
 * @brief Create a new empty Trie.
 * @return Pointer to Trie, or NULL on failure
 */
Trie*  mathi_trie_new(void);

/**
 * @brief Insert a key-value pair into the Trie.
 * @param t Pointer to Trie
 * @param key Null-terminated string key
 * @param value Pointer to value
 * @return 0 on success, 1 on failure
 */
int    mathi_trie_insert(Trie *t, const char *key, void *value);

/**
 * @brief Search for a key in the Trie.
 * @param t Pointer to Trie
 * @param key Null-terminated string key
 * @return Pointer to stored value, or NULL if not found
 */
void*  mathi_trie_search(Trie *t, const char *key);

/**
 * @brief Free all memory associated with the Trie.
 * @param t Pointer to Trie
 */
void   mathi_trie_free(Trie *t);

#endif // MATHI_DS_ADVANCED_H
