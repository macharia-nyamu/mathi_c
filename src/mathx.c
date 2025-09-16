/*
* Mathi C Library - Math Utilities
* mathi_math.c
* 
* Provides basic mathematical operations: GCD, LCM, factorial, power, primes, sqrt, and min/max/abs.
* 
* Copyright (c) 2025 Macharia Nyamū
* Licensed under the MIT License. See LICENSE file in the project root for details.
*/

#include <stdio.h>
#include <stdlib.h>
#include <math.h>


/**
 * @brief Compute the Greatest Common Divisor (GCD) of two integers using Euclid's algorithm.
 * @param a First integer.
 * @param b Second integer.
 * @return GCD of a and b.
 */
int mathi_gcd(int a, int b) {
    while (b) {
        int t = b;
        b = a % b;
        a = t;
    }
    return a;
}

/**
 * @brief Compute the Least Common Multiple (LCM) of two integers.
 * @param a First integer.
 * @param b Second integer.
 * @return LCM of a and b. Returns 0 if either number is 0.
 */
int mathi_lcm(int a, int b) {
    if (a == 0 || b == 0) return 0;
    return abs(a * b) / mathi_gcd(a, b);
}


/**
 * @brief Compute factorial of n (n!).
 * @param n Non-negative integer.
 * @return Factorial as double. Returns -1 for negative input.
 */
double mathi_factorial(int n) {
    if (n < 0) return -1;
    double res = 1;
    for (int i = 2; i <= n; i++) res *= i;
    return res;
}

/**
 * @brief Compute integer power of a number.
 * @param base Base value.
 * @param exp Exponent (can be negative).
 * @return base raised to the power exp.
 */
double mathi_power(double base, int exp) {
    double res = 1;
    int e = exp < 0 ? -exp : exp;
    for (int i = 0; i < e; i++) res *= base;
    return exp < 0 ? 1.0 / res : res;
}


/**
 * @brief Check if a number is prime.
 * @param n Integer to check.
 * @return 1 if prime, 0 otherwise.
 */
int mathi_prime(int n) {
    if (n < 2) return 0;
    if (n == 2 || n == 3) return 1;
    if (n % 2 == 0 || n % 3 == 0) return 0;
    for (int i = 5; i * i <= n; i += 6)
        if (n % i == 0 || n % (i + 2) == 0) return 0;
    return 1;
}

/**
 * @brief Find the next prime greater than n.
 * @param n Starting number.
 * @return Next prime number greater than n.
 */
int mathi_next_prime(int n) {
    if (n < 2) return 2;
    int candidate = n + 1;
    while (!mathi_prime(candidate)) candidate++;
    return candidate;
}


/**
 * @brief Compute square root using Newton-Raphson method.
 * @param x Input value.
 * @return Square root of x. Returns -1 for negative input.
 */
double mathi_sqrt(double x) {
    if (x < 0) return -1;
    double guess = x / 2.0, eps = 1e-9;
    while (fabs(guess * guess - x) > eps)
        guess = (guess + x / guess) / 2.0;
    return guess;
}


/**
 * @brief Absolute value of a double.
 */
double mathi_abs_double(double x) {
    return x < 0 ? -x : x;
}

/**
 * @brief Absolute value of an int.
 */
int mathi_abs_int(int x) {
    return x < 0 ? -x : x;
}


/**
 * @brief Maximum of two integers.
 */
int mathi_max_int(int a, int b) {
    return a > b ? a : b;
}

/**
 * @brief Minimum of two integers.
 */
int mathi_min_int(int a, int b) {
    return a < b ? a : b;
}

/**
 * @brief Maximum of two doubles.
 */
double mathi_max_double(double a, double b) {
    return a > b ? a : b;
}

/**
 * @brief Minimum of two doubles.
 */
double mathi_min_double(double a, double b) {
    return a < b ? a : b;
}