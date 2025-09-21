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
#include <stdlib.h>

int mathi_linear_solver(double **A, double *b, double *x, int n) 
{
    // Allocate temporary copies
    double **tempA = malloc(n * sizeof(double*));
    double *tempb = malloc(n * sizeof(double));
    if(!tempA || !tempb) return -1; // allocation failure

    for(int i = 0; i < n; i++) 
    {
        tempA[i] = malloc(n * sizeof(double));
        if(!tempA[i]) {
            for(int j = 0; j < i; j++) free(tempA[j]);
            free(tempA);
            free(tempb);
            return -1;
        }
        for(int j = 0; j < n; j++)
            tempA[i][j] = A[i][j];
        tempb[i] = b[i];
    }

    // Gaussian elimination with partial pivoting
    for(int k = 0; k < n; k++) 
    {
        // Find pivot
        int pivotRow = k;
        for(int i = k+1; i < n; i++)
            if(fabs(tempA[i][k]) > fabs(tempA[pivotRow][k]))
                pivotRow = i;

        if(fabs(tempA[pivotRow][k]) < 1e-12) 
        {
            // Singular matrix
            for(int i = 0; i < n; i++) free(tempA[i]);
            free(tempA);
            free(tempb);
            return -2;
        }

        // Swap rows
        if(pivotRow != k) 
        {
            double *tmpRow = tempA[k];
            tempA[k] = tempA[pivotRow];
            tempA[pivotRow] = tmpRow;

            double tmpVal = tempb[k];
            tempb[k] = tempb[pivotRow];
            tempb[pivotRow] = tmpVal;
        }

        // Eliminate
        for(int i = k+1; i < n; i++) 
        {
            double factor = tempA[i][k] / tempA[k][k];
            for(int j = k; j < n; j++)
                tempA[i][j] -= factor * tempA[k][j];
            tempb[i] -= factor * tempb[k];
        }
    }

    // Back substitution
    for(int i = n-1; i >= 0; i--) 
    {
        double sum = tempb[i];
        for(int j = i+1; j < n; j++)
            sum -= tempA[i][j] * x[j];
        x[i] = sum / tempA[i][i];
    }

    // Free temporary memory
    for(int i = 0; i < n; i++) free(tempA[i]);
    free(tempA);
    free(tempb);

    return 0; // success
}

Complex mathi_complex_new(double real, double imag) 
{ 
    Complex c = {real, imag};  
    return c; 
}

Complex mathi_complex_add(Complex a, Complex b) 
{ 
    return mathi_complex_new(a.real + b.real, a.imag + b.imag); 
}

Complex mathi_complex_sub(Complex a, Complex b) 
{ 
    return mathi_complex_new(a.real - b.real, a.imag - b.imag); 
}

Complex mathi_complex_mul(Complex a, Complex b) 
{ 
    return mathi_complex_new(
        a.real * b.real - a.imag * b.imag,  // real part
        a.real * b.imag + a.imag * b.real   // imaginary part
    ); 
}

Complex mathi_complex_div(Complex a, Complex b) 
{
    double denom = b.real * b.real + b.imag * b.imag;
    if (denom == 0) return mathi_complex_new(0, 0);
    return mathi_complex_new(
        (a.real * b.real + a.imag * b.imag) / denom, 
        (a.imag * b.real - a.real * b.imag) / denom
    );
}

double mathi_complex_abs(Complex a) 
{ 
    return sqrt(a.real * a.real + a.imag * a.imag); 
}