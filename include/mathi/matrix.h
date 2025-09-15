/**
 * Mathi C Library - Matrix Utilities
 * 
 * Provides basic matrix operations: addition, subtraction, multiplication, transpose,
 * determinant calculation, identity matrix creation, and scalar multiplication.
 * 
 * Status codes:
 * 0 - SUCCESS
 * 1 - INVALID_INPUT
 * 2 - MATRIX_ERROR
 * 3 - UNKNOWN_ERROR
 * 
 * @file matrix.h
 * @author Macharia Nyamū
 * @date 2025
 * @license MIT
 * 
 * Licensed under the MIT License. You may obtain a copy of the License at
 * https://opensource.org/licenses/MIT
 */

#ifndef MATHI_MATRIX_H
#define MATHI_MATRIX_H

/* ----- Matrix Operations ----- */

/**
 * @brief Add two matrices.
 * @param a First matrix
 * @param b Second matrix
 * @param res Result matrix
 * @param rows Number of rows
 * @param cols Number of columns
 */
void matrix_add(int **a, int **b, int **res, int rows, int cols);

/**
 * @brief Subtract matrix b from matrix a.
 * @param a First matrix
 * @param b Second matrix
 * @param res Result matrix
 * @param rows Number of rows
 * @param cols Number of columns
 */
void matrix_sub(int **a, int **b, int **res, int rows, int cols);

/**
 * @brief Multiply two square matrices of size n x n.
 * @param a First matrix
 * @param b Second matrix
 * @param res Result matrix
 * @param n Size of the square matrices
 */
void matrix_mul(int **a, int **b, int **res, int n);

/**
 * @brief Transpose a matrix.
 * @param a Input matrix
 * @param res Result matrix
 * @param rows Number of rows
 * @param cols Number of columns
 */
void matrix_transpose(int **a, int **res, int rows, int cols);

/**
 * @brief Compute the determinant of a square matrix.
 * @param a Input matrix (n x n)
 * @param n Size of the square matrix
 * @return Determinant value
 */
int matrix_determinant(int **a, int n);

/**
 * @brief Create an identity matrix of size n x n.
 * @param res Result matrix
 * @param n Size of the matrix
 */
void matrix_identity(int **res, int n);

/**
 * @brief Multiply a matrix by a scalar.
 * @param a Input matrix
 * @param scalar Scalar value
 * @param res Result matrix
 * @param rows Number of rows
 * @param cols Number of columns
 */
void matrix_scalar_mul(int **a, int scalar, int **res, int rows, int cols);

#endif