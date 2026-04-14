#ifndef PRIME_NUMBER_HPP
#define PRIME_NUMBER_HPP

#include <vector>
#include <cmath> // For sqrt

namespace PrimeNumber{

    // =========================
    // Prime Number Generators
    // =========================
    namespace generator{

        /**
         * @brief Generates all prime numbers up to a given limit using the Sieve of Eratosthenes.
         * @param limit The upper bound (inclusive) for generating primes.
         * @return std::vector<int> List of all primes up to 'limit'.
         */
        inline std::vector<int> bySieveOfEratosthenes(int limit){
            if (limit < 2)
                return {};
            std::vector<bool> isPrime(limit + 1, true);
            isPrime[0] = isPrime[1] = false;
            int sqrtLimit = static_cast<int>(std::sqrt(limit));          
            for (int i = 2; i <= sqrtLimit; ++i){
                if (isPrime[i]){
                    for (int j = i * i; j <= limit; j += i){
                        isPrime[j] = false;
                    }
                }
            }

            std::vector<int> primes;
            primes.reserve(limit / 10); // Rough estimate for better performance
            for (int i = 2; i <= limit; ++i){
                if (isPrime[i])
                {
                    primes.push_back(i);
                }
            }
            return primes;
        }

        inline std::vector<int> bySieveOfAtkin(int limit){
            if (limit < 2){
                return {}; // Return empty vector if limit is less than 2
            }

            // Initialize a boolean vector 'is_prime' with all values set to false.
            // The size is limit + 1 because we want to include 'limit' itself.
            std::vector<bool> is_prime(limit + 1, false);

            // 2 and 3 are prime, and are handled as special cases.
            if (limit >= 2){
                is_prime[2] = true;
            }
            if (limit >= 3){
                is_prime[3] = true;
            }

            // Main part of the Sieve of Atkin:
            // Numbers n are prime if and only if one of the following is true:
            // 1. n = 4x^2 + y^2, n % 12 == 1 or n % 12 == 5
            // 2. n = 3x^2 + y^2, n % 12 == 7
            // 3. n = 3x^2 - y^2, x > y, n % 12 == 11
            // where x and y are positive integers.

            int sqrt_limit = static_cast<int>(std::sqrt(limit)) + 1;

            // Iterate through possible x and y values
            for (int x = 1; x < sqrt_limit; ++x){
                for (int y = 1; y < sqrt_limit; ++y){
                    int n;

                    // Case 1: n = 4x^2 + y^2
                    n = (4 * x * x) + (y * y);
                    if (n <= limit && (n % 12 == 1 || n % 12 == 5)){
                        is_prime[n] = !is_prime[n];
                    }

                    // Case 2: n = 3x^2 + y^2
                    n = (3 * x * x) + (y * y);
                    if (n <= limit && (n % 12 == 7)){
                        is_prime[n] = !is_prime[n];
                    }

                    // Case 3: n = 3x^2 - y^2
                    // Note: x must be greater than y for this case to avoid negative n or redundant calculations
                    n = (3 * x * x) - (y * y);
                    if (x > y && n <= limit && (n % 12 == 11)){
                        is_prime[n] = !is_prime[n];
                    }
                }
            }

            // Eliminate composites by sieving (removing multiples of squares of primes)
            // This step ensures that numbers that are multiples of prime squares
            // (e.g., 25, 49, etc.) are correctly marked as non-prime, as they
            // would have been flipped an even number of times by the quadratic forms.
            for (int r = 5; r * r <= limit; ++r){ // Only need to go up to sqrt(limit)
                if (is_prime[r])
                { // If r is a prime found in the previous step
                    // Mark all multiples of r*r as not prime
                    for (int multiple = r * r; multiple <= limit; multiple += r * r)
                    {
                        is_prime[multiple] = false;
                    }
                }
            }

            // Collect the prime numbers
            std::vector<int> primes;
            for (int i = 2; i <= limit; ++i)
            {
                if (is_prime[i])
                {
                    primes.push_back(i);
                }
            }

            return primes;
        }
    }

    // =========================
    // Prime Number Checker
    // =========================
    namespace checker
    {

        /**
         * @brief Checks if a given number is prime.
         * @param number The number to check.
         * @return true if 'number' is prime, false otherwise.
         */
        inline bool isPrime(int number)
        {
            if (number < 2)
                return false;
            if (number == 2 || number == 3)
                return true;
            if (number % 2 == 0 || number % 3 == 0)
                return false;

            int sqrtNum = static_cast<int>(sqrt(number));
            for (int i = 5; i <= sqrtNum; i += 6)
            {
                if (number % i == 0 || number % (i + 2) == 0)
                {
                    return false;
                }
            }
            return true;
        }
    }

} // namespace PrimeNumber

#endif // PRIME_NUMBER_HPP