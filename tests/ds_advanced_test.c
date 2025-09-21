#include <stdio.h>
#include <stdlib.h>
#include <assert.h>
#include "mathi/ds.h"
#include "mathi/ds_advanced.h"

int cmp_placeholder(void *a, void *b) 
{
    return 0; // placeholder comparison for heap
}

void test_heap() 
{
    printf("\nTesting dsx heap\n");

    Heap *h = mathi_heap_new(cmp_placeholder);
    assert(h != NULL);
    printf("heap created successfully\n");

    int res = mathi_heap_insert(h, (void*)1);
    printf("heap_insert result = %d\n", res);
    assert(res == 0);

    res = mathi_heap_insert(h, (void*)2);
    printf("heap_insert result = %d\n", res);
    assert(res == 0);

    void *val = mathi_heap_extract(h);
    printf("heap_extract returned = %p\n", val);
    assert(val != NULL);

    val = mathi_heap_extract(h);
    printf("heap_extract returned = %p\n", val);
    assert(val != NULL);

    printf("heap is empty? %d\n", mathi_heap_is_empty(h));

    mathi_heap_free(h);
    printf("\n");
}

void test_graph() 
{
    printf("\nTesting dsx graph\n");

    Graph *g = mathi_graph_new(5);
    assert(g != NULL);

    int res = mathi_graph_add_edge(g, 0, 1);
    printf("graph_add_edge(0,1) result = %d\n", res);
    assert(res == 0);

    res = mathi_graph_add_edge(g, 1, 2);
    printf("graph_add_edge(1,2) result = %d\n", res);
    assert(res == 0);

    int num_neighbors = 0;
    int *neighbors = mathi_graph_neighbors(g, 0, &num_neighbors);
    printf("graph_neighbors(0) returned %p with num_neighbors = %d\n", (void*)neighbors, num_neighbors);
    assert(neighbors != NULL || num_neighbors == 0);

    neighbors = mathi_graph_neighbors(g, 1, &num_neighbors);
    printf("graph_neighbors(1) returned %p with num_neighbors = %d\n", (void*)neighbors, num_neighbors);
    assert(neighbors != NULL || num_neighbors == 0);

    mathi_graph_free(g);
    printf("\n");
}

void test_trie() 
{
    printf("\nTesting dsx trie\n");

    Trie *t = mathi_trie_new();
    assert(t != NULL);

    int res = mathi_trie_insert(t, "key1", (void*)1);
    printf("trie_insert('key1') result = %d\n", res);
    assert(res == 0);

    res = mathi_trie_insert(t, "key2", (void*)2);
    printf("trie_insert('key2') result = %d\n", res);
    assert(res == 0);

    void *val = mathi_trie_search(t, "key1");
    printf("trie_search('key1') returned = %p\n", val);
    assert(val != NULL);

    val = mathi_trie_search(t, "key2");
    printf("trie_search('key2') returned = %p\n", val);
    assert(val != NULL);

    val = mathi_trie_search(t, "key3"); // not inserted
    printf("trie_search('key3') returned = %p\n", val);
    assert(val == NULL);

    mathi_trie_free(t);
    printf("\n");
}

int main() 
{
    test_heap();
    test_graph();
    test_trie();

    printf("\nAll dsx tests completed successfully!\n");
    return 0;
}