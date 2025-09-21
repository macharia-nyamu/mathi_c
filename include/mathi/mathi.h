#ifndef MATHI_H
#define MATHI_H

#include <stddef.h>  // for size_t
#include <stdlib.h>  // for abs()
#include <stdio.h>
#include <stdbool.h>

// --- algo.h ---
/**
 * @brief Compute the n-th Fibonacci number.
 * @param n Index of the Fibonacci sequence (0-based).
 * @return n-th Fibonacci number.
 */
int mathi_fibonacci(int n);

/**
 * @brief Count the occurrences of a value in an integer array.
 * @param arr Array to search.
 * @param n Size of the array.
 * @param value Value to count.
 * @return Number of occurrences of value in arr.
 */
int mathi_occurs(const int *restrict arr, size_t n, int value);

/**
 * @brief Compute factorial of a number iteratively.
 * @param n Non-negative integer.
 * @return Factorial of n, or -1 if n < 0.
 */
int mathi_factorial_iterative(int n);

/**
 * @brief Compute factorial of a number recursively.
 * @param n Non-negative integer.
 * @return Factorial of n, or -1 if n < 0.
 */
int mathi_factorial_recursive(int n);

/**
 * @brief Compute the sum of digits of an integer.
 * @param n Integer value.
 * @return Sum of digits of n.
 */
int mathi_dgts_sum(int n);

/**
 * @brief Compute the root digital (single-digit sum) of an integer.
 * @param n Integer value.
 * @return Root digital of n.
 */
int mathi_rt_digital(int n);

// --- array.h ---
/**
 * @brief Find the index of a value in an array.
 * @param arr Array to search.
 * @param n Size of the array.
 * @param value Value to find.
 * @return Index of value if found, -1 otherwise.
 */
int mathi_arr_index(const int *restrict arr, size_t n, int value);

/**
 * @brief Check if an array contains a value.
 * @param arr Array to search.
 * @param n Size of the array.
 * @param value Value to check.
 * @return 1 if value exists, 0 otherwise.
 */
int mathi_arr_contains(const int *restrict arr, size_t n, int value);

/**
 * @brief Reverse an array in place.
 * @param arr Array to reverse.
 * @param n Size of the array.
 */
void mathi_arr_reverse(int *arr, size_t n);

/**
 * @brief Copy contents from one array to another.
 * @param src Source array.
 * @param dest Destination array.
 * @param n Number of elements to copy.
 */
void mathi_arr_copy(const int *restrict src, int *restrict dest, size_t n);

/**
 * @brief Fill an array with a specific value.
 * @param arr Array to fill.
 * @param n Size of the array.
 * @param value Value to fill.
 */
void mathi_arr_fill(int *arr, size_t n, int value);

/**
 * @brief Compute the sum of elements in an array.
 * @param arr Array to sum.
 * @param n Size of the array.
 * @return Sum of elements.
 */
int mathi_arr_sum(const int *restrict arr, size_t n);

/**
 * @brief Find the maximum value in an array.
 * @param arr Array to search.
 * @param n Size of the array.
 * @return Maximum value, or 0 if n <= 0.
 */
int mathi_arr_max(const int *restrict arr, size_t n);

/**
 * @brief Find the minimum value in an array.
 * @param arr Array to search.
 * @param n Size of the array.
 * @return Minimum value, or 0 if n <= 0.
 */
int mathi_arr_min(const int *restrict arr, size_t n);

/**
 * @brief Compute the average of array elements.
 * @param arr Array to process.
 * @param n Size of the array.
 * @return Average as double, or 0 if n <= 0.
 */
double mathi_arr_average(const int *restrict arr, size_t n);

/**
 * @brief Check if two arrays are equal.
 * @param a First array.
 * @param b Second array.
 * @param n Size of arrays.
 * @return 1 if equal, 0 otherwise.
 */
int mathi_arr_equal(const int *restrict a, const int *restrict b, size_t n);

/**
 * @brief Shuffle an array randomly.
 * @param arr Array to shuffle.
 * @param n Size of the array.
 */
void mathi_arr_shuffle(int *arr, size_t n);

/**
 * @brief Remove duplicate elements from an array.
 * @param arr Array to deduplicate.
 * @param n Pointer to size of array; updated with new size.
 */
void mathi_arr_distinct(int *arr, size_t *n);

/**
 * @brief Rotate array elements k times to the right.
 * @param arr Array to rotate.
 * @param n Size of the array.
 * @param k Number of rotations.
 */
void mathi_arr_rotate(int *arr, size_t n, size_t k);

/**
 * @brief Check if an array is sorted in ascending order.
 * @param arr Array to check.
 * @param n Size of the array.
 * @return 1 if sorted, 0 otherwise.
 */
int mathi_arr_sorted(const int *restrict arr, size_t n);

// --- stringx.h ---
/**
 * @brief Reverse a string in place
 * @param str The string to reverse
 * @return Pointer to the reversed string
 */
char *mathi_string_reverse(char *str);

/**
 * @brief Find the index of a character in a string
 * @param str The string to search
 * @param c The character to find
 * @return Index of character or -1 if not found
 */
int mathi_string_index_of(const char *str, char c);

/**
 * @brief Check if a string contains a character
 * @param str The string to check
 * @param c The character to find
 * @return 1 if found, 0 otherwise
 */
int mathi_string_contains(const char *str, char c);

/**
 * @brief Count occurrences of a character in a string
 * @param str The string to check
 * @param c The character to count
 * @return Number of occurrences
 */
