# Compiler and flags
CC = gcc
CFLAGS = -Wall -Iinclude

# Directories
SRC_DIR = src
OBJ_DIR = build/obj
LIB_DIR = build/lib
BIN_DIR = build/bin
TEST_DIR = tests

# Source files and objects
SRC = $(wildcard $(SRC_DIR)/*.c)
OBJ = $(patsubst $(SRC_DIR)/%.c,$(OBJ_DIR)/%.o,$(SRC))
LIB = $(LIB_DIR)/libmathi.a

# Test files
TEST_SRC = $(wildcard $(TEST_DIR)/*_test.c)
TEST_BIN = $(patsubst $(TEST_DIR)/%_test.c,$(BIN_DIR)/%_test,$(TEST_SRC))

# Default: build library
all: $(LIB)

# Compile .c -> .o
$(OBJ_DIR)/%.o: $(SRC_DIR)/%.c | $(OBJ_DIR)
	$(CC) $(CFLAGS) -c $< -o $@

# Create directories if missing
$(OBJ_DIR):
	mkdir -p $(OBJ_DIR)

$(LIB_DIR):
	mkdir -p $(LIB_DIR)

$(BIN_DIR):
	mkdir -p $(BIN_DIR)

# Archive object files into static library
$(LIB): $(OBJ) | $(LIB_DIR)
	ar rcs $@ $(OBJ)

# Build all test binaries
tests: $(TEST_BIN)

$(BIN_DIR)/%_test: $(TEST_DIR)/%_test.c $(LIB) | $(BIN_DIR)
	$(CC) $(CFLAGS) $< $(LIB) -lm -o $@

# Clean all build artifacts
clean:
	rm -rf $(OBJ_DIR)/*.o $(LIB_DIR)/*.a $(BIN_DIR)/*

.PHONY: all clean tests