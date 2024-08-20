/* 
    Problem
     - Find the minimum number of operations required to get the character "A" exactly "n" times on the screen, given the operation of copying all characters on the screen and pasting the previous copied characters to the screen, where the screen initially shows a single "A"

    Approaches
     1. Calculate the sum of the prime factors of "n"
      a. Consider that the factors of "n" represent the number of operations using the same clipboard, including both the initial copy operation and subsequent paste operations
      b. Consider that the prime factors are optimal because they represent operations performed with the largest possible clipboard sizes

    Data Structures
    Algorithms

    Time Complexity
     - O(n)
    Space Complexity
     - O(1)
*/

#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int minSteps(int n) {
        int ans = 0;

        int d = 2;
        while (n > 1) {
            while (n % d == 0) {
                ans += d;
                n /= d;
            }
            d++;
        }

        return ans;
    }
};