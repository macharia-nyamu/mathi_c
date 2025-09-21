/*
 * Mathi C Library - Math Utilities
 * mathi_math.h
 * 
 * Copyright (c) 2025 Macharia Nyamū
 * Licensed under the MIT License. See LICENSE file in the project root for details.
 */

#ifndef MATHI_MATH_H
#define MATHI_MATH_H

/**
 * @file mathi/math.h
 * @brief Basic mathematical utilities: GCD, LCM, factorial, powers, primes, sqrt, and min/max functions.
 */


/**
 * @brief Compute the greatest common divisor (GCD) of two integers.
 */
int mathi_gcd(int a, int b);

/**
 * @brief Compute the least common multiple (LCM) of two integers.
 */
int mathi_lcm(int a, int b);

/**
 * @brief Compute factorial of a non-negative integer.
 * @return -1 if n < 0.
 */
double mathi_factorial(int n);

/**
 * @brief Compute integer power of a base.
 */
double mathi_power(double base, int exp);

/**
 * @brief Check if a number is prime.
 * @return 1 if prime, 0 otherwise.
 */
int mathi_prime(int n);

/**
 * @brief Find the next prime number greater than n.
 */
int mathi_next_prime(int n);

/* --- Floating Point / General Math --- */

/**
 * @brief Compute the square root of a number.
 * @return -1 if x < 0.
 */
double mathi_sqrt(double x);

/**
 * @brief Compute absolute value of a double.
 */
double mathi_abs_double(double x);

/**
 * @brief Compute absolute value of an integer.
 */
int mathi_abs_int(int x);

/**
 * @brief Return maximum of two integers.
 */
int mathi_max_int(int a, int b);

/**
 * @brief Return minimum of two integers.
 */
int mathi_min_int(int a, int b);

/**
 * @brief Return maximum of two doubles.
 */
double mathi_max_double(double a, double b);

/**
 * @brief Return minimum of two doubles.
 */
double mathi_min_double(double a, double b);

#endif // MATHI_MATH_H