int mathi_string_count_char(const char *str, char c);

/**
 * @brief Convert a string to uppercase in place
 * @param str The string to convert
 * @return Pointer to the converted string
 */
char *mathi_string_to_upper(char *str);

/**
 * @brief Convert a string to lowercase in place
 * @param str The string to convert
 * @return Pointer to the converted string
 */
char *mathi_string_to_lower(char *str);

/**
 * @brief Get the length of a string
 * @param str The string to measure
 * @return Length of the string
 */
int mathi_string_length(const char *str);

/**
 * @brief Concatenate two strings
 * @param dest Destination string (must have enough space)
 * @param src Source string to append
 * @return Pointer to the destination string
 */
char *mathi_string_concat(char *dest, const char *src);

/**
 * @brief Copy a string
 * @param dest Destination string (must have enough space)
 * @param src Source string
 * @return Pointer to the destination string
 */
char *mathi_string_copy(char *dest, const char *src);

/**
 * @brief Compare two strings
 * @param a First string
 * @param b Second string
 * @return 0 if equal, <0 if a<b, >0 if a>b
 */
int mathi_string_compare(const char *a, const char *b);

/**
 * @brief Check if string starts with a prefix
 * @param str String to check
 * @param prefix Prefix to match
 * @return 1 if yes, 0 if no
 */
int mathi_string_starts_with(const char *str, const char *prefix);

/**
 * @brief Check if string ends with a suffix
 * @param str String to check
 * @param suffix Suffix to match
 * @return 1 if yes, 0 if no
 */
int mathi_string_ends_with(const char *str, const char *suffix);

/**
 * @brief Trim leading and trailing whitespace from string
 * @param str String to trim (modified in place)
 * @return Pointer to trimmed string
 */
char *mathi_string_trim(char *str);

/**
 * @brief Replace all occurrences of a character with another
 * @param str String to modify
 * @param old Character to replace
 * @param newc Replacement character
 * @return Pointer to modified string
 */
char *mathi_string_replace(char *str, char old, char newc);

// --- codec.h ---
/**
 * @brief Encode data to Base64.
 * @param data Input byte array.
 * @param len Length of input data.
 * @param out Pointer to output string (allocated inside function).
 * @return 0 on success, 1 on memory error, 2 on invalid input.
 */
int mathi_enc_base64(const unsigned char *restrict data, size_t len, char **out);

/**
 * @brief Decode Base64 string to bytes.
 * @param in Input Base64 string.
 * @param out Pointer to output byte array (allocated inside function).
 * @param out_len Pointer to output length.
 * @return 0 on success, 1 on memory error, 2 on invalid input.
 */
int mathi_dec_base64(const char *restrict in, unsigned char **out, size_t *out_len);

/**
 * @brief Compress data using Run-Length Encoding (RLE).
 * @param in Input byte array.
 * @param len Length of input data.
 * @param out Pointer to output byte array (allocated inside function).
 * @param out_len Pointer to output length.
 * @return 0 on success, 1 on memory error, 2 on invalid input.
 */
int mathi_rle_compress(const unsigned char *restrict in, size_t len, unsigned char **out, size_t *out_len);

/**
 * @brief Decompress RLE-compressed data.
 * @param in Input RLE-compressed byte array.
 * @param len Length of input data.
 * @param out Pointer to output byte array (allocated inside function).
 * @param out_len Pointer to output length.
 * @return 0 on success, 1 on memory error, 2 on invalid input.
 */
int mathi_rle_decompress(const unsigned char *restrict in, size_t len, unsigned char **out, size_t *out_len);

// --- conversion.h ---
/**
 * @brief Convert binary string to decimal integer.
 * @param bin Binary string (e.g., "1010").
 * @param result Pointer to store the result.
 * @return 0 on success, 1 on memory error, 2 on invalid input.
 */
int mathi_bin_to_dcm(const char *bin, int *result);

/**
 * @brief Convert decimal integer to binary string.
 * @param num Integer to convert.
 * @param out Pointer to allocated string for the result.
 * @return 0 on success, 1 on memory error, 2 on invalid input.
 */
int mathi_dcm_to_bin(int num, char **out);

/**
 * @brief Convert hexadecimal string to decimal integer.
 * @param hex Hex string (e.g., "1A3F").
 * @param result Pointer to store the result.
 * @return 0 on success, 1 on memory error, 2 on invalid input.
 */
int mathi_hex_to_dcm(const char *hex, int *result);

/**
 * @brief Convert decimal integer to hexadecimal string.
 * @param num Integer to convert.
 * @param out Pointer to allocated string for the result.
 * @return 0 on success, 1 on memory error, 2 on invalid input.
 */
int mathi_dcm_to_hex(int num, char **out);

/**
 * @brief Convert integer to string.
 * @param num Integer to convert.
 * @param out Pointer to allocated string for the result.
 * @return 0 on success, 1 on memory error, 2 on invalid input.
 */
int mathi_int_to_str(int num, char **out);

/**
 * @brief Convert string to integer.
 * @param str Input string.
 * @param result Pointer to store the integer result.
 * @return 0 on success, 2 on invalid input.
 */
int mathi_str_to_int(const char *str, int *result);

/**
 * @brief Convert string to double.
 * @param str Input string.
 * @param result Pointer to store the double result.
 * @return 0 on success, 2 on invalid input.
 */
int mathi_str_to_dbl(const char *str, double *result);

