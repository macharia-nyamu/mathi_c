/**
 * Mathi C Library - Main Header
 * 
 * This is the central header of the Mathi C Library, providing unified access 
 * to all core modules, including data structures, algorithms, mathematical 
 * utilities, string handling, file operations, networking, system utilities, 
 * statistics, and printing/logging functions.
 * 
 * By including this header, users gain access to the full suite of Mathi C 
 * Library functionality in a single import.
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


/**
 * @brief Core utilities and helpers
 */
#include "util.h"       

/**
 * @brief Validation helpers for input and data
 */
#include "validator.h"  

/**
 * @brief Basic array utilities (search, manipulation, printing)
 */
#include "array.h"      

/**
 * @brief Algorithms: sorting, searching, and related functions
 */
#include "algo.h"       

/**
 * @brief Core data structures: linked list, stack, queue, hash
 */
#include "ds.h"         

/**
 * @brief Advanced/generic data structures: heap, graph, trie, hashmap
 */
#include "dsx.h"        

/**
 * @brief Mathematical extensions (basic math functions)
 */
#include "mathx.h"      

/**
 * @brief Physical/scientific math functions
 */
#include "mathphy.h"    


/**
 * @brief Number/string conversions
 */
#include "conversion.h" 

/**
 * @brief Encoding/decoding utilities (Base64, RLE, etc.)
 */
#include "codec.h"      

/**
 * @brief Cryptographic utilities (hashes, checksum, XOR cipher)
 */
#include "crypto.h"     


/**
 * @brief Input handling utilities
 */
#include "inputx.h"     

/**
 * @brief Configuration file parsing and handling
 */
#include "config.h"     


/**
 * @brief File utilities (read, write, copy, etc.)
 */
#include "filex.h"      

/**
 * @brief Logging utilities
 */
#include "logx.h"       

/**
 * @brief System utilities (environment, sleep, timestamp, memory)
 */
#include "sys.h"        


/**
 * @brief Sorting utilities (built on arrays and algorithms)
 */
#include "sort.h"       

/**
 * @brief Searching utilities (built on arrays and algorithms)
 */
#include "search.h"     

/**
 * @brief Statistical functions for arrays and numerical data
 */
#include "stats.h"      

/**
 * @brief Matrix utilities (arrays and math)
 */
#include "matrix.h"     

/**
 * @brief Networking utilities (TCP/UDP)
 */
#include "networking.h" 

/**
 * @brief String manipulation extensions
 */
#include "stringx.h"    

/**
 * @brief Printing utilities for arrays, matrices, linked lists, bytes, strings
 */
#include "print.h"      

#endif // MATHI_MATHI_H