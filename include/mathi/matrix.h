/*
 * Mathi C Library - Matrix Utilities
 * mathi_matrix.h
 * 
 * Copyright (c) 2025 Macharia Nyamū
 * Licensed under the MIT License. See LICENSE file in the project root for details.
 */

#ifndef MATHI_MATRIX_H
#define MATHI_MATRIX_H

/**
 * @file mathi/matrix.h
 * @brief Basic matrix operations: addition, subtraction, multiplication, transpose, determinant, identity, and scalar multiplication.
 */

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

#endif // MATHI_MATRIX_H