// --- crypto.h ---
/**
 * @brief Compute SHA-256 hash (placeholder implementation).
 * @param input Null-terminated input string.
 * @param output Buffer to store resulting hash string (must be preallocated).
 * @return 0 on success, 2 on invalid input.
 */
int mathi_hash_sha256(const char *input, char *output);

/**
 * @brief Compute MD5 hash (placeholder implementation).
 * @param input Null-terminated input string.
 * @param output Buffer to store resulting hash string (must be preallocated).
 * @return 0 on success, 2 on invalid input.
 */
int mathi_hash_md5(const char *input, char *output);

/**
 * @brief XOR encrypt/decrypt a string with a single-byte key.
 * @param data Null-terminated string to process (modified in place).
 * @param key XOR key.
 * @return 0 on success, 2 on invalid input.
 */
int mathi_xor_cipher(char *data, char key);

/**
 * @brief Compute a simple checksum (sum of bytes modulo 256).
 * @param data Input byte array.
 * @param len Length of the array.
 * @return Checksum (0–255), or 2 if input is NULL.
 */
int mathi_checksum(const unsigned char *data, size_t len);

// --- ds.h ---
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

// --- ds_advanced.h ---

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
void mathi_graph_free(Graph *g);

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
Trie* mathi_trie_new(void);

/**
 * @brief Insert a key-value pair into the Trie.
 * @param t Pointer to Trie
 * @param key Null-terminated string key
 * @param value Pointer to value
 * @return 0 on success, 1 on failure
 */
int mathi_trie_insert(Trie *t, const char *key, void *value);

/**
 * @brief Search for a key in the Trie.
 * @param t Pointer to Trie
 * @param key Null-terminated string key
 * @return Pointer to stored value, or NULL if not found
 */
void* mathi_trie_search(Trie *t, const char *key);

/**
 * @brief Free all memory associated with the Trie.
 * @param t Pointer to Trie
 */
void mathi_trie_free(Trie *t);

// --- filex.h ---
/**
 * @brief Open a file with the specified mode.
 * @param path File path
 * @param mode Mode string (e.g., "r", "w", "rb")
 * @return FILE pointer on success, NULL on failure
 */
FILE* mathi_filex_open(const char *path, const char *mode);

/**
 * @brief Close a previously opened file.
 * @param f FILE pointer
 */
void mathi_filex_close(FILE *f);

/* --- File existence / size --- */
/**
 * @brief Check if a file exists.
 * @param path File path
 * @return 1 if file exists, 0 otherwise
 */
int mathi_file_exists(const char *path);

/**
 * @brief Get the size of a file in bytes.
 * @param path File path
 * @return File size in bytes, or -1 if file cannot be opened
 */
long mathi_file_size(const char *path);

/**
 * @brief Read the contents of a file into a buffer.
 * @param path File path
 * @param buffer Buffer to store file contents
 * @param size Maximum number of bytes to read
 * @return 1 on success, 0 on failure
 */
int mathi_file_read(const char *path, char *buffer, long size);

/**
 * @brief Write data to a file (overwrite).
 * @param path File path
 * @param buffer Buffer containing data
 * @param size Number of bytes to write
 * @return 1 on success, 0 on failure
 */
int mathi_file_write(const char *path, const char *buffer, long size);

/**
 * @brief Append a string to a file.
 * @param path File path
 * @param buffer Null-terminated string to append
 * @return 1 on success, 0 on failure
 */
int mathi_file_append(const char *path, const char *buffer);


/**
 * @brief Read a line from a file.
 * @param fp FILE pointer
 * @param buffer Buffer to store line
 * @param size Size of the buffer
 * @return Pointer to buffer on success, NULL on EOF or error
 */
char* mathi_file_read_line(FILE *fp, char *buffer, size_t size);


/**
 * @brief Copy a file from source to destination.
 * @param src Source file path
 * @param dest Destination file path
 * @return 1 on success, 0 on failure
 */
int mathi_file_copy(const char *src, const char *dest);

/**
 * @brief Delete a file.
 * @param path File path
 * @return 1 on success, 0 on failure
 */
int mathi_file_delete(const char *path);

// --- inputx.h ---
#define INPUT_OK              0
#define INPUT_EMPTY           1
#define INPUT_INVALID_INT     2
#define INPUT_INVALID_DOUBLE  3
#define INPUT_INVALID_BINARY  4
#define INPUT_INVALID_HEX     5

typedef struct {
    int code;   /**< Status code: 0 = OK, >0 = error */
    void *value;/**< Pointer to value (int*, double*, or char*) */
} InputResult;


/**
 * @brief Prompt the user and read an integer.
 * @param prompt Message to display
 * @return InputResult containing status and pointer to int
 */
InputResult mathi_get_int(const char *prompt);

/**
 * @brief Prompt the user and read a double.
 * @param prompt Message to display
 * @return InputResult containing status and pointer to double
 */
InputResult mathi_get_double(const char *prompt);

/**
 * @brief Prompt the user and read a binary string (e.g., "10101").
 * @param prompt Message to display
 * @return InputResult containing status and pointer to string
 */
InputResult mathi_get_binary(const char *prompt);

/**
 * @brief Prompt the user and read a hexadecimal string (e.g., "1A3F").
 * @param prompt Message to display
 * @return InputResult containing status and pointer to string
 */
InputResult mathi_get_hex(const char *prompt);

/**
 * @brief Prompt the user and read a string.
 * @param prompt Message to display
 * @return InputResult containing status and pointer to string
 */
