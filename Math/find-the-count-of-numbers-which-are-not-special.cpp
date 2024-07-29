/* 
    Problem
     - Find the number of integers in a specified range that are not special, where an integer is classified as special if it has exactly 2 proper divisors

    Approaches
     1. Count the integers in the range that are not perfect squares with prime number roots
      a. Consider that a number can have only 1 proper divisor other than "1" if and only if the divisor and quotient are the same

    Data Structures
    Algorithms
     - Sieve of Eratosthenes

    Time Complexity
     - O(sqrt(r)•log(log(sqrt(r))))
    Space Complexity
     - O(sqrt(r))
*/

#include <bits/stdc++.h>
using namespace std;

// Solution 1

class Solution {
public:
    int nonSpecialCount(int l, int r) {
        int ans = r - l + 1;
        l = ceil(sqrt(l));
        r = floor(sqrt(r));
        for (; l <= r; l++) {
            if (isPrime(l)) {
                ans--;
            }
        }
        return ans;
    }
private:
    bool isPrime(int n) {
        if (n <= 1) return false;
        if (n <= 3) return true;

        if (n % 2 == 0 || n % 3 == 0) 
            return false;

        for (int i = 5; i * i <= n; i += 6)
            if (n % i == 0 || n % (i + 2) == 0) 
                return false;

        return true;
    }
};

// Solution 1.1

class Solution {
public:
    int nonSpecialCount(int l, int r) {
        int ans = r - l + 1;
        l = ceil(sqrt(l));
        r = floor(sqrt(r));

        vector<bool> prime(r + 1, true);
        prime[0] = prime[1] = false;
        for (int p = 2; p * p <= r; p++) {
            if (prime[p] == true) {
                for (int i = p * p; i <= r; i += p) {
                    prime[i] = false;
                }
            }
        }

        for (; l <= r; l++) {
            if (prime[l]) {
                ans--;
            }
        }

        return ans;
    }
};