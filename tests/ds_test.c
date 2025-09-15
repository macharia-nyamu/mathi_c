#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <assert.h>
#include "mathi/ds.h"

void print_linked_list(Node *head, const char *name) {
    printf("%s = [", name);
    Node *current = head;
    while(current) {
        printf("%d", current->v);
        if(current->next) printf(", ");
        current = current->next;
    }
    printf("]\n");
}

void test_linked_list() {
    printf("Testing linked list...\n");
    Node *head = NULL;

    linked_list_add(&head, 10);
    linked_list_add(&head, 20);
    linked_list_add(&head, 30);
    print_linked_list(head, "linked list after adds");
    assert(linked_list_length(head) == 3);
    assert(linked_list_find(head, 20)->v == 20);

    linked_list_remove(&head, 20);
    print_linked_list(head, "linked list after removing 20");
    assert(linked_list_length(head) == 2);
    assert(linked_list_find(head, 20) == NULL);

    linked_list_remove(&head, 10);
    linked_list_remove(&head, 30);
    print_linked_list(head, "linked list after removing all");
    assert(linked_list_length(head) == 0);
}

void test_stack() {
    printf("Testing stack...\n");
    Stack *s = stack_new(3);
    printf("stack is empty? %d\n", stack_is_empty(s));

    stack_push(s, 1);
    stack_push(s, 2);
    stack_push(s, 3);
    printf("stack after pushes: top = %d\n", stack_peek(s));

    stack_push(s, 4); // should not push
    printf("stack after trying to push 4: top = %d\n", stack_peek(s));

    int val = stack_pop(s);
    printf("popped value = %d, new top = %d\n", val, stack_peek(s));
    assert(val == 3);

    assert(stack_peek(s) == 2);
    assert(!stack_is_empty(s));

    stack_pop(s);
    stack_pop(s);
    printf("stack after popping all: is empty? %d\n", stack_is_empty(s));
    assert(stack_is_empty(s));
    stack_free(s);
}

void test_queue() {
    printf("Testing queue...\n");
    Queue *q = queue_new(3);
    printf("queue is empty? %d\n", queue_is_empty(q));

    queue_enqueue(q, 1);
    queue_enqueue(q, 2);
    queue_enqueue(q, 3);
    printf("queue after enqueues: front = %d\n", queue_peek(q));

    queue_enqueue(q, 4); // should not enqueue
    printf("queue after trying to enqueue 4: front = %d\n", queue_peek(q));

    int val = queue_dequeue(q);
    printf("dequeued value = %d\n", val);
    val = queue_dequeue(q);
    printf("dequeued value = %d\n", val);
    val = queue_dequeue(q);
    printf("dequeued value = %d\n", val);

    printf("queue is empty? %d\n", queue_is_empty(q));
    assert(queue_is_empty(q));
    queue_free(q);
}

void test_hash_table() {
    printf("Testing hash table...\n");
    Hash *h = hash_new(10);

    hash_set(h, "one", 1);
    hash_set(h, "two", 2);
    hash_set(h, "three", 3);
    printf("hash['one'] = %d\n", hash_get(h, "one"));
    printf("hash['two'] = %d\n", hash_get(h, "two"));
    printf("hash['three'] = %d\n", hash_get(h, "three"));
    printf("hash['missing'] = %d\n", hash_get(h, "missing"));

    // overwrite existing key
    hash_set(h, "two", 20);
    printf("hash['two'] after overwrite = %d\n", hash_get(h, "two"));
    hash_free(h);
}

int main() {
    test_linked_list();
    test_stack();
    test_queue();
    test_hash_table();

    printf("All ds tests passed successfully!\n");
    return 0;
}