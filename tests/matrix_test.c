/*
* Mathi C Library - matrix_test_verbose.c
* Copyright (c) 2025 Macharia Nyamū
* Licensed under the MIT License. See LICENSE file in the project root for details.
*/

#include <stdio.h>
#include <stdlib.h>
#include <assert.h>
#include "mathi/matrix.h"
#include "mathi/print.h"

#define N 2

void test_matrix_add_sub() 
{
    printf("Test: Matrix Add/Subtract \n");

    int a[N][N] = {{1,2},{3,4}};
    int b[N][N] = {{5,6},{7,8}};
    int res[N][N];

    int *pa[N], *pb[N], *pres[N];
    for(int i=0;i<N;i++){ pa[i]=a[i]; pb[i]=b[i]; pres[i]=res[i]; }

    mathi_matrix_add(pa, pb, pres, N, N);
    mathi_prnt_matrix(pres, N, N, "Matrix Addition Result");
    assert(res[0][0]==6 && res[1][1]==12);

    mathi_matrix_sub(pa, pb, pres, N, N);
    mathi_prnt_matrix(pres, N, N, "Matrix Subtraction Result");
    assert(res[0][0]==-4 && res[1][1]==-4);
}

void test_matrix_mul_transpose() 
{
    printf("\nTest: Matrix Multiply/Transpose \n");

    int a[N][N] = {{1,2},{3,4}};
    int b[N][N] = {{2,0},{1,2}};
    int res[N][N];

    int *pa[N], *pb[N], *pres[N];
    for(int i=0;i<N;i++){ pa[i]=a[i]; pb[i]=b[i]; pres[i]=res[i]; }

    mathi_matrix_mul(pa, pb, pres, N);
    mathi_prnt_matrix(pres, N, N, "Matrix Multiplication Result");
    assert(res[0][0]==4 && res[1][1]==8);

    mathi_matrix_transpose(pa, pres, N, N);
    mathi_prnt_matrix(pres, N, N, "Matrix Transpose Result");
    assert(res[0][1]==3 && res[1][0]==2);
}

void test_determinant_identity_scalar() 
{
    printf("\nTest: Determinant, Identity, Scalar Multiply \n");

    int a[N][N] = {{1,2},{3,4}};
    int res[N][N];

    int *pa[N], *pres[N];
    for(int i=0;i<N;i++){ pa[i]=a[i]; pres[i]=res[i]; }

    int det = mathi_matrix_determinant(pa, N);
    printf("Determinant: %d\n", det);
    assert(det == -2);

    mathi_matrix_identity(pres, N);
    mathi_prnt_matrix(pres, N, N, "Identity Matrix");
    assert(res[0][0]==1 && res[1][1]==1 && res[0][1]==0);

    mathi_matrix_scalar_mul(pa, 2, pres, N, N);
    mathi_prnt_matrix(pres, N, N, "Scalar Multiplication Result");
    assert(res[0][0]==2 && res[1][1]==8);
}

int main() 
{
    test_matrix_add_sub();
    test_matrix_mul_transpose();
    test_determinant_identity_scalar();

    printf("\nAll matrix tests passed successfully!\n");
    return 0;
}