InputResult get_string(const char *prompt);

// --- logx.h ---
/**
 * @file mathi/logx.h
 * @brief Logging functions (info, warn, error) with optional file output.
 */

/* Status codes */
#define LOG_SUCCESS   0
#define LOG_FILE_ERROR 1
#define LOG_INVALID_PATH 2

/**
 * @brief Set the file to which logs should be written.
 * @param path File path.
 * @return LOG_SUCCESS on success, LOG_FILE_ERROR if file can't be opened, LOG_INVALID_PATH if path is NULL.
 */
int mathi_set_log_file(const char *path);

/**
 * @brief Log an informational message.
 * @param fmt Format string (like printf).
 * @return LOG_SUCCESS
 */
int mathi_log_info(const char *fmt, ...);

/**
 * @brief Log a warning message.
 * @param fmt Format string (like printf).
 * @return LOG_SUCCESS
 */
int mathi_log_warn(const char *fmt, ...);

/**
 * @brief Log an error message.
 * @param fmt Format string (like printf).
 * @return LOG_SUCCESS
 */
int mathi_log_error(const char *fmt, ...);

// --- mathison.h ---
/**
 * @enum MathiJSONType
 * @brief Enumeration of possible JSON types.
 */
typedef enum {
    JSON_NULL,    /**< Null type */
    JSON_BOOL,    /**< Boolean type */
    JSON_NUMBER,  /**< Numeric type */
    JSON_STRING,  /**< String type */
    JSON_ARRAY,   /**< Array type */
    JSON_OBJECT   /**< Object type */
} MathiJSONType;

/**
 * @struct MathiJSON
 * @brief Representation of a JSON value.
 */
typedef struct MathiJSON MathiJSON;

struct MathiJSON {
    MathiJSONType type; /**< Type of JSON value */
    union {
        struct {           /**< JSON object */
            char **keys;        /**< Array of keys */
            MathiJSON **values; /**< Array of corresponding values */
            size_t count;       /**< Number of key-value pairs */
        } object;
        struct {           /**< JSON array */
            MathiJSON **items; /**< Array of items */
            size_t count;      /**< Number of items */
        } array;
        char *str;         /**< JSON string value */
        double num;        /**< JSON numeric value */
        bool boolean;      /**< JSON boolean value */
    } data;
};


/**
 * @brief Create a new JSON object.
 * @return Pointer to a new MathiJSON object of type JSON_OBJECT.
 */
MathiJSON* mathison_new_object(void);

/**
 * @brief Create a new JSON array.
 * @return Pointer to a new MathiJSON object of type JSON_ARRAY.
 */
MathiJSON* mathison_new_array(void);

/**
 * @brief Create a new JSON string.
 * @param value String value to store.
 * @return Pointer to a new MathiJSON object of type JSON_STRING.
 */
MathiJSON* mathison_new_string(const char *value);

/**
 * @brief Create a new JSON number.
 * @param value Numeric value to store.
 * @return Pointer to a new MathiJSON object of type JSON_NUMBER.
 */
MathiJSON* mathison_new_number(double value);

/**
 * @brief Create a new JSON boolean.
 * @param value Boolean value to store.
 * @return Pointer to a new MathiJSON object of type JSON_BOOL.
 */
MathiJSON* mathison_new_bool(bool value);

/**
 * @brief Create a new JSON null value.
 * @return Pointer to a new MathiJSON object of type JSON_NULL.
 */
MathiJSON* mathison_new_null(void);


/**
 * @brief Copy a JSON object.
 * @param source Source JSON object.
 * @param dest Pointer to destination JSON pointer.
 * @return 0 on success, -1 on failure.
 */
int mathison_copy(MathiJSON *source, MathiJSON **dest);

/**
 * @brief Free a JSON object and all its children.
 * @param json_obj JSON object to free.
 * @return 0 on success, -1 on failure.
 */
int mathison_free(MathiJSON *json_obj);

/**
 * @brief Clear contents of a JSON object/array without freeing the main structure.
 * @param json_obj JSON object or array to clear.
 * @return 0 on success, -1 on failure.
 */
int mathison_clear(MathiJSON *json_obj);


/**
 * @brief Check if a JSON object is of type JSON_OBJECT.
 */
bool mathison_is_object(MathiJSON *json_obj);

/**
 * @brief Check if a JSON object is of type JSON_ARRAY.
 */
bool mathison_is_array(MathiJSON *json_obj);

/**
 * @brief Check if a JSON object is of type JSON_STRING.
 */
bool mathison_is_string(MathiJSON *json_obj);

/**
 * @brief Check if a JSON object is of type JSON_NUMBER.
 */
bool mathison_is_number(MathiJSON *json_obj);

/**
 * @brief Check if a JSON object is of type JSON_BOOL.
 */
bool mathison_is_bool(MathiJSON *json_obj);

/**
 * @brief Check if a JSON object is of type JSON_NULL.
 */
bool mathison_is_null(MathiJSON *json_obj);

/**
 * @brief Validate JSON type against expected type.
 * @param json_obj JSON object to check.
 * @param expected_type Expected MathiJSONType.
 * @return Non-zero if matches, zero otherwise.
 */
int mathison_validate_type(MathiJSON *json_obj, int expected_type);

/**
 * @brief Append an item to a JSON array.
 */
int mathison_append_array(MathiJSON *json_array, MathiJSON *value);

/**
 * @brief Prepend an item to a JSON array.
 */
