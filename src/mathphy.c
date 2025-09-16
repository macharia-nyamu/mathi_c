/*
* Mathi C Library - Physics & Math Module
* mathphy.c
* 
* Provides matrix operations, linear solvers, and complex number arithmetic.
* Currently, matrix routines are placeholders.
* 
* Copyright (c) 2025 Macharia Nyamū
* Licensed under the MIT License. See LICENSE file in the project root for details.
*/

#include "mathi/mathphy.h"
#include <stdlib.h>
#include <math.h>


/**
 * @brief Placeholder for computing the determinant of an n x n matrix.
 * @param matrix Pointer to an array of n pointers, each pointing to an array of n doubles.
 * @param n Size of the square matrix.
 * @return Currently returns 0.0 (not implemented).
 */
double mathi_matrix_determinant(double **matrix, int n) 
{ 
    return 0.0; 
}

/**
 * @brief Placeholder for computing the inverse of an n x n matrix.
 * @param matrix Input matrix.
 * @param inverse Output matrix to store the inverse.
 * @param n Size of the square matrix.
 * @return Currently returns 0 (failure/not implemented).
 */
int mathi_matrix_inverse(double **matrix, double **inverse, int n) 
{ 
    return 0; 
}

/**
 * @brief Placeholder for solving a linear system Ax = b.
 * @param A Coefficient matrix.
 * @param b Right-hand side vector.
 * @param x Output solution vector.
 * @param n Size of the system.
 * @return Currently returns 0 (failure/not implemented).
 */
int mathi_linear_solver(double **A, double *b, double *x, int n) 
{ 
    return 0; 
}


/**
 * @brief Create a new complex number.
 * @param real Real part.
 * @param imag Imaginary part.
 * @return Complex number struct.
 */
Complex mathi_complex_new(double real, double imag) 
{ 
    Complex c = {real, imag};  // using brace-initialization for struct
    return c; 
}

/**
 * @brief Add two complex numbers.
 */
Complex mathi_complex_add(Complex a, Complex b) 
{ 
    return mathi_complex_new(a.real + b.real, a.imag + b.imag); 
}

/**
 * @brief Subtract two complex numbers.
 */
Complex mathi_complex_sub(Complex a, Complex b) 
{ 
    return mathi_complex_new(a.real - b.real, a.imag - b.imag); 
}

/**
 * @brief Multiply two complex numbers.
 */
Complex mathi_complex_mul(Complex a, Complex b) 
{ 
    return mathi_complex_new(
        a.real * b.real - a.imag * b.imag,  // real part
        a.real * b.imag + a.imag * b.real   // imaginary part
    ); 
}

/**
 * @brief Divide two complex numbers.
 * @note Returns 0+0i if denominator is zero to prevent division by zero.
 */
Complex mathi_complex_div(Complex a, Complex b) 
{
    double denom = b.real * b.real + b.imag * b.imag;
    if (denom == 0) return mathi_complex_new(0, 0);
    return mathi_complex_new(
        (a.real * b.real + a.imag * b.imag) / denom, 
        (a.imag * b.real - a.real * b.imag) / denom
    );
}

/**
 * @brief Absolute value (magnitude) of a complex number.
 */
double mathi_complex_abs(Complex a) 
{ 
    return sqrt(a.real * a.real + a.imag * a.imag); 
}