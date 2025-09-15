/*
* Mathi C Library - mathphy_test_verbose.c
* Copyright (c) 2025 Macharia Nyamū
* Licensed under the MIT License. See LICENSE file in the project root for details.
*/

#include <stdio.h>
#include <stdlib.h>
#include <assert.h>
#include "mathi/mathphy.h"
#include <math.h>

void test_complex_operations() {
    printf("Testing complex operations...\n");

    Complex a = complex_new(1.0, 2.0);
    Complex b = complex_new(3.0, 4.0);

    printf("a = %.2f + %.2fi\n", a.real, a.imag);
    printf("b = %.2f + %.2fi\n", b.real, b.imag);

    Complex c = complex_add(a, b);
    printf("a + b = %.2f + %.2fi\n", c.real, c.imag);
    assert(c.real == 4.0 && c.imag == 6.0);

    c = complex_sub(b, a);
    printf("b - a = %.2f + %.2fi\n", c.real, c.imag);
    assert(c.real == 2.0 && c.imag == 2.0);

    c = complex_mul(a, b);
    printf("a * b = %.2f + %.2fi\n", c.real, c.imag);
    assert(c.real == -5.0 && c.imag == 10.0);

    c = complex_div(a, b);
    double denom = 3*3 + 4*4;
    printf("a / b = %.6f + %.6fi\n", c.real, c.imag);
    assert(fabs(c.real - (1*3 + 2*4)/denom) < 1e-6);
    assert(fabs(c.imag - (2*3 - 1*4)/denom) < 1e-6);

    double abs_val = complex_abs(a);
    printf("|a| = %.6f\n", abs_val);
    assert(fabs(abs_val - sqrt(5.0)) < 1e-6);
}

void test_matrix_placeholders() {
    printf("Testing matrix placeholder functions...\n");

    double *mat[2];
    double row0[2] = {1, 2};
    double row1[2] = {3, 4};
    mat[0] = row0; mat[1] = row1;

    printf("Matrix:\n");
    for(int i=0;i<2;i++) printf("[%.2f, %.2f]\n", mat[i][0], mat[i][1]);

    double **inv = NULL; // placeholder
    double b[2] = {1, 1};
    double x[2] = {0, 0};

    double det = matrix_determinant(mat, 2);
    printf("Determinant = %.6f\n", det);
    assert(fabs(det - 0.0) < 1e-6);

    int inv_code = matrix_inverse(mat, inv, 2);
    printf("matrix_inverse returned %d\n", inv_code);
    assert(inv_code == 0);

    int solve_code = linear_solver(mat, b, x, 2);
    printf("linear_solver returned %d, solution x = [%.2f, %.2f]\n", solve_code, x[0], x[1]);
    assert(solve_code == 0);
}

int main() {
    test_complex_operations();
    test_matrix_placeholders();

    printf("All mathphy static tests passed successfully!\n");
    return 0;
}