int mathison_prepend_array(MathiJSON *json_array, MathiJSON *value);

/**
 * @brief Insert an item at a specific index in a JSON array.
 */
int mathison_insert_array(MathiJSON *json_array, size_t index, MathiJSON *value);

/**
 * @brief Remove an item at a specific index from a JSON array.
 */
int mathison_remove_array_index(MathiJSON *json_array, size_t index);

/**
 * @brief Swap two items in a JSON array.
 */
int mathison_swap_array_items(MathiJSON *json_array, size_t i, size_t j);

/**
 * @brief Get an item from a JSON array by index.
 */
MathiJSON* mathison_array_get(MathiJSON *json_array, size_t index);

/**
 * @brief Get number of items in a JSON array.
 */
size_t mathison_array_count(MathiJSON *json_array);

/**
 * @brief Concatenate two JSON arrays.
 */
int mathison_array_concat(MathiJSON *target_array, MathiJSON *source_array);

/**
 * @brief Set a key-value pair in a JSON object.
 */
int mathison_set_value(MathiJSON *json_obj, const char *key, MathiJSON *value);

/**
 * @brief Get a value by key from a JSON object.
 */
int mathison_get_value(MathiJSON *json_obj, const char *key, MathiJSON **value);

/**
 * @brief Remove a key-value pair from a JSON object.
 */
int mathison_remove_key(MathiJSON *json_obj, const char *key);

/**
 * @brief Check if a key exists in a JSON object.
 */
bool mathison_has_key(MathiJSON *json_obj, const char *key);

/**
 * @brief Parse a string into a JSON object.
 */
int mathison_parse(const char *str, MathiJSON **json_obj);

/**
 * @brief Serialize a JSON object (currently supports strings only).
 */
int mathison_serialize(MathiJSON *json_obj, char **output);

// --- config.h ---
/**
 * @brief Load a configuration file.
 * @param file_path Path to the config file.
 * @return 0 on success, non-zero on error.
 */
int mathi_conf_load(const char *file_path);

/**
 * @brief Save the current configuration to file.
 * @param file_path Path to save the config file.
 * @return 0 on success, non-zero on error.
 */
int mathi_conf_save(const char *file_path);

/**
 * @brief Get a string value from the configuration.
 * @param key Key to look up.
 * @return String value, or empty string if not found.
 */
const char* mathi_conf_get_string(const char *key);

/**
 * @brief Set a string value in the configuration.
 * @param key Key to set.
 * @param value Value to assign.
 * @return 0 on success, non-zero on error.
 */
int mathi_conf_set_string(const char *key, const char *value);

/**
 * @brief Get an integer value from the configuration.
 * @param key Key to look up.
 * @param value Pointer to store the integer result.
 * @return 0 on success, non-zero on error.
 */
int mathi_conf_get_int(const char *key, int *value);

/**
 * @brief Get a boolean value from the configuration.
 * @param key Key to look up.
 * @param value Pointer to store the boolean result.
 * @return 0 on success, non-zero on error.
 */
int mathi_conf_get_bool(const char *key, bool *value);

/**
 * @brief Set a boolean value in the configuration.
 * @param key Key to set.
 * @param value Boolean value to assign.
 * @return 0 on success, non-zero on error.
 */
int mathi_conf_set_bool(const char *key, bool value);

/**
 * @brief Get a floating-point (double) value from the configuration.
 * @param key Key to look up.
 * @param value Pointer to store the double result.
 * @return 0 on success, non-zero on error.
 */
int mathi_conf_get_double(const char *key, double *value);

/**
 * @brief Set a floating-point (double) value in the configuration.
 * @param key Key to set.
 * @param value Double value to assign.
 * @return 0 on success, non-zero on error.
 */
int mathi_conf_set_double(const char *key, double value);

/**
 * @brief Get an array from the configuration.
 * @param key Key to look up.
 * @param array Pointer to store the MathiJSON array.
 * @return 0 on success, non-zero on error.
 */
int mathi_conf_get_array(const char *key, MathiJSON **array);

/**
 * @brief Set an array in the configuration.
 * @param key Key to set.
 * @param array MathiJSON array to assign.
 * @return 0 on success, non-zero on error.
 */
int mathi_conf_set_array(const char *key, MathiJSON *array);

/**
 * @brief Get a nested object from the configuration.
 * @param key Key to look up.
 * @param object Pointer to store the MathiJSON object.
 * @return 0 on success, non-zero on error.
 */
int mathi_conf_get_object(const char *key, MathiJSON **object);

/**
 * @brief Set a nested object in the configuration.
 * @param key Key to set.
 * @param object MathiJSON object to assign.
 * @return 0 on success, non-zero on error.
 */
int mathi_conf_set_object(const char *key, MathiJSON *object);

/**
 * @brief Remove a key/value pair from the configuration.
 * @param key Key to remove.
 * @return 0 on success, non-zero on error.
 */
int mathi_conf_remove_key(const char *key);

/**
 * @brief Check if a key exists in the configuration.
 * @param key Key to check.
 * @return true if the key exists, false otherwise.
 */
bool mathi_conf_has_key(const char *key);

// --- mathphy.h ---
/**
 * @struct Complex
 * @brief Structure representing a complex number.
 */
typedef struct {
    double real; /**< Real part */
    double imag; /**< Imaginary part */
} Complex;

/**
 * @brief Create a new complex number.
 * @param real Real part.
 * @param imag Imaginary part.
 * @return Complex number.
 */
