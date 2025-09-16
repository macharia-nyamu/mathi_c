/*
 * Mathi C Library - Advanced Data Structures
 * Copyright (c) 2025 Macharia Nyamū
 * Licensed under the MIT License. See LICENSE file in the project root for details.
 *
 * Linked lists, stacks, queues, and hash tables.
 */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct Node 
{
    int v;
    struct Node *next;
} Node;

/**
 * @brief Create a new node.
 * @param v Value
 * @return Pointer to new node
 */
Node* mathi_list_new(int v)
{
    Node *n = malloc(sizeof(Node));
    n->v = v;
    n->next = NULL;
    return n;
}

/**
 * @brief Add a value to the end of linked list.
 */
void mathi_linked_list_add(Node **head, int value)
{
    Node *n = mathi_list_new(value);
    if (!*head) 
        *head = n;
    else 
    {
        Node *t = *head;
        while (t->next) t = t->next;
        t->next = n;
    }
}

/**
 * @brief Remove first occurrence of a value from linked list.
 */
void mathi_linked_list_remove(Node **head, int value)
{
    Node *t = *head, *prev = NULL;
    while (t) 
    {
        if (t->v == value) 
        {
            if (prev) 
                prev->next = t->next;
            else 
                *head = t->next;
            free(t);
            return;
        }
        prev = t;
        t = t->next;
    }
}

/**
 * @brief Get length of linked list.
 */
int mathi_linked_list_length(Node *head)
{
    int count = 0;
    while (head) 
    {
        count++;
        head = head->next;
    }
    return count;
}

/**
 * @brief Find a node by value.
 */
Node* mathi_linked_list_find(Node *head, int value)
{
    while (head) 
    {
        if (head->v == value) return head;
        head = head->next;
    }
    return NULL;
}

/**
 * @brief Print linked list.
 */
void mathi_linked_list_print(Node *head)
{
    while (head) 
    {
        printf("%d ", head->v);
        head = head->next;
    }
    printf("\n");
}

int mathi_list_length(Node *head) { return mathi_linked_list_length(head); }
Node* mathi_list_find(Node *head, int value) { return mathi_linked_list_find(head, value); }

/* --- Stack --- */
typedef struct Stack 
{
    int *d;
    int t;
    int n;
} Stack;

Stack* mathi_stack_new(int n)
{
    Stack *s = malloc(sizeof(Stack));
    s->d = malloc(n * sizeof(int));
    s->t = -1;
    s->n = n;
    return s;
}

void mathi_stack_push(Stack *s, int v)
{
    if (s->t + 1 < s->n) s->d[++s->t] = v;
}

int mathi_stack_pop(Stack *s)
{
    return (s->t >= 0) ? s->d[s->t--] : 0;
}

int mathi_stack_peek(Stack *s)
{
    return (s->t >= 0) ? s->d[s->t] : 0;
}

int mathi_stack_is_empty(Stack *s)
{
    return s->t < 0;
}

void mathi_stack_free(Stack *s)
{
    free(s->d);
    free(s);
}

/* --- Queue --- */
typedef struct Queue 
{
    int *d;
    int f, r, c, n;
} Queue;

Queue* mathi_queue_new(int n)
{
    Queue *q = malloc(sizeof(Queue));
    q->d = malloc(n * sizeof(int));
    q->f = q->c = 0;
    q->r = -1;
    q->n = n;
    return q;
}

void mathi_queue_enqueue(Queue *q, int v)
{
    if (q->c < q->n) 
    {
        q->r = (q->r + 1) % q->n;
        q->d[q->r] = v;
        q->c++;
    }
}

int mathi_queue_dequeue(Queue *q)
{
    if (!q->c) return 0;
    int v = q->d[q->f];
    q->f = (q->f + 1) % q->n;
    q->c--;
    return v;
}

int mathi_queue_peek(Queue *q)
{
    return q->c ? q->d[q->f] : 0;
}

int mathi_queue_is_empty(Queue *q)
{
    return q->c == 0;
}

void mathi_queue_free(Queue *q)
{
    free(q->d);
    free(q);
}

typedef struct 
{
    char *key;
    int val;
} Pair;

typedef struct 
{
    Pair *tab;
    int n;
} Hash;

static unsigned hash_str(const char *s)
{
    unsigned h = 5381;
    while (*s) h = ((h << 5) + h) + *s++;
    return h;
}

Hash* mathi_hash_new(int n)
{
    Hash *h = malloc(sizeof(Hash));
    h->tab = calloc(n, sizeof(Pair));
    h->n = n;
    return h;
}

void mathi_hash_set(Hash *h, const char *k, int v)
{
    unsigned idx = hash_str(k) % h->n;
    while (h->tab[idx].key && strcmp(h->tab[idx].key, k)) 
        idx = (idx + 1) % h->n;
    
    if (!h->tab[idx].key) 
        h->tab[idx].key = strdup(k);
    
    h->tab[idx].val = v;
}

int mathi_hash_get(Hash *h, const char *k)
{
    unsigned idx = hash_str(k) % h->n;
    while (h->tab[idx].key) 
    { 
        if (!strcmp(h->tab[idx].key, k)) return h->tab[idx].val; 
        idx = (idx + 1) % h->n; 
    }
    return 0;
}

void mathi_hash_free(Hash *h)
{
    for (int i = 0; i < h->n; i++) 
        free(h->tab[i].key);
    free(h->tab);
    free(h);
}