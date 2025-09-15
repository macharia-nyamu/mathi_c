/**
 * Mathi C Library - Main Header
 * 
 * This header includes all core modules of the Mathi C Library, providing
 * access to algorithms, data structures, file utilities, conversions,
 * networking, system utilities, and more.
 * 
 * @file mathi.h
 * @author Macharia Nyamū
 * @date 2025
 * @license MIT
 * 
 * Licensed under the MIT License. See LICENSE file in the project root for details.
 */

#ifndef MATHI_MATHI_H
#define MATHI_MATHI_H

/* ---------------- Fundamental / Core ---------------- */
#include "util.h"       // Core utilities used by many modules
#include "validator.h"  // Validation helpers for input and data
#include "array.h"      // Basic array utilities
#include "algo.h"       // Algorithm utilities (sorting, searching)
#include "ds.h"         // Core data structures (linked list, stack, queue, hash)
#include "dsx.h"        // Advanced / generic data structures (heap, graph, trie, hashmap)
#include "mathx.h"      // Mathematical extensions (basic math functions)
#include "mathphy.h"    // Physical / scientific math functions

/* ---------------- Conversion & Codec ---------------- */
#include "conversion.h" // Number/string conversions
#include "codec.h"      // Encoding/decoding (Base64, RLE, etc.)
#include "crypto.h"     // Crypto functions (hashes, checksum, XOR cipher)

/* ---------------- Input / Config ---------------- */
#include "inputx.h"     // Input handling
#include "config.h"     // Configuration files

/* ---------------- File, Logging, System ---------------- */
#include "filex.h"      // File utilities
#include "logx.h"       // Logging
#include "sys.h"        // System utilities

/* ---------------- Higher-level modules ---------------- */
#include "sort.h"       // Sorting (relies on arrays / algo)
#include "search.h"     // Searching (relies on arrays / algo)
#include "stats.h"      // Statistical functions (arrays / math)
#include "matrix.h"     // Matrix utilities (arrays / math)
#include "networking.h" // Networking utilities
#include "stringx.h"    // String extensions (may use validator/util)

#endif