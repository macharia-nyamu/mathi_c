#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <assert.h>
#include "mathi/ds.h"
#include "mathi/print.h"

void test_linked_list_add() 
{
    printf("Testing linked_list_add...\n");

    Node *head = NULL;
    mathi_linked_list_add(&head, 10);
    mathi_linked_list_add(&head, 20);
    mathi_linked_list_add(&head, 30);

    mathi_prnt_linked_list(head, "After adding 10, 20, 30");
    assert(mathi_linked_list_length(head) == 3);
}

void test_linked_list_find() 
{
    printf("Testing linked_list_find...\n");

    Node *head = NULL;
    mathi_linked_list_add(&head, 100);
    mathi_linked_list_add(&head, 200);

    Node *found = mathi_linked_list_find(head, 200);
    assert(found && found->v == 200);
    printf("Found node with value 200: %p -> %d\n\n", (void*)found, found->v);
}

void test_linked_list_remove() 
{
    printf("Testing linked_list_remove...\n");

    Node *head = NULL;
    mathi_linked_list_add(&head, 1);
    mathi_linked_list_add(&head, 2);
    mathi_linked_list_add(&head, 3);

    mathi_linked_list_remove(&head, 2);
    mathi_prnt_linked_list(head, "After removing 2");
    assert(mathi_linked_list_find(head, 2) == NULL);

    mathi_linked_list_remove(&head, 1);
    mathi_linked_list_remove(&head, 3);
    mathi_prnt_linked_list(head, "After removing all");
    assert(mathi_linked_list_length(head) == 0);
}

void test_stack_operations() 
{
    printf("Testing Stack Operations...\n");

    Stack *s = mathi_stack_new(3);
    printf("New stack created, is_empty = %d\n", mathi_stack_is_empty(s));

    mathi_stack_push(s, 5);
    mathi_stack_push(s, 10);
    mathi_stack_push(s, 15);
    printf("After pushes: top = %d\n", mathi_stack_peek(s));

    mathi_stack_push(s, 20);
    printf("After attempting to push 20 (overflow): top = %d\n", mathi_stack_peek(s));

    int val = mathi_stack_pop(s);
    printf("Pop returned: %d, new top = %d\n", val, mathi_stack_peek(s));
    assert(val == 15);
    assert(mathi_stack_peek(s) == 10);

    mathi_stack_pop(s);
    mathi_stack_pop(s);
    printf("After popping all: is_empty = %d\n\n", mathi_stack_is_empty(s));

    mathi_stack_free(s);
}

void test_queue_operations() 
{
    printf("Testing Queue Operations...\n");

    Queue *q = mathi_queue_new(3);
    int val;
    printf("New queue created, is_empty = %d\n", mathi_queue_is_empty(q));

    mathi_queue_enqueue(q, 1);
    mathi_queue_enqueue(q, 2);
    mathi_queue_enqueue(q, 3);
    printf("After enqueues: front = %d\n", mathi_queue_peek(q));

    mathi_queue_enqueue(q, 4);
    printf("After attempting to enqueue 4 (overflow): front = %d\n", mathi_queue_peek(q));

    val = mathi_queue_dequeue(q);
    printf("Dequeue returned: %d\n", val);
    val = mathi_queue_dequeue(q);
    printf("Dequeue returned: %d\n", val);
    val = mathi_queue_dequeue(q);
    printf("Dequeue returned: %d\n", val);

    printf("After dequeueing all: is_empty = %d\n\n", mathi_queue_is_empty(q));
    mathi_queue_free(q);
}

void test_hash_table_operations() 
{
    printf("Testing Hash Table Operations...\n");

    Hash *h = mathi_hash_new(5);

    mathi_hash_set(h, "a", 1);
    mathi_hash_set(h, "b", 2);
    mathi_hash_set(h, "c", 3);

    printf("hash['a'] = %d\n", mathi_hash_get(h, "a"));
    printf("hash['b'] = %d\n", mathi_hash_get(h, "b"));
    printf("hash['c'] = %d\n", mathi_hash_get(h, "c"));
    printf("hash['missing'] = %d\n", mathi_hash_get(h, "missing"));

    mathi_hash_set(h, "b", 20);
    printf("hash['b'] after overwrite = %d\n\n", mathi_hash_get(h, "b"));

    mathi_hash_free(h);
}

void test_list_length_and_find() 
{
    printf("Testing list_length and list_find aliases...\n");

    Node *head = NULL;
    mathi_linked_list_add(&head, 7);
    mathi_linked_list_add(&head, 14);

    assert(mathi_list_length(head) == 2);
    Node *found = mathi_list_find(head, 14);
    assert(found && found->v == 14);
    printf("list_length = %d, list_find found: %d\n\n", mathi_list_length(head), found->v);
}

void test_stack_boundaries() 
{
    printf("Testing Stack boundaries...\n");

    Stack *s = mathi_stack_new(2);
    mathi_stack_push(s, 1);
    mathi_stack_push(s, 2);
    mathi_stack_pop(s);
    mathi_stack_pop(s);

    printf("Stack after popping all: is_empty = %d\n\n", mathi_stack_is_empty(s));
    mathi_stack_free(s);
}

void test_queue_boundaries() 
{
    printf("Testing Queue boundaries...\n");

    Queue *q = mathi_queue_new(2);
    mathi_queue_enqueue(q, 1);
    mathi_queue_enqueue(q, 2);
    mathi_queue_dequeue(q);
    mathi_queue_dequeue(q);

    printf("Queue after dequeueing all: is_empty = %d\n\n", mathi_queue_is_empty(q));
    mathi_queue_free(q);
}

int main() 
{
    test_linked_list_add();
    test_linked_list_find();
    test_linked_list_remove();
    test_list_length_and_find();

    test_stack_operations();
    test_stack_boundaries();

    test_queue_operations();
    test_queue_boundaries();

    test_hash_table_operations();

    printf("All DS tests passed successfully!\n");
    return 0;
}