# Mathi C Library

[![License: MIT](https://img.shields.io/badge/License-MIT-yellow.svg)](LICENSE)
[![Build Status](https://img.shields.io/github/actions/workflow/status/macharia-nyamu/mathi_c/build.yml)](https://github.com/macharia-nyamu/mathi_c/actions)

Mathi C is a modular C library collection providing algorithms, data structures, file and string utilities, math operations, and time/date utilities — all ready to plug into your C projects.

---


## Modules

| Category          | Modules                       | Description                       |
|------------------|-------------------------------|-----------------------------------|
| Algorithms        | `Algo`, `Sort`, `Search`      | Sorting, searching, Fibonacci etc.|
| Data Structures   | `DS`, `DSX`                   | Lists, stacks, queues, trees      |
| Math Utilities    | `Mathx`, `Mathphy`, `Mathison`| Arithmetic, physics, advanced math|
| File & I/O        | `Filex`, `Inputx`, `Logx`     | File handling, input, logging     |
| String Utilities  | `Stringx`, `Codec`            | String operations, encoding/decoding|
| Time & System     | `Timeutil`, `Sys`             | Date, time, system operations     |
| General Utilities | `Util`, `Validator`           | Helpers, validators               |

### Modules and Functions

#### Algo (`algo.c`)
- `int fibonacci(int n)`
- `int count_occurrences(int arr[], int n, int value)`
- `void rotate_array(int *arr, int n, int k)`
- `int factorial_iterative(int n)`
- `int factorial_recursive(int n)`
- `int is_sorted(int *arr, int n)`
- `int nth_fibonacci(int n)`
- `int sum_of_digits(int n)`
- `int digital_root(int n)`

#### Array (`array.c`)
- `int array_index_of(int *arr, int n, int value)`
- `int array_contains(int *arr, int n, int value)`
- `void array_reverse(int *arr, int n)`
- `void array_copy(int *src, int *dest, int n)`
- `void array_fill(int *arr, int n, int value)`
- `int array_sum(int *arr, int n)`
- `int array_max(int *arr, int n)`
- `int array_min(int *arr, int n)`
- `double array_average(int *arr, int n)`
- `int array_equals(int *a, int *b, int n)`
- `void array_shuffle(int *arr, int n)`
- `void array_unique(int *arr, int *n)`

#### Codec (`codec.c`)
- `int base64_encode(const unsigned char *data, size_t len, char **output)`
- `int base64_decode(const char *input, unsigned char **output, size_t *out_len)`
- `int rle_compress(const unsigned char *data, size_t len, unsigned char **out, size_t *out_len)`
- `int rle_decompress(const unsigned char *data, size_t len, unsigned char **out, size_t *out_len)`

#### Config (`config.c`)
- `int config_load(const char *file_path)`
- `int config_get_int(const char *key, int *value)`
- `int config_set_string(const char *key, const char *value)`
- `int config_save(const char *file_path)`

#### Conversion (`conversion.c`)
- `int binary_to_decimal(const char *bin)`
- `void decimal_to_binary(int num, char *buffer)`
- `int hex_to_decimal(const char *hex)`
- `void decimal_to_hex(int num, char *buffer)`
- `int string_to_int(const char *str)`
- `double string_to_double(const char *str)`

#### Crypto (`crypto.c`)
- `int sha256_hash(const char *input, char *output)`
- `int md5_hash(const char *input, char *output)`
- `int xor_cipher(char *data, char key)`
- `int simple_checksum(const unsigned char *data, size_t len)`

#### DS (`ds.c`)
- `void linked_list_add(Node **head, int value)`
- `void linked_list_remove(Node **head, int value)`
- `int linked_list_length(Node *head)`
- `void linked_list_print(Node *head)`
- `int list_length(Node *head)`
- `void stack_push(Stack *s, int v)`
- `int stack_pop(Stack *s)`
- `int stack_peek(Stack *s)`
- `int stack_is_empty(Stack *s)`
- `void stack_free(Stack *s)`
- `void queue_enqueue(Queue *q, int v)`
- `int queue_dequeue(Queue *q)`
- `int queue_peek(Queue *q)`
- `int queue_is_empty(Queue *q)`
- `void queue_free(Queue *q)`
- `void hash_set(Hash *h, const char *k, int v)`
- `int hash_get(Hash *h, const char *k)`
- `void hash_free(Hash *h)`

#### DSX (`dsx.c`)
- `int stack_push(Stack *s, void *item)`
- `int stack_is_empty(Stack *s)`
- `void stack_free(Stack *s)`
- `int queue_enqueue(Queue *q, void *item)`
- `int queue_is_empty(Queue *q)`
- `void queue_free(Queue *q)`
- `int heap_insert(Heap *h, void *item)`
- `int heap_is_empty(Heap *h)`
- `void heap_free(Heap *h)`
- `int graph_add_edge(Graph *g, int src, int dest)`
- `void graph_free(Graph *g)`
- `int trie_insert(Trie *t, const char *key, void *value)`
- `void trie_free(Trie *t)`
- `int hashmap_set(HashMap *h, const char *key, void *value)`
- `int hashmap_has_key(HashMap *h, const char *key)`
- `void hashmap_free(HashMap *h)`

#### Filex (`filex.c`)
- `void filex_close(FILE *f)`
- `int file_exists(const char *path)`
- `long file_size(const char *path)`
- `int file_read(const char *path, char *buffer, long size)`
- `int file_write(const char *path, const char *buffer, long size)`
- `int file_append(const char *path, const char *buffer)`
- `int file_copy(const char *src, const char *dest)`
- `int file_delete(const char *path)`

#### Inputx (`inputx.c`)
- `InputResult get_int(const char *prompt)`
- `InputResult get_double(const char *prompt)`
- `InputResult get_binary(const char *prompt)`
- `InputResult get_hex(const char *prompt)`
- `InputResult get_string(const char *prompt)`

#### Logx (`logx.c`)
- `int set_log_file(const char *path)`
- `int log_info(const char *fmt, ...)`
- `int log_warn(const char *fmt, ...)`
- `int log_error(const char *fmt, ...)`

#### Mathison (`mathison.c`)
- `int json_copy(MathiJSON *source, MathiJSON **dest)`
- `int json_free(MathiJSON *json)`
- `int json_clear(MathiJSON *json_obj)`
- `bool json_is_object(MathiJSON *json_obj)`
- `bool json_is_array(MathiJSON *json_obj)`
- `bool json_is_string(MathiJSON *json_obj)`
- `bool json_is_number(MathiJSON *json_obj)`
- `bool json_is_bool(MathiJSON *json_obj)`
- `bool json_is_null(MathiJSON *json_obj)`
- `int json_append_array(MathiJSON *json_array, MathiJSON *value)`
- `int json_swap_array_items(MathiJSON *json_array, size_t i, size_t j)`
- `size_t json_array_count(MathiJSON *json_array)`
- `int json_set_value(MathiJSON *json_obj, const char *key, MathiJSON *value)`
- `int json_get_value(MathiJSON *json_obj, const char *key, MathiJSON **value)`
- `int json_remove_key(MathiJSON *json_obj, const char *key)`
- `bool json_has_key(MathiJSON *json_obj)`
- `int json_parse(const char *str, MathiJSON **json_obj)`
- `int json_serialize(MathiJSON *json_obj, char **output)`
- `int json_prepend_array(MathiJSON *json_array, MathiJSON *value)`
- `int json_insert_array(MathiJSON *json_array, size_t index, MathiJSON *value)`
- `int json_remove_array_index(MathiJSON *json_array, size_t index)`
- `int json_array_concat(MathiJSON *target_array, MathiJSON *source_array)`
- `int json_validate_type(MathiJSON *json_obj, int expected_type)`

#### Mathphy (`mathphy.c`)
- `double matrix_determinant(double **matrix, int n)`
- `int matrix_inverse(double **matrix, double **inverse, int n)`
- `int linear_solver(double **A, double *b, double *x, int n)`
- `Complex complex_new(double real, double imag)`
- `Complex complex_add(Complex a, Complex b)`
- `Complex complex_sub(Complex a, Complex b)`
- `Complex complex_mul(Complex a, Complex b)`
- `Complex complex_div(Complex a, Complex b)`
- `double complex_abs(Complex a)`

#### Mathx (`mathx.c`)
- `int gcd(int a, int b)`
- `int lcm(int a, int b)`
- `double factorial(int n)`
- `double power(double base, int exp)`
- `int is_prime(int n)`
- `int next_prime(int n)`
- `double sqrt_newton(double x)`
- `double abs_double(double x)`
- `int abs_int(int x)`
- `int max_int(int a, int b)`
- `int min_int(int a, int b)`
- `double max_double(double a, double b)`
- `double min_double(double a, double b)`

#### Matrix (`matrix.c`)
- `void matrix_add(int **a, int **b, int **res, int rows, int cols)`
- `void matrix_sub(int **a, int **b, int **res, int rows, int cols)`
- `void matrix_mul(int **a, int **b, int **res, int n)`
- `void matrix_transpose(int **a, int **res, int rows, int cols)`
- `int matrix_determinant(int **a, int n)`
- `void matrix_identity(int **res, int n)`
- `void matrix_scalar_mul(int **a, int scalar, int **res, int rows, int cols)`

#### Networking (`networking.c`)
- `int connect_tcp(const char *host, int port)`
- `int send_tcp(int sock, const char *data, size_t size)`
- `int recv_tcp(int sock, char *buffer, size_t size)`
- `int connect_udp(const char *host, int port)`
- `int send_udp(int sock, const char *data, size_t size, const char *host, int port)`
- `int recv_udp(int sock, char *buffer, size_t size)`

#### Search (`search.c`)
- `int linear_search(int *arr, int n, int key)`
- `int binary_search(int *arr, int n, int key)`
- `int jump_search(int *arr, int n, int key)`
- `int interpolation_search(int *arr, int n, int key)`

#### Sort (`sort.c`)
- `void bubble_sort(int *arr, int n)`
- `void selection_sort(int *arr, int n)`
- `void insertion_sort(int *arr, int n)`
- `void merge_sort(int *arr, int n)`
- `void quick_sort(int *arr, int n)`
- `void heap_sort(int *arr, int n)`
- `void counting_sort(int *arr, int n, int max)`

#### Stats (`stats.c`)
- `double mean(int *arr, int n)`
- `int cmp_int(const void *a, const void *b)`
- `double median(int *arr, int n)`
- `double variance(int *arr, int n)`
- `double stddev(int *arr, int n)`
- `int mode(int *arr, int n)`
- `double percentile(int *arr, int n, double p)`

#### Stringx (`stringx.c`)
- `int string_index_of(const char *str, char c)`
- `int string_contains(const char *str, char c)`
- `int string_count_char(const char *str, char c)`
- `int string_length(const char *str)`
- `int string_compare(const char *a, const char *b)`
- `int string_starts_with(const char *str, const char *prefix)`
- `int string_ends_with(const char *str, const char *suffix)`

#### Sys (`sys.c`)
- `int set_env(const char *name, const char *value, int overwrite)`

#### Timeutil (`timeutil.c`)
- `long current_timestamp()`
- `void format_time(char *buffer, size_t size)`
- `void sleep_ms(int ms)`
- `int elapsed_seconds(long start, long end)`

#### Util (`util.c`)
- `void swap_int(int *a, int *b)`
- `void swap_double(double *a, double *b)`
- `void swap_char(char *a, char *b)`
- `int clamp_int(int value, int min, int max)`
- `double clamp_double(double value, double min, double max)`
- `void mem_zero(void *ptr, size_t size)`
- `void mem_copy(void *dest, const void *src, size_t size)`
- `void mem_swap(void *a, void *b, size_t size)`

#### Validator (`validator.c`)
- `int is_int(const char *str)`
- `int is_float(const char *str)`
- `int is_double(const char *str)`
- `int is_number(const char *str)`
- `int is_alpha(const char *str)`
- `int is_alnum(const char *str)`
- `int is_binary(const char *str)`
- `int is_hex(const char *str)`
- `int is_in_range(int value, int min, int max)`


---

## Project Structure

```text
Mathi C/
├── build/ # compiled binaries and objects
│ └── bin/ # compiled test binaries
│ ├── algo_test
│ ├── array_test
│ ├── codec_test
│ ├── config_test
│ ├── conversion_test
│ ├── crypto_test
│ ├── ds_test
│ ├── dsx_test
│ ├── filex_test
│ ├── inputx_test
│ ├── logx_test
│ ├── mathison_test
│ ├── mathphy_test
│ ├── mathx_test
│ ├── matrix_test
│ ├── networking_test
│ ├── search_test
│ ├── sort_test
│ ├── stats_test
│ ├── stringx_test
│ ├── sys_test
│ ├── timeutil_test
│ ├── util_test
│ └── validator_test
├── docs/ # additional documentation
├── include/ # library headers
│ └── mathi/
│ ├── algo.h
│ ├── array.h
│ ├── codec.h
│ ├── config.h
│ ├── conversion.h
│ ├── crypto.h
│ ├── ds.h
│ ├── dsx.h
│ ├── filex.h
│ ├── inputx.h
│ ├── logx.h
│ ├── mathi.h
│ ├── mathison.h
│ ├── mathphy.h
│ ├── mathx.h
│ ├── matrix.h
│ ├── networking.h
│ ├── search.h
│ ├── sort.h
│ ├── stats.h
│ ├── stringx.h
│ ├── sys.h
│ ├── timeutil.h
│ ├── util.h
│ └── validator.h
├── src/ # source code files
│ ├── algo.c
│ ├── array.c
│ ├── codec.c
│ ├── config.c
│ ├── conversion.c
│ ├── crypto.c
│ ├── ds.c
│ ├── dsx.c
│ ├── filex.c
│ ├── inputx.c
│ ├── logx.c
│ ├── mathison.c
│ ├── mathphy.c
│ ├── mathx.c
│ ├── matrix.c
│ ├── networking.c
│ ├── search.c
│ ├── sort.c
│ ├── stats.c
│ ├── stringx.c
│ ├── sys.c
│ ├── timeutil.c
│ ├── util.c
│ └── validator.c
└── tests/ # unit tests for all modules
├── algo_test.c
├── array_test.c
├── codec_test.c
├── config_test.c
├── conversion_test.c
├── crypto_test.c
├── ds_test.c
├── dsx_test.c
├── filex_test.c
├── inputx_test.c
├── logx_test.c
├── mathison_test.c
├── mathphy_test.c
├── mathx_test.c
├── matrix_test.c
├── networking_test.c
├── search_test.c
├── sort_test.c
├── stats_test.c
├── stringx_test.c
├── sys_test.c
├── timeutil_test.c
├── util_test.c
└── validator_test.c
```

---

## Installation & Build

Clone the repository:

```bash
git clone https://github.com/macharia-nyamu/mathi_c.git
cd mathi_c

Build the library:

mkdir -p build/bin
gcc src/*.c -I./include -lm -o build/bin/mathi_c

Running All Tests

# Algo
gcc tests/algo_test.c src/algo.c -I./include -lm -o build/bin/algo_test && ./build/bin/algo_test

# Array
gcc tests/array_test.c src/array.c -I./include -lm -o build/bin/array_test && ./build/bin/array_test

# Codec
gcc tests/codec_test.c src/codec.c -I./include -lm -o build/bin/codec_test && ./build/bin/codec_test

# Config
gcc tests/config_test.c src/config.c -I./include -lm -o build/bin/config_test && ./build/bin/config_test

# Conversion
gcc tests/conversion_test.c src/conversion.c -I./include -lm -o build/bin/conversion_test && ./build/bin/conversion_test

# Crypto
gcc tests/crypto_test.c src/crypto.c -I./include -lm -o build/bin/crypto_test && ./build/bin/crypto_test

# DS
gcc tests/ds_test.c src/ds.c -I./include -lm -o build/bin/ds_test && ./build/bin/ds_test

# DSX
gcc tests/dsx_test.c src/dsx.c -I./include -lm -o build/bin/dsx_test && ./build/bin/dsx_test

# Filex
gcc tests/filex_test.c src/filex.c -I./include -lm -o build/bin/filex_test && ./build/bin/filex_test

# Inputx
gcc tests/inputx_test.c src/inputx.c src/validator.c -I./include -lm -o build/bin/inputx_test && ./build/bin/inputx_test

# Logx
gcc tests/logx_test.c src/logx.c -I./include -lm -o build/bin/logx_test && ./build/bin/logx_test

# Mathison
gcc tests/mathison_test.c src/mathison.c -I./include -lm -o build/bin/mathison_test && ./build/bin/mathison_test

# Mathphy
gcc tests/mathphy_test.c src/mathphy.c -I./include -lm -o build/bin/mathphy_test && ./build/bin/mathphy_test

# Mathx
gcc tests/mathx_test.c src/mathx.c -I./include -lm -o build/bin/mathx_test && ./build/bin/mathx_test

# Matrix
gcc tests/matrix_test.c src/matrix.c -I./include -lm -o build/bin/matrix_test && ./build/bin/matrix_test

# Networking
gcc tests/networking_test.c src/networking.c -I./include -lm -o build/bin/networking_test && ./build/bin/networking_test

# Search
gcc tests/search_test.c src/search.c -I./include -lm -o build/bin/search_test && ./build/bin/search_test

# Sort
gcc tests/sort_test.c src/sort.c -I./include -lm -o build/bin/sort_test && ./build/bin/sort_test

# Stats
gcc tests/stats_test.c src/stats.c -I./include -lm -o build/bin/stats_test && ./build/bin/stats_test

# Stringx
gcc tests/stringx_test.c src/stringx.c -I./include -lm -o build/bin/stringx_test && ./build/bin/stringx_test

# Sys
gcc tests/sys_test.c src/sys.c -I./include -lm -o build/bin/sys_test && ./build/bin/sys_test

# Timeutil
gcc tests/timeutil_test.c src/timeutil.c -I./include -lm -o build/bin/timeutil_test && ./build/bin/timeutil_test

# Util
gcc tests/util_test.c src/util.c -I./include -lm -o build/bin/util_test && ./build/bin/util_test

# Validator
gcc tests/validator_test.c src/validator.c -I./include -lm -o build/bin/validator_test && ./build/bin/validator_test

Example Usage

#include "mathi/algo.h"
#include "mathi/array.h"
#include "mathi/ds.h"
#include "mathi/filex.h"
#include "mathi/mathx.h"
#include "mathi/stringx.h"
#include "mathi/timeutil.h"
#include "mathi/util.h"
#include "mathi/validator.h"
#include <stdio.h>

int main() {
    int arr[] = {3, 1, 4, 2};
    bubble_sort(arr, 4);
    printf("Bubble sorted array: ");
    for(int i = 0; i < 4; i++) printf("%d ", arr[i]);
    printf("\n");

    char str[] = "Mathi";
    string_reverse(str);
    printf("Reversed string: %s\n", str);

    if(is_int("123")) printf("123 is an int\n");
    if(is_float("12.34")) printf("12.34 is a float\n");

    printf("Factorial of 5 = %d\n", factorial_iterative(5));
    printf("Sum of digits of 1234 = %d\n", sum_of_digits(1234));

    stack_t s;
    stack_init(&s);
    stack_push(&s, 10);
    stack_push(&s, 20);
    printf("Stack top: %d\n", stack_top(&s));
    stack_pop(&s);
    printf("Stack top after pop: %d\n", stack_top(&s));

    return 0;
}

License

This project is licensed under the [MIT License](https://opensource.org/licenses/MIT) – see the LICENSE file for details.
