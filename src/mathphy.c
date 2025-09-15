/*
* Mathi C Library
* Copyright (c) 2025 Macharia Nyamū
* Licensed under the MIT License. See LICENSE file in the project root for details.
*/

#include "mathi/mathphy.h"
#include <stdlib.h>
#include <math.h>

/* Matrix routines placeholders */
double matrix_determinant(double **matrix, int n) { return 0.0; }
int matrix_inverse(double **matrix, double **inverse, int n) { return 0; }
int linear_solver(double **A, double *b, double *x, int n) { return 0; }

/* Complex numbers */
Complex complex_new(double real, double imag) { Complex c={real,imag}; return c; }
Complex complex_add(Complex a, Complex b) { return complex_new(a.real+b.real, a.imag+b.imag); }
Complex complex_sub(Complex a, Complex b) { return complex_new(a.real-b.real, a.imag-b.imag); }
Complex complex_mul(Complex a, Complex b) { return complex_new(a.real*b.real - a.imag*b.imag, a.real*b.imag + a.imag*b.real); }
Complex complex_div(Complex a, Complex b) {
    double denom = b.real*b.real + b.imag*b.imag;
    if(denom==0) return complex_new(0,0);
    return complex_new((a.real*b.real+a.imag*b.imag)/denom, (a.imag*b.real-a.real*b.imag)/denom);
}
double complex_abs(Complex a) { return sqrt(a.real*a.real + a.imag*a.imag); }