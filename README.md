# Mathi C Library

[![License: MIT](https://img.shields.io/badge/License-MIT-yellow.svg)](LICENSE)
[![Build Status](https://img.shields.io/github/actions/workflow/status/macharia-nyamu/mathi_c/build.yml)](https://github.com/macharia-nyamu/mathi_c/actions)

Mathi C is a modular C library collection providing algorithms, data structures, file and string utilities, math operations, and time/date utilities — all ready to plug into your C projects.

---

## Modules

| Category           | Modules                        | Description                               |
|-------------------|--------------------------------|-------------------------------------------|
| Algorithms         | `Algo`, `Sort`, `Search`       | Sorting, searching, Fibonacci, and related algorithms |
| Data Structures    | `DS`, `DS_Advanced`            | Lists, stacks, queues, heaps, trees      |
| Math Utilities     | `Mathx`, `Mathphy`, `Mathison` | Arithmetic, physics, complex math, JSON utilities |
| File & I/O         | `Filex`, `Inputx`, `Logx`      | File handling, user input, logging       |
| String Utilities   | `Stringx`, `Codec`             | String operations, encoding/decoding     |
| Time & System      | `Timeutil`, `Sys`              | Date, time, and system operations        |
| General Utilities  | `Util`, `Validator`            | Helper functions and input validators    |


### Functions

#### Algo (`algo.c`)
- `int mathi_fibonacci(int n)`
- `int mathi_occurs(int arr[], int n, int value)`
- `int mathi_factorial_iterative(int n)`
- `int mathi_factorial_recursive(int n)`
- `int mathi_dgts_sum(int n)`
- `int mathi_rt_digital(int n)`

#### Array (`array.c`)
- `int mathi_arr_index(int *arr, int n, int value)`
- `int mathi_arr_contains(int *arr, int n, int value)`
- `void mathi_arr_reverse(int *arr, int n)`
- `void mathi_arr_copy(int *src, int *dest, int n)`
- `void mathi_arr_fill(int *arr, int n, int value)`
- `int mathi_arr_sum(int *arr, int n)`
- `int mathi_arr_max(int *arr, int n)`
- `int mathi_arr_min(int *arr, int n)`
- `double mathi_arr_average(int *arr, int n)`
- `int mathi_arr_equal(int *a, int *b, int n)`
- `void mathi_arr_shuffle(int *arr, int n)`
- `void mathi_arr_distinct(int *arr, int *n)`
- `void mathi_arr_rotate(int *arr, int n, int k)`
- `int mathi_arr_sorted(int *arr, int n)`

#### Codec (`codec.c`)
- `int mathi_enc_base64(const unsigned char *data, size_t len, char **out)`
- `int mathi_dec_base64(const char *in, unsigned char **out, size_t *out_len)`
- `int mathi_rle_compress(const unsigned char *in, size_t len, unsigned char **out, size_t *out_len)`
- `int mathi_rle_decompress(const unsigned char *in, size_t len, unsigned char **out, size_t *out_len)`

#### Config (`config.c`)
- `int mathi_conf_load(const char *file_path)`
- `int mathi_conf_get_int(const char *key, int *value)`
- `int mathi_conf_set_string(const char *key, const char *value)`
- `int mathi_conf_save(const char *file_path)`

#### Conversion (`conversion.c`)
- `int mathi_bin_to_dcm(const char *bin, int *result)`
- `int mathi_dcm_to_bin(int num, char **out)`
- `int mathi_hex_to_dcm(const char *hex, int *result)`
- `int mathi_dcm_to_hex(int num, char **out)`
- `int mathi_int_to_str(int num, char **out)`
- `int mathi_str_to_int(const char *str, int *result)`
- `int mathi_str_to_dbl(const char *str, double *result)`

#### Crypto (`crypto.c`)
- `int mathi_hash_sha256(const char *input, char *output)`
- `int mathi_hash_md5(const char *input, char *output)`
- `int mathi_xor_cipher(char *data, char key)`
- `int mathi_checksum(const unsigned char *data, size_t len)`

#### DS Advanced (`ds_advanced.c`)
- `int mathi_heap_insert(Heap *h, void *item)`
- `int mathi_heap_is_empty(Heap *h)`
- `void mathi_heap_free(Heap *h)`
- `int mathi_graph_add_edge(Graph *g, int src, int dest)`
- `void mathi_graph_free(Graph *g)`
- `int mathi_trie_insert(Trie *t, const char *key, void *value)`
- `void mathi_trie_free(Trie *t)`

#### DS (`ds.c`)
- `void mathi_linked_list_add(Node **head, int value)`
- `void mathi_linked_list_remove(Node **head, int value)`
- `int mathi_linked_list_length(Node *head)`
- `void mathi_linked_list_print(Node *head)`
- `int mathi_list_length(Node *head)`
- `void mathi_stack_push(Stack *s, int v)`
- `int mathi_stack_pop(Stack *s)`
- `int mathi_stack_peek(Stack *s)`
- `int mathi_stack_is_empty(Stack *s)`
- `void mathi_stack_free(Stack *s)`
- `void mathi_queue_enqueue(Queue *q, int v)`
- `int mathi_queue_dequeue(Queue *q)`
- `int mathi_queue_peek(Queue *q)`
- `int mathi_queue_is_empty(Queue *q)`
- `void mathi_queue_free(Queue *q)`
- `void mathi_hash_set(Hash *h, const char *k, int v)`
- `int mathi_hash_get(Hash *h, const char *k)`
- `void mathi_hash_free(Hash *h)`

#### File Utilities (`filex.c`)
- `void mathi_filex_close(FILE *f)`
- `int mathi_file_exists(const char *path)`
- `long mathi_file_size(const char *path)`
- `int mathi_file_read(const char *path, char *buffer, long size)`
- `int mathi_file_write(const char *path, const char *buffer, long size)`
- `int mathi_file_append(const char *path, const char *buffer)`
- `int mathi_file_copy(const char *src, const char *dest)`
- `int mathi_file_delete(const char *path)`

#### Input (`inputx.c`)
- `InputResult mathi_get_int(const char *prompt)`
- `InputResult mathi_get_double(const char *prompt)`
- `InputResult mathi_get_binary(const char *prompt)`
- `InputResult mathi_get_hex(const char *prompt)`
- `InputResult mathi_get_string(const char *prompt)`

#### Logging (`logx.c`)
- `int mathi_set_log_file(const char *path)`
- `int mathi_log_info(const char *fmt, ...)`
- `int mathi_log_warn(const char *fmt, ...)`
- `int mathi_log_error(const char *fmt, ...)`

#### JSON (`mathison.c`)
- `int mathison_copy(MathiJSON *source, MathiJSON **dest)`
- `int mathison_free(MathiJSON *json)`
- `int mathison_clear(MathiJSON *json_obj)`
- `bool mathison_is_object(MathiJSON *json_obj)`
- `bool mathison_is_array(MathiJSON *json_obj)`
- `bool mathison_is_string(MathiJSON *json_obj)`
- `bool mathison_is_number(MathiJSON *json_obj)`
- `bool mathison_is_bool(MathiJSON *json_obj)`
- `bool mathison_is_null(MathiJSON *json_obj)`
- `int mathison_append_array(MathiJSON *json_array, MathiJSON *value)`
- `int mathison_prepend_array(MathiJSON *json_array, MathiJSON *value)`
- `int mathison_insert_array(MathiJSON *json_array, size_t index, MathiJSON *value)`
- `int mathison_remove_array_index(MathiJSON *json_array, size_t index)`
- `int mathison_array_concat(MathiJSON *target_array, MathiJSON *source_array)`
- `int mathison_swap_array_items(MathiJSON *json_array, size_t i, size_t j)`
- `size_t mathison_array_count(MathiJSON *json_array)`
- `int mathison_set_value(MathiJSON *json_obj, const char *key, MathiJSON *value)`
- `int mathison_get_value(MathiJSON *json_obj, const char *key, MathiJSON **value)`
- `int mathison_remove_key(MathiJSON *json_obj, const char *key)`
- `bool mathison_has_key(MathiJSON *json_obj, const char *key)`
- `int mathison_parse(const char *str, MathiJSON **json_obj)`
- `int mathison_serialize(MathiJSON *json_obj, char **output)`
- `int mathison_validate_type(MathiJSON *json_obj, int expected_type)`

#### Math & Physics (`mathphy.c`)
- `int mathi_matrix_inverse(double **matrix, double **inverse, int n)`
- `int mathi_linear_solver(double **A, double *b, double *x, int n)`
- `Complex mathi_complex_new(double real, double imag)`
- `Complex mathi_complex_add(Complex a, Complex b)`
- `Complex mathi_complex_sub(Complex a, Complex b)`
- `Complex mathi_complex_mul(Complex a, Complex b)`
- `Complex mathi_complex_div(Complex a, Complex b)`
- `double mathi_complex_abs(Complex a)`

#### Matrix (`matrix.c`)
- `void mathi_matrix_add(int **a, int **b, int **res, int rows, int cols)`
- `void mathi_matrix_sub(int **a, int **b, int **res, int rows, int cols)`
- `void mathi_matrix_mul(int **a, int **b, int **res, int n)`
- `void mathi_matrix_transpose(int **a, int **res, int rows, int cols)`
- `int mathi_matrix_determinant(int **a, int n)`
- `void mathi_matrix_identity(int **res, int n)`
- `void mathi_matrix_scalar_mul(int **a, int scalar, int **res, int rows, int cols)`

#### Networking (`networking.c`)
- `int mathi_connect_tcp(const char *host, int port)`
- `int mathi_send_tcp(int sock, const char *data, size_t size)`
- `int mathi_recv_tcp(int sock, char *buffer, size_t size)`
- `int mathi_connect_udp(const char *host, int port)`
- `int mathi_send_udp(int sock, const char *data, size_t size, const char *host, int port)`
- `int mathi_recv_udp(int sock, char *buffer, size_t size)`

#### Print Utilities (`print.c`)
- `void mathi_prnt_linked_list(Node *head, const char *name)`
- `void mathi_prnt_arr(int *arr, int n, const char *name)`
- `void mathi_prnt_matrix(int *m[], int rows, int cols, const char *name)`
- `void mathi_prnt_str(const char *label, const char *str)`
- `void mathi_prnt_bytes(const unsigned char *data, size_t len, const char *name)`
- `void mathi_prnt_int_pair(const char *label, int a, int b)`
- `void mathi_prnt_double_pair(const char *label, double x, double y)`
- `void mathi_prnt_char_pair(const char *label, char c1, char c2)`
- `void mathi_prnt_mem(const char *label, char *mem, size_t n)`

#### Search (`search.c`)
- `int mathi_linear_search(int *arr, int n, int key)`
- `int mathi_binary_search(int *arr, int n, int key)`
- `int mathi_jump_search(int *arr, int n, int key)`
- `int mathi_interpolation_search(int *arr, int n, int key)`

#### Sort (`sort.c`)
- `void mathi_bubble_sort(int *arr, int n)`
- `void mathi_selection_sort(int *arr, int n)`
- `void mathi_insertion_sort(int *arr, int n)`
- `void mathi_merge_sort(int *arr, int n)`
- `void mathi_quick_sort(int *arr, int n)`
- `void mathi_heap_sort(int *arr, int n)`
- `void mathi_counting_sort(int *arr, int n, int max)`

#### Stats (`stats.c`)
- `double mathi_mean(int *arr, int n)`
- `int cmp_int(const void *a, const void *b)`
- `double mathi_median(int *arr, int n)`
- `double mathi_variance(int *arr, int n)`
- `double mathi_stddev(int *arr, int n)`
- `int mathi_mode(int *arr, int n)`
- `double mathi_percentile(int *arr, int n, double p)`

#### String Utilities (`stringx.c`)
- `int mathi_string_index_of(const char *str, char c)`
- `int mathi_string_contains(const char *str, char c)`
- `int mathi_string_count_char(const char *str, char c)`
- `int mathi_string_length(const char *str)`
- `int mathi_string_compare(const char *a, const char *b)`
- `int mathi_string_starts_with(const char *str, const char *prefix)`
- `int mathi_string_ends_with(const char *str, const char *suffix)`

#### System (`sys.c`)
- `int mathi_set_env(const char *name, const char *value, int overwrite)`

#### Time Utilities (`timeutil.c`)
- `long mathi_current_timestamp()`
- `void mathi_format_time(char *buffer, size_t size)`
- `void mathi_sleep_ms(int ms)`
- `int mathi_elapsed_seconds(long start, long end)`

#### Utilities (`util.c`)
- `void mathi_swap_int(int *a, int *b)`
- `void mathi_swap_double(double *a, double *b)`
- `void mathi_swap_char(char *a, char *b)`
- `int mathi_clamp_int(int value, int min, int max)`
- `double mathi_clamp_double(double value, double min, double max)`
- `void mathi_mem_zero(void *ptr, size_t size)`
- `void mathi_mem_copy(void *dest, const void *src, size_t size)`
- `void mathi_mem_swap(void *a, void *b, size_t size)`

#### Validator (`validator.c`)
- `int mathi_is_int(const char *str)`
- `int mathi_is_float(const char *str)`
- `int mathi_is_double(const char *str)`
- `int mathi_is_number(const char *str)`
- `int mathi_is_alpha(const char *str)`
- `int mathi_is_alnum(const char *str)`
- `int mathi_is_binary(const char *str)`
- `int mathi_is_hex(const char *str)`
- `int mathi_in_range(int value, int min, int max)`


---

## Project Structure

```text
.
├── build
│   ├── bin
│   │   ├── algo_test
│   │   ├── array_test
│   │   ├── codec_test
│   │   ├── config_test
│   │   ├── conversion_test
│   │   ├── crypto_test
│   │   ├── ds_advanced_test
│   │   ├── ds_test
│   │   ├── filex_test
│   │   ├── inputx_test
│   │   ├── logx_test
│   │   ├── mathison_test
│   │   ├── mathphy_test
│   │   └── mathx_test
│   ├── lib
│   │   └── libmathi.a
│   └── obj
│       ├── algo.o
│       ├── array.o
│       ├── codec.o
│       ├── config.o
│       ├── conversion.o
│       ├── crypto.o
│       ├── ds_advanced.o
│       ├── ds.o
│       ├── filex.o
│       ├── inputx.o
│       ├── logx.o
│       ├── mathison.o
│       ├── mathphy.o
│       ├── mathx.o
│       ├── matrix.o
│       ├── networking.o
│       ├── print.o
│       ├── search.o
│       ├── sort.o
│       ├── stats.o
│       ├── stringx.o
│       ├── sys.o
│       ├── timeutil.o
│       ├── util.o
│       └── validator.o
├── include
│   └── mathi
│       ├── algo.h
│       ├── array.h
│       ├── codec.h
│       ├── config.h
│       ├── conversion.h
│       ├── crypto.h
│       ├── ds_advanced.h
│       ├── ds.h
│       ├── filex.h
│       ├── inputx.h
│       ├── logx.h
│       ├── mathi.h
│       ├── mathison.h
│       ├── mathphy.h
│       ├── mathx.h
│       ├── matrix.h
│       ├── networking.h
│       ├── print.h
│       ├── search.h
│       ├── sort.h
│       ├── stats.h
│       ├── stringx.h
│       ├── sys.h
│       ├── timeutil.h
│       ├── util.h
│       └── validator.h
├── LICENSE
├── Makefile
├── README.md
├── src
│   ├── algo.c
│   ├── array.c
│   ├── codec.c
│   ├── config.c
│   ├── conversion.c
│   ├── crypto.c
│   ├── ds_advanced.c
│   ├── ds.c
│   ├── filex.c
│   ├── inputx.c
│   ├── logx.c
│   ├── mathison.c
│   ├── mathphy.c
│   ├── mathx.c
│   ├── matrix.c
│   ├── networking.c
│   ├── print.c
│   ├── search.c
│   ├── sort.c
│   ├── stats.c
│   ├── stringx.c
│   ├── sys.c
│   ├── timeutil.c
│   ├── util.c
│   └── validator.c
└── tests
    ├── algo_test.c
    ├── array_test.c
    ├── codec_test.c
    ├── config_test.c
    ├── conversion_test.c
    ├── crypto_test.c
    ├── ds_advanced_test.c
    ├── ds_test.c
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

```bash
git clone https://github.com/macharia-nyamu/mathi_c.git
cd mathi_c
make # generate the .o and .a files
make tests # generate the binn files
make clean # clean the build dir

```

---

## Running Individual Tests

After running `make tests`, you can run each test binary directly:

```bash
./build/bin/algo_test
./build/bin/array_test
./build/bin/codec_test
./build/bin/config_test
./build/bin/conversion_test
./build/bin/crypto_test
./build/bin/ds_test
./build/bin/ds_advanced_test
./build/bin/filex_test
./build/bin/inputx_test
./build/bin/logx_test
./build/bin/mathison_test
./build/bin/mathphy_test
./build/bin/mathx_test
./build/bin/matrix_test
./build/bin/networking_test
./build/bin/search_test
./build/bin/sort_test
./build/bin/stats_test
./build/bin/stringx_test
./build/bin/sys_test
./build/bin/timeutil_test
./build/bin/util_test
./build/bin/validator_test
```

---

### Contributing

Contributions are welcome!
    Fork the repository
    Create a new branch
    Make your changes and add tests
    Submit a pull request

---

## License

This project is licensed under the [MIT License](https://opensource.org/licenses/MIT) – see the LICENSE file for details.