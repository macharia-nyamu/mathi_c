/*
* Mathi C Library - Core Data Structures
* Linked List, Stack, Queue, Hash Table
*
* Copyright (c) 2025 Macharia Nyamū
* Licensed under the MIT License. See LICENSE file for details.
*/

#ifndef MATHI_DS_H
#define MATHI_DS_H

#include <stddef.h>  // For size_t

/**
 * @file mathi/ds.h
 * @brief Provides core data structures for C: linked lists, stacks, queues, and hash tables.
 *
 * All structures are dynamically allocated where appropriate.
 * Functions that return pointers to dynamically allocated memory
 * require the caller to free the memory after use.
 */


/**
 * @struct Node
 * @brief Node for a singly linked list of integers.
 */
typedef struct Node {
    int v;              ///< Value stored in the node
    struct Node *next;  ///< Pointer to the next node
} Node;

/**
 * @brief Create a new linked list node.
 * @param v Value to store
 * @return Pointer to newly allocated Node
 */
Node* mathi_list_new(int v);

/**
 * @brief Append a value to the end of the linked list.
 * @param head Pointer to the head node pointer
 * @param value Value to add
 */
void mathi_linked_list_add(Node **head, int value);

/**
 * @brief Remove the first occurrence of a value from the linked list.
 * @param head Pointer to the head node pointer
 * @param value Value to remove
 */
void mathi_linked_list_remove(Node **head, int value);

/**
 * @brief Count the number of nodes in the linked list.
 * @param head Pointer to head node
 * @return Number of nodes
 */
int mathi_linked_list_length(Node *head);

/**
 * @brief Find the first node containing the specified value.
 * @param head Pointer to head node
 * @param value Value to search for
 * @return Pointer to Node if found, NULL otherwise
 */
Node* mathi_linked_list_find(Node *head, int value);

/**
 * @brief Print all values in the linked list to stdout.
 * @param head Pointer to head node
 */
void mathi_linked_list_print(Node *head);

/* Aliases for convenience */
#define mathi_list_length mathi_linked_list_length
#define mathi_list_find   mathi_linked_list_find


/**
 * @struct Stack
 * @brief Simple dynamic integer stack.
 */
typedef struct Stack {
    int *d; ///< Array holding elements
    int t;  ///< Index of the top element (-1 if empty)
    int n;  ///< Maximum capacity
} Stack;

/**
 * @brief Create a new stack.
 * @param n Capacity of the stack
 * @return Pointer to new Stack
 */
Stack* mathi_stack_new(int n);

/**
 * @brief Push a value onto the stack.
 * @param s Stack pointer
 * @param v Value to push
 */
void mathi_stack_push(Stack *s, int v);

/**
 * @brief Pop a value from the stack.
 * @param s Stack pointer
 * @return Value popped (0 if empty)
 */
int mathi_stack_pop(Stack *s);

/**
 * @brief Peek at the top value of the stack without removing it.
 * @param s Stack pointer
 * @return Top value (0 if empty)
 */
int mathi_stack_peek(Stack *s);

/**
 * @brief Check if the stack is empty.
 * @param s Stack pointer
 * @return 1 if empty, 0 otherwise
 */
int mathi_stack_is_empty(Stack *s);

/**
 * @brief Free all memory associated with the stack.
 * @param s Stack pointer
 */
void mathi_stack_free(Stack *s);


/**
 * @struct Queue
 * @brief Circular integer queue implementation.
 */
typedef struct Queue {
    int *d; ///< Array holding elements
    int f;  ///< Index of front element
    int r;  ///< Index of rear element
    int c;  ///< Current size
    int n;  ///< Maximum capacity
} Queue;

/**
 * @brief Create a new queue.
 * @param n Capacity of the queue
 * @return Pointer to new Queue
 */
Queue* mathi_queue_new(int n);

/**
 * @brief Enqueue a value to the rear of the queue.
 * @param q Queue pointer
 * @param v Value to enqueue
 */
void mathi_queue_enqueue(Queue *q, int v);

/**
 * @brief Dequeue a value from the front of the queue.
 * @param q Queue pointer
 * @return Value dequeued (0 if empty)
 */
int mathi_queue_dequeue(Queue *q);

/**
 * @brief Peek at the front value without removing it.
 * @param q Queue pointer
 * @return Front value (0 if empty)
 */
int mathi_queue_peek(Queue *q);

/**
 * @brief Check if the queue is empty.
 * @param q Queue pointer
 * @return 1 if empty, 0 otherwise
 */
int mathi_queue_is_empty(Queue *q);

/**
 * @brief Free all memory associated with the queue.
 * @param q Queue pointer
 */
void mathi_queue_free(Queue *q);


/**
 * @struct Pair
 * @brief Key-value pair stored in a hash table.
 */
typedef struct {
    char *key; ///< Dynamically allocated string key
    int val;   ///< Associated integer value
} Pair;

/**
 * @struct Hash
 * @brief Simple open-addressing hash table for integer values.
 */
typedef struct {
    Pair *tab; ///< Array of key-value pairs
    int n;     ///< Size of the table
} Hash;

/**
 * @brief Create a new hash table.
 * @param n Number of buckets
 * @return Pointer to new Hash
 */
Hash* mathi_hash_new(int n);

/**
 * @brief Set a key-value pair in the hash table.
 * @param h Hash pointer
 * @param k Key string
 * @param v Value
 */
void mathi_hash_set(Hash *h, const char *k, int v);

/**
 * @brief Get the value associated with a key.
 * @param h Hash pointer
 * @param k Key string
 * @return Value if found, 0 otherwise
 */
int  mathi_hash_get(Hash *h, const char *k);

/**
 * @brief Free all memory associated with the hash table.
 * @param h Hash pointer
 */
void mathi_hash_free(Hash *h);

#endif // MATHI_DS_H