#ifndef _P_C_H_
#define _P_C_H_

/**
 * @brief Factorial using an iterative approach.
 * 
 * @param n number to find factorial.
 * @return int factorial of the number n. Error: -1
 */
inline int fact(int n) {
    if (n < 0) return -1; // Error case for negative numbers
    int result = 1;
    for (int i = 2; i <= n; ++i) {
        result *= i;
    }
    return result;
}

/**
 * @brief Permutation P(n,r). n is a whole number, r is a natural number, and r must be smaller than or equal to n.
 * 
 * @param n total number of items.
 * @param r number of items to be arranged.
 * @return int number of ways to arrange r items out of n items. Error: -1
 */
inline int p(int n, int r) {
    if (n < 0 || r < 1 || r > n) {
        return -1; // Error case
    }
    return fact(n) / fact(n - r);
}

/**
 * @brief Combination C(n,r). n is a whole number, r is a natural number, and r must be smaller than or equal to n.
 * 
 * @param n total number of items.
 * @param r number of items to be selected.
 * @return int number of ways to select r items out of n items. Error: -1
 */
inline int c(int n, int r) {
    if (n < 0 || r < 1 || r > n) {
        return -1; // Error case
    }
    return fact(n) / (fact(r) * fact(n - r));
}

#endif // _P_C_HPP_