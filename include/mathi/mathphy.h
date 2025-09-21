/*
 * Mathi C Library - Math & Physics Module
 * mathphy.h
 * 
 * Copyright (c) 2025 Macharia Nyamū
 * Licensed under the MIT License. See LICENSE file in the project root for details.
 */

#ifndef MATHI_MATHPHY_H
#define MATHI_MATHPHY_H

#include <stddef.h>

/**
 * @file mathi/mathphy.h
 * @brief Math and physics utilities: matrices, linear algebra, and complex numbers.
 */


/**
 * @struct Complex
 * @brief Structure representing a complex number.
 */
typedef struct {
    double real; /**< Real part */
    double imag; /**< Imaginary part */
} Complex;

/**
 * @brief Create a new complex number.
 * @param real Real part.
 * @param imag Imaginary part.
 * @return Complex number.
 */
Complex mathi_complex_new(double real, double imag);

/**
 * @brief Add two complex numbers.
 */
Complex mathi_complex_add(Complex a, Complex b);

/**
 * @brief Subtract two complex numbers.
 */
Complex mathi_complex_sub(Complex a, Complex b);

/**
 * @brief Multiply two complex numbers.
 */
Complex mathi_complex_mul(Complex a, Complex b);

/**
 * @brief Divide two complex numbers.
 */
Complex mathi_complex_div(Complex a, Complex b);

/**
 * @brief Compute the absolute value (magnitude) of a complex number.
 */
double mathi_complex_abs(Complex a);


/**
 * @brief Compute the inverse of a square matrix.
 * @param matrix Pointer to the original 2D array of doubles.
 * @param inverse Pointer to the 2D array to store the inverse.
 * @param n Dimension of the square matrix.
 */
int mathi_matrix_inverse(double **matrix, double **inverse, int n);

/**
 * @brief Solve a linear system Ax = b.
 * @param A Pointer to the matrix of coefficients.
 * @param b Pointer to the right-hand side vector.
 * @param x Pointer to the solution vector (output).
 * @param n Dimension of the system.
 * @return 0 on success, non-zero on failure (currently placeholder).
 */
int mathi_linear_solver(double **A, double *b, double *x, int n);

#endif // MATHI_MATHPHY_H