Complex mathi_complex_new(double real, double imag);

/**
 * @brief Add two complex numbers.
 */
Complex mathi_complex_add(Complex a, Complex b);

/**
 * @brief Subtract two complex numbers.
 */
Complex mathi_complex_sub(Complex a, Complex b);

/**
 * @brief Multiply two complex numbers.
 */
Complex mathi_complex_mul(Complex a, Complex b);

/**
 * @brief Divide two complex numbers.
 */
Complex mathi_complex_div(Complex a, Complex b);

/**
 * @brief Compute the absolute value (magnitude) of a complex number.
 */
double mathi_complex_abs(Complex a);


/**
 * @brief Compute the inverse of a square matrix.
 * @param matrix Pointer to the original 2D array of doubles.
 * @param inverse Pointer to the 2D array to store the inverse.
 * @param n Dimension of the square matrix.
 */
int mathi_matrix_inverse(double **matrix, double **inverse, int n);

/**
 * @brief Solve a linear system Ax = b.
 * @param A Pointer to the matrix of coefficients.
 * @param b Pointer to the right-hand side vector.
 * @param x Pointer to the solution vector (output).
 * @param n Dimension of the system.
 */
int mathi_linear_solver(double **A, double *b, double *x, int n);

// --- mathx.h ---
/**
 * @brief Compute the greatest common divisor (GCD) of two integers.
 */
int mathi_gcd(int a, int b);

/**
 * @brief Compute the least common multiple (LCM) of two integers.
 */
int mathi_lcm(int a, int b);

/**
 * @brief Compute factorial of a non-negative integer.
 * @return -1 if n < 0.
 */
double mathi_factorial(int n);

/**
 * @brief Compute integer power of a base.
 */
double mathi_power(double base, int exp);

/**
 * @brief Check if a number is prime.
 * @return 1 if prime, 0 otherwise.
 */
int mathi_prime(int n);

/**
 * @brief Find the next prime number greater than n.
 */
int mathi_next_prime(int n);

/* --- Floating Point / General Math --- */

/**
 * @brief Compute the square root of a number.
 * @return -1 if x < 0.
 */
double mathi_sqrt(double x);

/**
 * @brief Compute absolute value of a double.
 */
double mathi_abs_double(double x);

/**
 * @brief Compute absolute value of an integer.
 */
int mathi_abs_int(int x);

/**
 * @brief Return maximum of two integers.
 */
int mathi_max_int(int a, int b);

/**
 * @brief Return minimum of two integers.
 */
int mathi_min_int(int a, int b);

/**
 * @brief Return maximum of two doubles.
 */
double mathi_max_double(double a, double b);

/**
 * @brief Return minimum of two doubles.
 */
double mathi_min_double(double a, double b);

// --- matrix.h ---
/**
 * @brief Add two matrices a and b element-wise.
 * @param a First input matrix
 * @param b Second input matrix
 * @param res Output matrix (result)
 * @param rows Number of rows
 * @param cols Number of columns
 */
void mathi_matrix_add(int **a, int **b, int **res, int rows, int cols);

/**
 * @brief Subtract matrix b from matrix a element-wise.
 */
void mathi_matrix_sub(int **a, int **b, int **res, int rows, int cols);

/**
 * @brief Multiply two square matrices a and b.
 * @param n Dimension of the square matrices
 */
void mathi_matrix_mul(int **a, int **b, int **res, int n);

/**
 * @brief Transpose a matrix.
 */
void mathi_matrix_transpose(int **a, int **res, int rows, int cols);

/**
 * @brief Compute the determinant of a square matrix.
 * @param a Input square matrix
 * @param n Dimension of the matrix
 * @return Determinant of the matrix
 */
int mathi_matrix_determinant(int **a, int n);

/**
 * @brief Create an identity matrix of size n x n.
 */
void mathi_matrix_identity(int **res, int n);

/**
 * @brief Multiply a matrix by a scalar.
 */
void mathi_matrix_scalar_mul(int **a, int scalar, int **res, int rows, int cols);

// --- networking.h ---
/**
 * @brief Establish a TCP connection to a host and port.
 * @param host Hostname or IP address
 * @param port Port number
 * @return Socket descriptor on success, -1 on failure
 */
int mathi_connect_tcp(const char *host, int port);

/**
 * @brief Send data over a TCP connection.
 * @param sock Socket descriptor
 * @param data Pointer to data buffer
 * @param size Size of data in bytes
 * @return Number of bytes sent, or -1 on error
 */
int mathi_send_tcp(int sock, const char *data, size_t size);

/**
 * @brief Receive data from a TCP connection.
 * @param sock Socket descriptor
 * @param buffer Buffer to store received data
 * @param size Maximum number of bytes to receive
 * @return Number of bytes received, or -1 on error
 */
int mathi_recv_tcp(int sock, char *buffer, size_t size);


/**
 * @brief Create a UDP socket.
 * @param host Hostname or IP (unused in socket creation, provided for consistency)
 * @param port Port number (unused in socket creation, provided for consistency)
 * @return Socket descriptor on success, -1 on failure
 */
int mathi_connect_udp(const char *host, int port);

/**
 * @brief Send data over a UDP socket to a specific host and port.
 * @param sock UDP socket descriptor
 * @param data Data buffer to send
 * @param size Size of data in bytes
 * @param host Destination hostname or IP
 * @param port Destination port
 * @return Number of bytes sent, or -1 on error
 */
