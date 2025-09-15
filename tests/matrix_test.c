/*
* Mathi C Library - matrix_test_verbose.c
* Copyright (c) 2025 Macharia Nyamū
* Licensed under the MIT License. See LICENSE file in the project root for details.
*/

#include <stdio.h>
#include <stdlib.h>
#include <assert.h>
#include "mathi/matrix.h"

#define N 2

void print_matrix(int *m[], int rows, int cols, const char *name) {
    printf("%s:\n", name);
    for(int i=0;i<rows;i++) {
        for(int j=0;j<cols;j++) printf("%d ", m[i][j]);
        printf("\n");
    }
    printf("\n");
}

void test_matrix_add_sub() {
    printf("Testing matrix add/sub...\n");
    int a[N][N] = {{1,2},{3,4}};
    int b[N][N] = {{5,6},{7,8}};
    int res[N][N];

    int *pa[N], *pb[N], *pres[N];
    for(int i=0;i<N;i++){pa[i]=a[i]; pb[i]=b[i]; pres[i]=res[i];}

    matrix_add(pa,pb,pres,N,N);
    print_matrix(pres,N,N,"Matrix Addition Result");
    assert(res[0][0]==6 && res[1][1]==12);

    matrix_sub(pa,pb,pres,N,N);
    print_matrix(pres,N,N,"Matrix Subtraction Result");
    assert(res[0][0]==-4 && res[1][1]==-4);
}

void test_matrix_mul_transpose() {
    printf("Testing matrix mul/transpose...\n");
    int a[N][N] = {{1,2},{3,4}};
    int b[N][N] = {{2,0},{1,2}};
    int res[N][N];

    int *pa[N], *pb[N], *pres[N];
    for(int i=0;i<N;i++){pa[i]=a[i]; pb[i]=b[i]; pres[i]=res[i];}

    matrix_mul(pa,pb,pres,N);
    print_matrix(pres,N,N,"Matrix Multiplication Result");
    assert(res[0][0]==4 && res[1][1]==8);

    matrix_transpose(pa,pres,N,N);
    print_matrix(pres,N,N,"Matrix Transpose Result");
    assert(res[0][1]==3 && res[1][0]==2);
}

void test_determinant_identity_scalar() {
    printf("Testing determinant, identity, scalar mul...\n");
    int a[N][N] = {{1,2},{3,4}};
    int res[N][N];

    int *pa[N], *pres[N];
    for(int i=0;i<N;i++){pa[i]=a[i]; pres[i]=res[i];}

    int det = matrix_determinant(pa,N);
    printf("Determinant: %d\n", det);
    assert(det == -2);

    matrix_identity(pres,N);
    print_matrix(pres,N,N,"Identity Matrix");
    assert(res[0][0]==1 && res[1][1]==1 && res[0][1]==0);

    matrix_scalar_mul(pa,2,pres,N,N);
    print_matrix(pres,N,N,"Scalar Multiplication Result");
    assert(res[0][0]==2 && res[1][1]==8);
}

int main() {
    test_matrix_add_sub();
    test_matrix_mul_transpose();
    test_determinant_identity_scalar();

    printf("All matrix tests passed successfully!\n");
    return 0;
}