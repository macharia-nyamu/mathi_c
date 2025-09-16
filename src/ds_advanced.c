/*
 * Mathi C Library - Advanced Data Structures Implementation
 * DS Advanced (Heap, Graph, Trie)
 *
 * Copyright (c) 2025 Macharia Nyamū
 * Licensed under the MIT License. See LICENSE file for details.
 */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "mathi/ds.h"
#include "mathi/ds_advanced.h"


struct Heap 
{
    void **items;           // array of heap items
    int size;               // current number of items
    int capacity;           // allocated capacity
    int (*cmp)(void*, void*);// comparison function (min-heap)
};

// create new heap
Heap* mathi_heap_new(int (*cmp)(void*, void*)) 
{
    if (!cmp) return NULL;

    Heap *h = malloc(sizeof(Heap));
    if (!h) return NULL;

    h->capacity = 16;
    h->size = 0;
    h->cmp = cmp;
    h->items = malloc(sizeof(void*) * h->capacity);
    if (!h->items) 
    {
        free(h);
        return NULL;
    }
    return h;
}

// swap two heap items
static void heap_swap(void **a, void **b) 
{
    void *tmp = *a;
    *a = *b;
    *b = tmp;
}

// move item up to maintain heap property
static void heapify_up(Heap *h, int index) 
{
    if (index == 0) return;
    int parent = (index - 1) / 2;
    if (h->cmp(h->items[index], h->items[parent]) < 0) 
    {
        heap_swap(&h->items[index], &h->items[parent]);
        heapify_up(h, parent);
    }
}

// move item down to maintain heap property
static void heapify_down(Heap *h, int index) 
{
    int left = 2 * index + 1;
    int right = 2 * index + 2;
    int smallest = index;

    if (left < h->size && h->cmp(h->items[left], h->items[smallest]) < 0) 
        smallest = left;
    if (right < h->size && h->cmp(h->items[right], h->items[smallest]) < 0) 
        smallest = right;

    if (smallest != index) 
    {
        heap_swap(&h->items[index], &h->items[smallest]);
        heapify_down(h, smallest);
    }
}

// insert new item into heap
int mathi_heap_insert(Heap *h, void *item) 
{
    if (!h || !item) return 1;

    if (h->size >= h->capacity) 
    {
        void **tmp = realloc(h->items, sizeof(void*) * h->capacity * 2);
        if (!tmp) return 1;
        h->items = tmp;
        h->capacity *= 2;
    }

    h->items[h->size] = item;
    heapify_up(h, h->size);
    h->size++;
    return 0;
}

// extract top item from heap
void* mathi_heap_extract(Heap *h) 
{
    if (!h || h->size == 0) return NULL;

    void *top = h->items[0];
    h->size--;
    if (h->size > 0) 
    {
        h->items[0] = h->items[h->size];
        heapify_down(h, 0);
    }
    return top;
}

int mathi_heap_is_empty(Heap *h) 
{
    return (!h || h->size == 0);
}

void mathi_heap_free(Heap *h) 
{
    if (!h) return;
    free(h->items);
    free(h);
}

struct Graph 
{
    int vertices;
    Node **adj_lists; // adjacency list array
};

// create graph with given number of vertices
Graph* mathi_graph_new(int vertices) 
{
    if (vertices <= 0) return NULL;

    Graph *g = malloc(sizeof(Graph));
    if (!g) return NULL;

    g->vertices = vertices;
    g->adj_lists = malloc(sizeof(Node*) * vertices);
    if (!g->adj_lists) 
    {
        free(g);
        return NULL;
    }

    for (int i = 0; i < vertices; i++) 
        g->adj_lists[i] = NULL;

    return g;
}

// add directed edge src -> dest
int mathi_graph_add_edge(Graph *g, int src, int dest) 
{
    if (!g || src < 0 || src >= g->vertices || dest < 0 || dest >= g->vertices) 
        return 2;

    mathi_linked_list_add(&g->adj_lists[src], dest);
    return 0;
}

// get neighbors of a vertex as an array
int* mathi_graph_neighbors(Graph *g, int vertex, int *num_neighbors) 
{
    if (!g || vertex < 0 || vertex >= g->vertices || !num_neighbors) 
        return NULL;

    Node *head = g->adj_lists[vertex];
    *num_neighbors = mathi_linked_list_length(head);
    if (*num_neighbors == 0) return NULL;

    int *arr = malloc(sizeof(int) * (*num_neighbors));
    Node *cur = head;
    for (int i = 0; i < *num_neighbors; i++) 
    {
        arr[i] = cur->v;
        cur = cur->next;
    }
    return arr;
}

// free graph memory
void mathi_graph_free(Graph *g) 
{
    if (!g) return;
    for (int i = 0; i < g->vertices; i++) 
    {
        Node *cur = g->adj_lists[i];
        while (cur) 
        {
            Node *tmp = cur;
            cur = cur->next;
            free(tmp);
        }
    }
    free(g->adj_lists);
    free(g);
}

struct TrieNode 
{
    char *key;               // stored key at node
    void *value;             // associated value
    struct TrieNode *children[256]; // all possible ASCII children
};

struct Trie 
{
    struct TrieNode *root;
};

// create new trie node
static struct TrieNode* trie_node_new() 
{
    struct TrieNode *node = calloc(1, sizeof(struct TrieNode));
    return node;
}

// create new trie
Trie* mathi_trie_new() 
{
    Trie *t = malloc(sizeof(Trie));
    if (!t) return NULL;
    t->root = trie_node_new();
    return t;
}

// insert key-value into trie
int mathi_trie_insert(Trie *t, const char *key, void *value) 
{
    if (!t || !key) return 1;

    struct TrieNode *cur = t->root;
    for (size_t i = 0; key[i]; i++) 
    {
        unsigned char c = key[i];
        if (!cur->children[c]) 
            cur->children[c] = trie_node_new();
        cur = cur->children[c];
    }

    cur->key = strdup(key); // store full key at leaf
    cur->value = value;
    return 0;
}

// search key in trie, return value or NULL
void* mathi_trie_search(Trie *t, const char *key) 
{
    if (!t || !key) return NULL;

    struct TrieNode *cur = t->root;
    for (size_t i = 0; key[i]; i++) 
    {
        unsigned char c = key[i];
        if (!cur->children[c]) return NULL;
        cur = cur->children[c];
    }
    return cur->value;
}

// recursively free trie node
static void trie_node_free(struct TrieNode *node) 
{
    if (!node) return;
    for (int i = 0; i < 256; i++) 
        trie_node_free(node->children[i]);
    free(node->key);
    free(node);
}

// free entire trie
void mathi_trie_free(Trie *t) 
{
    if (!t) return;
    trie_node_free(t->root);
    free(t);
}