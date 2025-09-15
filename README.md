# Mathi C Library

Mathi C is a collection of C modules providing algorithms, data structures, file utilities, math utilities, string utilities, and time utilities.

## Project Structure

.
├── build  
├── docs  
├── include  
└── src  

- `src/` – source code files  
- `include/mathi/` – library headers  
- `docs/` – additional documentation  
- `build/` – compiled objects and binaries  

## Features / Modules

- **Algo** – algorithm implementations  
- **Array** – array utilities  
- **DS** – data structures  
- **Filex** – file utilities  
- **Mathx** – math utilities  
- **Stringx** – string utilities  
- **Timeutil** – time and date utilities  
- **Util** – general utilities  

## Installation / Build

To build the library using the provided Makefile:


## Tests Commands
gcc tests/algo_test.c src/algo.c -I./include -lm -o build/bin/algo_test
./build/bin/algo_test

gcc tests/array_test.c src/array.c -I./include -lm -o build/bin/array_test
./build/bin/array_test

gcc tests/codec_test.c src/codec.c -I./include -lm -o build/bin/codec_test
./build/bin/codec_test

gcc tests/config_test.c src/config.c -I./include -lm -o build/bin/config_test
./build/bin/config_test

gcc tests/conversion_test.c src/conversion.c -I./include -lm -o build/bin/conversion_test
./build/bin/conversion_test

gcc tests/crypto_test.c src/crypto.c -I./include -lm -o build/bin/crypto_test
./build/bin/crypto_test

gcc tests/ds_test.c src/ds.c -I./include -lm -o build/bin/ds_test
./build/bin/ds_test

gcc tests/dsx_test.c src/dsx.c -I./include -lm -o build/bin/dsx_test
./build/bin/dsx_test

gcc tests/filex_test.c src/filex.c -I./include -lm -o build/bin/filex_test
./build/bin/filex_test

gcc tests/inputx_test.c src/inputx.c src/validator.c -I./include -lm -o build/bin/inputx_test
./build/bin/inputx_test

gcc tests/logx_test.c src/logx.c -I./include -lm -o build/bin/logx_test
./build/bin/logx_test

gcc tests/mathison_test.c src/mathison.c -I./include -lm -o build/bin/mathison_test
./build/bin/mathison_test

gcc tests/mathphy_test.c src/mathphy.c -I./include -lm -o build/bin/mathphy_test
./build/bin/mathphy_test

gcc tests/mathx_test.c src/mathx.c -I./include -lm -o build/bin/mathx_test
./build/bin/mathx_test

gcc tests/matrix_test.c src/matrix.c -I./include -lm -o build/bin/matrix_test
./build/bin/matrix_test

gcc tests/networking_test.c src/networking.c -I./include -lm -o build/bin/networking_test
./build/bin/networking_test

gcc tests/search_test.c src/search.c -I./include -lm -o build/bin/search_test
./build/bin/search_test

gcc tests/sort_test.c src/sort.c -I./include -lm -o build/bin/sort_test
./build/bin/sort_test

gcc tests/stats_test.c src/stats.c -I./include -lm -o build/bin/stats_test
./build/bin/stats_test

gcc tests/stringx_test.c src/stringx.c -I./include -lm -o build/bin/stringx_test
./build/bin/stringx_test

gcc tests/sys_test.c src/sys.c -I./include -lm -o build/bin/sys_test
./build/bin/sys_test

gcc tests/timeutil_test.c src/timeutil.c -I./include -lm -o build/bin/timeutil_test
./build/bin/timeutil_test

gcc tests/util_test.c src/util.c -I./include -lm -o build/bin/util_test
./build/bin/util_test

gcc tests/validator_test.c src/validator.c -I./include -lm -o build/bin/validator_test
./build/bin/validator_test


## License

This project is licensed under the MIT License – see the [LICENSE](LICENSE) file for details.