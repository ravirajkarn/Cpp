/**
 * @file Q3.cpp
 * @author Sumit Kumar (ravirajkarn21@gmail.com)
 * @brief 
 * @details rite a program that outputs all prime numbers less than 1000.The program
 *          should also count the number of prime numbers less than 1000.An integer >= 2
 *          is a prime number if it is not divisible by any number except 1 and itself. Use the
 *          Sieve of Eratosthenes:
 *          To find primary numbers simply eliminate multiples of any primary numbers
 *          you have already found, i.e.:
 *          first eliminate any multiples of 2 ( 4, 6, 8, ... ),
 *          then eliminate any multiples of 3 ( 6, 9, 12, ...),
 *          then eliminate any multiples of 5 ( 10, 15, 20, ..) // 4 has already been eliminated
 *          and so on.
 * @version 0.1
 * @date 2025-06-15
 * 
 * @copyright Copyright (c) 2025
 * 
 */

#include <iostream>
#include "prime_number.hpp"
#include <random>
#include <fmt/core.h>
#include <gmp.h>


void print_prime(auto number){
    for (const auto& prime : number) {
        fmt::print("{}\n", prime);
    }
}

int main() {
    fmt::print("Prime numbers up to 1000:\n");
    print_prime(PrimeNumber::generator::bySieveOfEratosthenes(1000));
    print_prime(PrimeNumber::generator::bySieveOfAtkin(1000));

    fmt::print("\nA random number is generating.\n");
    std::random_device rd;
    std::mt19937 mt(rd());
    
    int number = mt();
    fmt::print("{0} is a prime number: {1:s}\n",number,PrimeNumber::checker::isPrime(number) );
    
}