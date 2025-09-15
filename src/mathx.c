/*
* Mathi C Library
* Copyright (c) 2025 Macharia Nyamū
* Licensed under the MIT License. See LICENSE file in the project root for details.
*/

#include <stdio.h>
#include <stdlib.h>
#include <math.h>

int gcd(int a, int b) {
    while(b) {
        int t = b;
        b = a % b;
        a = t;
    }
    return a;
}

int lcm(int a, int b) {
    if(a == 0 || b == 0) return 0;
    return abs(a * b) / gcd(a, b);
}

double factorial(int n) {
    if(n < 0) return -1;
    double res = 1;
    for(int i = 2; i <= n; i++) res *= i;
    return res;
}

double power(double base, int exp) {
    double res = 1;
    int e = exp < 0 ? -exp : exp;
    for(int i = 0; i < e; i++) res *= base;
    return exp < 0 ? 1.0 / res : res;
}

int is_prime(int n) {
    if(n < 2) return 0;
    if(n == 2 || n == 3) return 1;
    if(n % 2 == 0 || n % 3 == 0) return 0;
    for(int i = 5; i * i <= n; i += 6)
        if(n % i == 0 || n % (i + 2) == 0) return 0;
    return 1;
}

int next_prime(int n) {
    if(n < 2) return 2;
    int candidate = n + 1;
    while(!is_prime(candidate)) candidate++;
    return candidate;
}

double sqrt_newton(double x) {
    if(x < 0) return -1;
    double guess = x / 2.0, eps = 1e-9;
    while(fabs(guess * guess - x) > eps) guess = (guess + x / guess) / 2.0;
    return guess;
}

double abs_double(double x) {
    return x < 0 ? -x : x;
}

int abs_int(int x) {
    return x < 0 ? -x : x;
}

int max_int(int a, int b) {
    return a > b ? a : b;
}

int min_int(int a, int b) {
    return a < b ? a : b;
}

double max_double(double a, double b) {
    return a > b ? a : b;
}

double min_double(double a, double b) {
    return a < b ? a : b;
}