int mathi_send_udp(int sock, const char *data, size_t size, const char *host, int port);

/**
 * @brief Receive data from a UDP socket.
 * @param sock UDP socket descriptor
 * @param buffer Buffer to store received data
 * @param size Maximum number of bytes to receive
 * @return Number of bytes received, or -1 on error
 */
int mathi_recv_udp(int sock, char *buffer, size_t size);

// --- print.h ---
/**
 * @brief Print a linked list of integers.
 * @param head Pointer to the head node
 * @param name Label to display before the list
 */
void mathi_prnt_linked_list(Node *head, const char *name);


/**
 * @brief Print an integer array.
 * @param arr Pointer to array
 * @param n Number of elements
 * @param name Label to display before the array
 */
void mathi_prnt_arr(int *arr, int n, const char *name);


/**
 * @brief Print a 2D integer matrix.
 * @param m Pointer to array of row pointers
 * @param rows Number of rows
 * @param cols Number of columns
 * @param name Label to display before the matrix
 */
void mathi_prnt_matrix(int *m[], int rows, int cols, const char *name);


/**
 * @brief Print a string with a label.
 * @param label Label to display
 * @param str String to print
 */
void mathi_prnt_str(const char *label, const char *str);


/**
 * @brief Print byte data as unsigned integers.
 * @param data Pointer to byte array
 * @param len Number of bytes
 * @param name Label to display before the byte array
 */
void mathi_prnt_bytes(const unsigned char *data, size_t len, const char *name);

void mathi_prnt_int_pair(const char *label, int a, int b);

void mathi_prnt_double_pair(const char *label, double x, double y);

void mathi_prnt_char_pair(const char *label, char c1, char c2);

void mathi_prnt_mem(const char *label, char *mem, size_t n);

// --- search.h ---
/**
 * @brief Perform linear search on an array.
 * @param arr Pointer to the integer array
 * @param n Number of elements in the array
 * @param key Value to search for
 * @return Index of key if found, -1 otherwise
 */
int mathi_linear_search(int *arr, int n, int key);

/**
 * @brief Perform binary search on a sorted array.
 * @param arr Pointer to sorted integer array
 * @param n Number of elements in the array
 * @param key Value to search for
 * @return Index of key if found, -1 otherwise
 */
int mathi_binary_search(int *arr, int n, int key);

/**
 * @brief Perform jump search on a sorted array.
 * @param arr Pointer to sorted integer array
 * @param n Number of elements in the array
 * @param key Value to search for
 * @return Index of key if found, -1 otherwise
 */
int mathi_jump_search(int *arr, int n, int key);

/**
 * @brief Perform interpolation search on a sorted array.
 * @param arr Pointer to sorted integer array
 * @param n Number of elements in the array
 * @param key Value to search for
 * @return Index of key if found, -1 otherwise
 */
int mathi_interpolation_search(int *arr, int n, int key);

// --- sort.h ---
/**
 * @brief Bubble Sort
 * @param arr Pointer to the array
 * @param n Number of elements in the array
 */
void mathi_bubble_sort(int *arr, int n);

/**
 * @brief Selection Sort
 * @param arr Pointer to the array
 * @param n Number of elements in the array
 */
void mathi_selection_sort(int *arr, int n);

/**
 * @brief Insertion Sort
 * @param arr Pointer to the array
 * @param n Number of elements in the array
 */
void mathi_insertion_sort(int *arr, int n);

/**
 * @brief Merge Sort
 * @param arr Pointer to the array
 * @param n Number of elements in the array
 */
void mathi_merge_sort(int *arr, int n);

/**
 * @brief Quick Sort
 * @param arr Pointer to the array
 * @param n Number of elements in the array
 */
void mathi_quick_sort(int *arr, int n);

/**
 * @brief Heap Sort
 * @param arr Pointer to the array
 * @param n Number of elements in the array
 */
void mathi_heap_sort(int *arr, int n);

/**
 * @brief Counting Sort (requires maximum element)
 * @param arr Pointer to the array
 * @param n Number of elements in the array
 * @param max Maximum value in the array
 */
void mathi_counting_sort(int *arr, int n, int max);

// --- stats.h ---
/**
 * @brief Compute the mean (average) of an array
 * @param arr Pointer to the integer array
 * @param n Number of elements in the array
 * @return Mean value as double
 */
double mathi_mean(int *arr, int n);

/**
 * @brief Compute the median of an array
 * @param arr Pointer to the integer array
 * @param n Number of elements in the array
 * @return Median value as double
 */
double mathi_median(int *arr, int n);

/**
 * @brief Compute the variance of an array
 * @param arr Pointer to the integer array
 * @param n Number of elements in the array
 * @return Variance as double
 */
double mathi_variance(int *arr, int n);

/**
 * @brief Compute the standard deviation of an array
 * @param arr Pointer to the integer array
 * @param n Number of elements in the array
 * @return Standard deviation as double
 */
double mathi_stddev(int *arr, int n);

/**
 * @brief Compute the mode (most frequent value) of an array
 * @param arr Pointer to the integer array
 * @param n Number of elements in the array
 * @return Mode as integer
 */
int mathi_mode(int *arr, int n);

/**
 * @brief Compute a percentile value of an array
 * @param arr Pointer to the integer array
 * @param n Number of elements in the array
 * @param p Percentile (0-100)
 * @return Percentile value as double
 */
double mathi_percentile(int *arr, int n, double p);

