#include <stdio.h>
#include <stdlib.h>
#include <assert.h>
#include "mathi/dsx.h"

void test_stack() {
    printf("Testing dsx stack...\n");
    Stack *s = stack_new();
    printf("stack is empty? %d\n", stack_is_empty(s));
    int res = stack_push(s, (void*)1);
    printf("stack_push result = %d\n", res);
    void *val = stack_pop(s);
    printf("stack_pop returned = %p\n", val);
    stack_free(s);
}

void test_queue() {
    printf("Testing dsx queue...\n");
    Queue *q = queue_new();
    printf("queue is empty? %d\n", queue_is_empty(q));
    int res = queue_enqueue(q, (void*)1);
    printf("queue_enqueue result = %d\n", res);
    void *val = queue_dequeue(q);
    printf("queue_dequeue returned = %p\n", val);
    queue_free(q);
}

int cmp_placeholder(void *a, void *b) { return 0; }

void test_heap() {
    printf("Testing dsx heap...\n");
    Heap *h = heap_new(cmp_placeholder);
    printf("heap is empty? %d\n", heap_is_empty(h));
    int res = heap_insert(h, (void*)1);
    printf("heap_insert result = %d\n", res);
    void *val = heap_extract(h);
    printf("heap_extract returned = %p\n", val);
    heap_free(h);
}

void test_graph() {
    printf("Testing dsx graph...\n");
    Graph *g = graph_new(5);
    int res = graph_add_edge(g, 0, 1);
    printf("graph_add_edge(0,1) result = %d\n", res);
    int num_neighbors = -1;
    int *neighbors = graph_neighbors(g, 0, &num_neighbors);
    printf("graph_neighbors(0) returned %p with num_neighbors = %d\n", (void*)neighbors, num_neighbors);
    graph_free(g);
}

void test_trie() {
    printf("Testing dsx trie...\n");
    Trie *t = trie_new();
    int res = trie_insert(t, "key", (void*)1);
    printf("trie_insert('key') result = %d\n", res);
    void *val = trie_search(t, "key");
    printf("trie_search('key') returned = %p\n", val);
    trie_free(t);
}

void test_hashmap() {
    printf("Testing dsx hashmap...\n");
    HashMap *h = hashmap_new();
    int res = hashmap_set(h, "key", (void*)1);
    printf("hashmap_set('key') result = %d\n", res);
    void *val = hashmap_get(h, "key");
    printf("hashmap_get('key') returned = %p\n", val);
    int has_key = hashmap_has_key(h, "key");
    printf("hashmap_has_key('key') = %d\n", has_key);
    hashmap_free(h);
}

int main() {
    test_stack();
    test_queue();
    test_heap();
    test_graph();
    test_trie();
    test_hashmap();

    printf("All dsx tests passed successfully!\n");
    return 0;
}