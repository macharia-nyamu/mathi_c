# Mathi C Library

[![License: MIT](https://img.shields.io/badge/License-MIT-yellow.svg)](LICENSE)
[![Build Status](https://img.shields.io/github/actions/workflow/status/macharia-nyamu/mathi_c/build.yml)](https://github.com/macharia-nyamu/mathi_c/actions)

Mathi C is a modular C library collection providing algorithms, data structures, file and string utilities, math operations, and time/date utilities — all ready to plug into your C projects.

---

## Project Structure

Mathi C/
├── build/                  # compiled binaries and objects
│   └── bin/                # compiled test binaries
│       ├── algo_test
│       ├── array_test
│       ├── codec_test
│       ├── config_test
│       ├── conversion_test
│       ├── crypto_test
│       ├── ds_test
│       ├── dsx_test
│       ├── filex_test
│       ├── inputx_test
│       ├── logx_test
│       ├── mathison_test
│       ├── mathphy_test
│       ├── mathx_test
│       ├── matrix_test
│       ├── networking_test
│       ├── search_test
│       ├── sort_test
│       ├── stats_test
│       ├── stringx_test
│       ├── sys_test
│       ├── timeutil_test
│       ├── util_test
│       └── validator_test
├── docs/                   # additional documentation
├── include/                # library headers
│   └── mathi/
│       ├── algo.h
│       ├── array.h
│       ├── codec.h
│       ├── config.h
│       ├── conversion.h
│       ├── crypto.h
│       ├── ds.h
│       ├── dsx.h
│       ├── filex.h
│       ├── inputx.h
│       ├── logx.h
│       ├── mathi.h
│       ├── mathison.h
│       ├── mathphy.h
│       ├── mathx.h
│       ├── matrix.h
│       ├── networking.h
│       ├── search.h
│       ├── sort.h
│       ├── stats.h
│       ├── stringx.h
│       ├── sys.h
│       ├── timeutil.h
│       ├── util.h
│       └── validator.h
├── src/                    # source code files
│   ├── algo.c
│   ├── array.c
│   ├── codec.c
│   ├── config.c
│   ├── conversion.c
│   ├── crypto.c
│   ├── ds.c
│   ├── dsx.c
│   ├── filex.c
│   ├── inputx.c
│   ├── logx.c
│   ├── mathison.c
│   ├── mathphy.c
│   ├── mathx.c
│   ├── matrix.c
│   ├── networking.c
│   ├── search.c
│   ├── sort.c
│   ├── stats.c
│   ├── stringx.c
│   ├── sys.c
│   ├── timeutil.c
│   ├── util.c
│   └── validator.c
└── tests/                  # unit tests for all modules
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

<!-- Space for future detailed descriptions of all functions -->

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

Contributing

Contributions are welcome!

    Fork the repository

    Create a new branch

    Make your changes and add tests

    Submit a pull request

License

This project is licensed under the MIT License – see the LICENSE

file for details.