/**
 * Mathi C Library - Data Structures
 * 
 * This header provides common data structures including linked lists,
 * stacks, queues, and hash tables, along with their associated operations.
 * 
 * @file ds.h
 * @author Macharia Nyamū
 * @date 2025
 * @license MIT
 * 
 * Licensed under the MIT License. You may obtain a copy of the License at
 * https://opensource.org/licenses/MIT
 */

#ifndef MATHI_DS_H
#define MATHI_DS_H

/** Linked List Node */
typedef struct Node {
    int v;             /**< Value stored in the node */
    struct Node *next; /**< Pointer to the next node */
} Node;

/** Stack structure */
typedef struct Stack {
    int *d; /**< Array holding stack elements */
    int t;  /**< Top index */
    int n;  /**< Maximum size */
} Stack;

/** Queue structure */
typedef struct Queue {
    int *d; /**< Array holding queue elements */
    int f;  /**< Front index */
    int r;  /**< Rear index */
    int c;  /**< Current count */
    int n;  /**< Maximum size */
} Queue;

/** Key-value pair for hash table */
typedef struct Pair {
    char *key; /**< Key string */
    int val;   /**< Associated value */
} Pair;

/** Hash table structure */
typedef struct Hash {
    Pair *tab; /**< Array of key-value pairs */
    int n;     /**< Number of slots */
} Hash;

/* --- Linked List Functions --- */
Node* list_new(int v);
void linked_list_add(Node **head, int value);
void linked_list_remove(Node **head, int value);
int linked_list_length(Node *head);
Node* linked_list_find(Node *head, int value);
void linked_list_print(Node *head);
int list_length(Node *head);
Node* list_find(Node *head, int value);

/* --- Stack Functions --- */
Stack* stack_new(int n);
void stack_push(Stack *s, int value);
int stack_pop(Stack *s);
int stack_peek(Stack *s);
int stack_is_empty(Stack *s);
void stack_free(Stack *s);

/* --- Queue Functions --- */
Queue* queue_new(int n);
void queue_enqueue(Queue *q, int value);
int queue_dequeue(Queue *q);
int queue_peek(Queue *q);
int queue_is_empty(Queue *q);
void queue_free(Queue *q);

/* --- Hash Table Functions --- */
Hash* hash_new(int n);
void hash_free(Hash *h);
void hash_set(Hash *h, const char *k, int v);
int hash_get(Hash *h, const char *k);

#endif