// --- sys.h ---
#ifdef __cplusplus
extern "C" {
#endif

/**
 * @brief Get the value of an environment variable
 * @param name Name of the environment variable
 * @return Pointer to the value string, or NULL if not found
 */
char* mathi_get_env(const char *name);

/**
 * @brief Set the value of an environment variable
 * @param name Name of the environment variable
 * @param value Value to set
 * @param overwrite If non-zero, overwrite existing variable
 * @return 1 on success, 0 on failure
 */
int mathi_set_env(const char *name, const char *value, int overwrite);

#ifdef __cplusplus
}
#endif

// --- timeutil.h ---
#ifdef __cplusplus
extern "C" {
#endif

/**
 * @file mathi/time.h
 * @brief Time and timestamp utility functions.
 */

/**
 * @brief Get the current Unix timestamp
 * @return Current timestamp in seconds since epoch
 */
long mathi_current_timestamp(void);

/**
 * @brief Format current local time into a string
 * @param buffer Buffer to store formatted time
 * @param size Size of the buffer
 *
 * Format used: "YYYY-MM-DD HH:MM:SS"
 */
void mathi_format_time(char *buffer, size_t size);

/**
 * @brief Sleep for a specified number of milliseconds
 * @param ms Number of milliseconds to sleep
 *
 * Cross-platform implementation: uses Sleep on Windows and usleep on Unix.
 */
void mathi_sleep_ms(int ms);

/**
 * @brief Calculate elapsed seconds between two timestamps
 * @param start Start timestamp
 * @param end End timestamp
 * @return Number of seconds elapsed
 */
int mathi_elapsed_seconds(long start, long end);

#ifdef __cplusplus
}
#endif

// --- util.h ---
/**
 * @brief Swap two integers in place.
 * @param a Pointer to the first integer.
 * @param b Pointer to the second integer.
 */
void mathi_swap_int(int *a, int *b);

/**
 * @brief Swap two doubles in place.
 * @param a Pointer to the first double.
 * @param b Pointer to the second double.
 */
void mathi_swap_double(double *a, double *b);

/**
 * @brief Swap two characters in place.
 * @param a Pointer to the first character.
 * @param b Pointer to the second character.
 */
void mathi_swap_char(char *a, char *b);

/**
 * @brief Clamp an integer to a specified range.
 * @param value The value to clamp.
 * @param min Minimum allowed value.
 * @param max Maximum allowed value.
 * @return The clamped value within [min, max].
 */
int mathi_clamp_int(int value, int min, int max);

/**
 * @brief Clamp a double to a specified range.
 * @param value The value to clamp.
 * @param min Minimum allowed value.
 * @param max Maximum allowed value.
 * @return The clamped value within [min, max].
 */
double mathi_clamp_double(double value, double min, double max);

/**
 * @brief Set a memory block to zero.
 * @param ptr Pointer to the memory block.
 * @param size Size of the memory block in bytes.
 */
void mathi_mem_zero(void *ptr, size_t size);

/**
 * @brief Copy a memory block from source to destination.
 * @param dest Destination pointer.
 * @param src Source pointer.
 * @param size Size of the memory block in bytes.
 */
void mathi_mem_copy(void *dest, const void *src, size_t size);

/**
 * @brief Swap two memory blocks of arbitrary size.
 * @param a Pointer to the first memory block.
 * @param b Pointer to the second memory block.
 * @param size Size of the memory blocks in bytes.
 */
void mathi_mem_swap(void *a, void *b, size_t size);

// --- validator.h ---
#ifdef __cplusplus
extern "C" {
#endif

/**
 * @brief Check if a string represents a valid integer.
 * @param str The string to check.
 * @return 1 if the string is a valid integer, 0 otherwise.
 */
int mathi_is_int(const char *str);

/**
 * @brief Check if a string represents a valid float.
 * @param str The string to check.
 * @return 1 if the string is a valid float, 0 otherwise.
 */
int mathi_is_float(const char *str);

/**
 * @brief Check if a string represents a valid double.
 * @param str The string to check.
 * @return 1 if the string is a valid double, 0 otherwise.
 */
int mathi_is_double(const char *str);

/**
 * @brief Check if a string represents any numeric value (int, float, or double).
 * @param str The string to check.
 * @return 1 if the string is numeric, 0 otherwise.
 */
int mathi_is_number(const char *str);

/**
 * @brief Check if a string contains only alphabetic characters.
 * @param str The string to check.
 * @return 1 if the string is alphabetic, 0 otherwise.
 */
int mathi_is_alpha(const char *str);

/**
 * @brief Check if a string contains only alphanumeric characters.
 * @param str The string to check.
 * @return 1 if the string is alphanumeric, 0 otherwise.
 */
int mathi_is_alnum(const char *str);

/**
 * @brief Check if a string contains only binary digits ('0' or '1').
 * @param str The string to check.
 * @return 1 if the string is binary, 0 otherwise.
 */
int mathi_is_binary(const char *str);

/**
 * @brief Check if a string contains only valid hexadecimal characters.
 * @param str The string to check.
 * @return 1 if the string is hexadecimal, 0 otherwise.
 */
int mathi_is_hex(const char *str);

/**
 * @brief Check if an integer is within a specified range.
 * @param value The value to check.
 * @param min Minimum allowed value.
 * @param max Maximum allowed value.
 * @return 1 if value is within [min, max], 0 otherwise.
 */
int mathi_in_range(int value, int min, int max);

#ifdef __cplusplus
}
#endif

#endif // MATHI_H