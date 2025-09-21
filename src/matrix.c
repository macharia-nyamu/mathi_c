/*
* Mathi C Library
* Copyright (c) 2025 Macharia Nyamū
* Licensed under the MIT License. See LICENSE file in the project root for details.
*/

#include <stdio.h>
#include <stdlib.h>

/**
 * @brief Add two matrices.
 * @param a First input matrix.
 * @param b Second input matrix.
 * @param res Result matrix (a + b).
 * @param rows Number of rows.
 * @param cols Number of columns.
 */
void mathi_matrix_add(int **a, int **b, int **res, int rows, int cols)
{
    for(int i = 0; i < rows; i++)
        for(int j = 0; j < cols; j++)
            res[i][j] = a[i][j] + b[i][j];
}

/**
 * @brief Subtract one matrix from another.
 * @param a First input matrix.
 * @param b Second input matrix.
 * @param res Result matrix (a - b).
 * @param rows Number of rows.
 * @param cols Number of columns.
 */
void mathi_matrix_sub(int **a, int **b, int **res, int rows, int cols)
{
    for(int i = 0; i < rows; i++)
        for(int j = 0; j < cols; j++)
            res[i][j] = a[i][j] - b[i][j];
}

/**
 * @brief Multiply two square matrices.
 * @param a First input matrix.
 * @param b Second input matrix.
 * @param res Result matrix (a * b).
 * @param n Size of the square matrices.
 */
void mathi_matrix_mul(int **a, int **b, int **res, int n)
{
    for(int i = 0; i < n; i++)
        for(int j = 0; j < n; j++)
        {
            res[i][j] = 0;
            for(int k = 0; k < n; k++)
                res[i][j] += a[i][k] * b[k][j];
        }
}

/**
 * @brief Transpose a matrix.
 * @param a Input matrix.
 * @param res Transposed matrix.
 * @param rows Number of rows in input.
 * @param cols Number of columns in input.
 */
void mathi_matrix_transpose(int **a, int **res, int rows, int cols)
{
    for(int i = 0; i < rows; i++)
        for(int j = 0; j < cols; j++)
            res[j][i] = a[i][j];
}

/**
 * @brief Compute determinant of a square matrix (recursive, allocates temporary submatrices).
 * @param a Input matrix (n x n).
 * @param n Size of the matrix.
 * @return Determinant of the matrix.
 */
int mathi_matrix_determinant(int **a, int n)
{
    if(n == 1) return a[0][0];
    if(n == 2) return a[0][0]*a[1][1] - a[0][1]*a[1][0];

    int det = 0;

    for(int c = 0; c < n; c++)
    {
        int **sub = malloc((n-1) * sizeof(int*));
        for(int i = 0; i < n-1; i++)
            sub[i] = malloc((n-1) * sizeof(int));

        for(int i = 1; i < n; i++)
        {
            int colIndex = 0;
            for(int j = 0; j < n; j++)
            {
                if(j == c) continue;
                sub[i-1][colIndex++] = a[i][j];
            }
        }

        int sign = (c % 2 == 0) ? 1 : -1;
        det += sign * a[0][c] * mathi_matrix_determinant(sub, n-1);

        for(int i = 0; i < n-1; i++) free(sub[i]);
        free(sub);
    }

    return det;
}


/**
 * @brief Generate an identity matrix.
 * @param res Result identity matrix.
 * @param n Size of the square matrix.
 */
void mathi_matrix_identity(int **res, int n)
{
    for(int i = 0; i < n; i++)
        for(int j = 0; j < n; j++)
            res[i][j] = (i == j) ? 1 : 0;
}

/**
 * @brief Multiply a matrix by a scalar.
 * @param a Input matrix.
 * @param scalar Scalar value to multiply.
 * @param res Result matrix.
 * @param rows Number of rows.
 * @param cols Number of columns.
 */
void mathi_matrix_scalar_mul(int **a, int scalar, int **res, int rows, int cols)
{
    for(int i = 0; i < rows; i++)
        for(int j = 0; j < cols; j++)
            res[i][j] = a[i][j] * scalar;
}