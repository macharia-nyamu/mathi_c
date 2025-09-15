/**
 * Mathi C Library - Math Utilities
 * 
 * Provides basic mathematical routines: factorial, powers, GCD/LCM, primes, square roots, and min/max functions.
 * 
 * Status codes:
 * 0 - SUCCESS
 * 1 - INVALID_INPUT
 * 2 - UNKNOWN_ERROR
 * 
 * @file mathx.h
 * @author Macharia Nyamū
 * @date 2025
 * @license MIT
 * 
 * Licensed under the MIT License. You may obtain a copy of the License at
 * https://opensource.org/licenses/MIT
 */

#ifndef MATHI_MATHX_H
#define MATHI_MATHX_H

/* ----- Basic Math Functions ----- */

/**
 * @brief Compute factorial of n (n!).
 * @param n Non-negative integer
 * @return Factorial value, or -1 for invalid input
 */
double factorial(int n);

/**
 * @brief Compute base raised to the exponent exp (base^exp).
 * @param base Base value
 * @param exp Exponent
 * @return Result of base^exp
 */
double power(double base, int exp);

/**
 * @brief Compute greatest common divisor of a and b.
 * @param a First integer
 * @param b Second integer
 * @return GCD of a and b
 */
int gcd(int a, int b);

/**
 * @brief Compute least common multiple of a and b.
 * @param a First integer
 * @param b Second integer
 * @return LCM of a and b
 */
int lcm(int a, int b);

/**
 * @brief Check if a number is prime.
 * @param n Integer to check
 * @return 1 if prime, 0 otherwise
 */
int is_prime(int n);

/**
 * @brief Find the next prime number after n.
 * @param n Integer input
 * @return Next prime number
 */
int next_prime(int n);

/**
 * @brief Compute square root of x using Newton's method.
 * @param x Input value
 * @return Square root of x
 */
double sqrt_newton(double x);

/**
 * @brief Compute absolute value of a double.
 * @param x Input value
 * @return Absolute value
 */
double abs_double(double x);

/**
 * @brief Compute absolute value of an integer.
 * @param x Input integer
 * @return Absolute value
 */
int abs_int(int x);

/**
 * @brief Return maximum of two integers.
 * @param a First integer
 * @param b Second integer
 * @return Maximum value
 */
int max_int(int a, int b);

/**
 * @brief Return minimum of two integers.
 * @param a First integer
 * @param b Second integer
 * @return Minimum value
 */
int min_int(int a, int b);

/**
 * @brief Return maximum of two doubles.
 * @param a First value
 * @param b Second value
 * @return Maximum value
 */
double max_double(double a, double b);

/**
 * @brief Return minimum of two doubles.
 * @param a First value
 * @param b Second value
 * @return Minimum value
 */
double min_double(double a, double b);

#endif