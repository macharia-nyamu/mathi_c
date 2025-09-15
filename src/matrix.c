/*
* Mathi C Library
* Copyright (c) 2025 Macharia Nyamū
* Licensed under the MIT License. See LICENSE file in the project root for details.
*/

#include <stdio.h>
#include <stdlib.h>

void matrix_add(int **a, int **b, int **res, int rows, int cols) {
    for(int i = 0; i < rows; i++)
        for(int j = 0; j < cols; j++)
            res[i][j] = a[i][j] + b[i][j];
}

void matrix_sub(int **a, int **b, int **res, int rows, int cols) {
    for(int i = 0; i < rows; i++)
        for(int j = 0; j < cols; j++)
            res[i][j] = a[i][j] - b[i][j];
}

void matrix_mul(int **a, int **b, int **res, int n) {
    for(int i = 0; i < n; i++)
        for(int j = 0; j < n; j++) {
            res[i][j] = 0;
            for(int k = 0; k < n; k++) res[i][j] += a[i][k] * b[k][j];
        }
}

void matrix_transpose(int **a, int **res, int rows, int cols) {
    for(int i = 0; i < rows; i++)
        for(int j = 0; j < cols; j++)
            res[j][i] = a[i][j];
}

static int determinant_recursive(int **a, int n) {
    if(n == 1) return a[0][0];
    if(n == 2) return a[0][0]*a[1][1] - a[0][1]*a[1][0];
    int det = 0;
    for(int c = 0; c < n; c++) {
        int **sub = malloc((n-1) * sizeof(int*));
        for(int i = 0; i < n-1; i++) sub[i] = malloc((n-1) * sizeof(int));
        for(int i = 1; i < n; i++) {
            int colIndex = 0;
            for(int j = 0; j < n; j++) {
                if(j == c) continue;
                sub[i-1][colIndex++] = a[i][j];
            }
        }
        int sign = (c % 2 == 0) ? 1 : -1;
        det += sign * a[0][c] * determinant_recursive(sub, n-1);
        for(int i = 0; i < n-1; i++) free(sub[i]);
        free(sub);
    }
    return det;
}

int matrix_determinant(int **a, int n) {
    return determinant_recursive(a, n);
}

void matrix_identity(int **res, int n) {
    for(int i = 0; i < n; i++)
        for(int j = 0; j < n; j++)
            res[i][j] = (i == j) ? 1 : 0;
}

void matrix_scalar_mul(int **a, int scalar, int **res, int rows, int cols) {
    for(int i = 0; i < rows; i++)
        for(int j = 0; j < cols; j++)
            res[i][j] = a[i][j] * scalar;
}