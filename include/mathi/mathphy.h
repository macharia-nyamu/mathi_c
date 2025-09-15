/**
 * Mathi C Library - Math/Physics Module
 * 
 * Advanced numerical routines: matrices, linear solvers, complex numbers
 * 
 * Status codes:
 * 0 - SUCCESS
 * 1 - MEMORY_ERROR
 * 2 - INVALID_INPUT
 * 3 - MATRIX_ERROR
 * 4 - UNKNOWN_ERROR
 * 
 * @file mathphy.h
 * @author Macharia Nyamū
 * @date 2025
 * @license MIT
 * 
 * Licensed under the MIT License. You may obtain a copy of the License at
 * https://opensource.org/licenses/MIT
 */

#ifndef MATHI_MATHPHY_H
#define MATHI_MATHPHY_H

/* ----- Matrix routines ----- */

/**
 * @brief Compute the determinant of a square matrix.
 * @param matrix Pointer to 2D array (n x n)
 * @param n Size of the square matrix
 * @return Determinant value
 */
double matrix_determinant(double **matrix, int n);

/**
 * @brief Compute the inverse of a square matrix.
 * @param matrix Input matrix (n x n)
 * @param inverse Output matrix to store the inverse
 * @param n Size of the square matrix
 * @return Status code (0 = SUCCESS, 1 = MEMORY_ERROR, 2 = INVALID_INPUT, 3 = MATRIX_ERROR, 4 = UNKNOWN_ERROR)
 */
int matrix_inverse(double **matrix, double **inverse, int n);

/**
 * @brief Solve a linear system Ax = b.
 * @param A Coefficient matrix (n x n)
 * @param b Right-hand side vector
 * @param x Output solution vector
 * @param n Size of the system
 * @return Status code (0 = SUCCESS, 1 = MEMORY_ERROR, 2 = INVALID_INPUT, 3 = MATRIX_ERROR, 4 = UNKNOWN_ERROR)
 */
int linear_solver(double **A, double *b, double *x, int n);

/* ----- Complex numbers ----- */

/**
 * @struct Complex
 * @brief Represents a complex number with real and imaginary parts.
 */
typedef struct Complex {
    double real;
    double imag;
} Complex;

/**
 * @brief Create a new complex number.
 * @param real Real component
 * @param imag Imaginary component
 * @return Complex number
 */
Complex complex_new(double real, double imag);

/**
 * @brief Add two complex numbers.
 * @param a First operand
 * @param b Second operand
 * @return Result of a + b
 */
Complex complex_add(Complex a, Complex b);

/**
 * @brief Subtract two complex numbers.
 * @param a First operand
 * @param b Second operand
 * @return Result of a - b
 */
Complex complex_sub(Complex a, Complex b);

/**
 * @brief Multiply two complex numbers.
 * @param a First operand
 * @param b Second operand
 * @return Result of a * b
 */
Complex complex_mul(Complex a, Complex b);

/**
 * @brief Divide two complex numbers.
 * @param a Numerator
 * @param b Denominator
 * @return Result of a / b
 */
Complex complex_div(Complex a, Complex b);

/**
 * @brief Compute absolute value (magnitude) of a complex number.
 * @param a Complex number
 * @return Magnitude |a|
 */
double complex_abs(Complex a);

#endif