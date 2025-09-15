/*
* Mathi C Library - mathx_test_verbose.c
* Copyright (c) 2025 Macharia Nyamū
* Licensed under the MIT License. See LICENSE file in the project root for details.
*/

#include <stdio.h>
#include <stdlib.h>
#include <assert.h>
#include <math.h>
#include "mathi/mathx.h"

void test_gcd_lcm() {
    printf("Testing gcd and lcm...\n");
    
    int a = 12, b = 18;
    int g = gcd(a, b);
    int l = lcm(a, b);
    printf("gcd(%d, %d) = %d\n", a, b, g);
    printf("lcm(%d, %d) = %d\n", a, b, l);
    assert(g == 6);
    assert(l == 36);

    a = 7; b = 3;
    g = gcd(a, b);
    printf("gcd(%d, %d) = %d\n", a, b, g);
    assert(g == 1);

    a = 0; b = 5;
    l = lcm(a, b);
    printf("lcm(%d, %d) = %d\n", a, b, l);
    assert(l == 0);
}

void test_factorial_power() {
    printf("Testing factorial and power...\n");

    int n = 5;
    long f = factorial(n);
    printf("factorial(%d) = %ld\n", n, f);
    assert(f == 120);

    f = factorial(0);
    printf("factorial(0) = %ld\n", f);
    assert(f == 1);

    double base = 2.0, exp = 3.0;
    double p = power(base, exp);
    printf("power(%.2f, %.2f) = %.6f\n", base, exp, p);
    assert(p == 8.0);

    exp = -3.0;
    p = power(base, exp);
    printf("power(%.2f, %.2f) = %.9f\n", base, exp, p);
    assert(fabs(p - 0.125) < 1e-9);
}

void test_prime() {
    printf("Testing prime functions...\n");

    int val = 2;
    printf("is_prime(%d) = %d\n", val, is_prime(val));
    assert(is_prime(val));

    val = 4;
    printf("is_prime(%d) = %d\n", val, is_prime(val));
    assert(!is_prime(val));

    val = 7;
    int next = next_prime(val);
    printf("next_prime(%d) = %d\n", val, next);
    assert(next == 11);

    val = 0;
    next = next_prime(val);
    printf("next_prime(%d) = %d\n", val, next);
    assert(next == 2);
}

void test_sqrt_abs_min_max() {
    printf("Testing sqrt, abs, min, max...\n");

    double val = 4.0;
    double s = sqrt_newton(val);
    printf("sqrt_newton(%.2f) = %.9f\n", val, s);
    assert(fabs(s - 2.0) < 1e-9);

    int i = -5;
    printf("abs_int(%d) = %d\n", i, abs_int(i));
    assert(abs_int(i) == 5);

    double d = -2.5;
    printf("abs_double(%.2f) = %.2f\n", d, abs_double(d));
    assert(abs_double(d) == 2.5);

    int a = 3, b = 7;
    printf("max_int(%d, %d) = %d\n", a, b, max_int(a,b));
    printf("min_int(%d, %d) = %d\n", a, b, min_int(a,b));
    assert(max_int(a,b) == 7);
    assert(min_int(a,b) == 3);

    double x = 1.2, y = 3.4;
    printf("max_double(%.2f, %.2f) = %.9f\n", x, y, max_double(x,y));
    printf("min_double(%.2f, %.2f) = %.9f\n", x, y, min_double(x,y));
    assert(fabs(max_double(x,y) - 3.4) < 1e-9);
    assert(fabs(min_double(x,y) - 1.2) < 1e-9);
}

int main() {
    test_gcd_lcm();
    test_factorial_power();
    test_prime();
    test_sqrt_abs_min_max();

    printf("All mathx tests passed successfully!\n");
    return 0;
}