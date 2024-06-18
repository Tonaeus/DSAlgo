/* 
    Approaches
     1. Iterate from both the left and the right at the same time to see if there exist two integers, a and b, such that a^2 + b^2 = c
      a. Consider that if a^2, b^2 <= c, then a, b <= sqrt(c) 
      b. Consider integer overflow 

    Data Structures
    Algorithms

    Time Complexity
     - O(sqrt(c))
    Space Complexity
     - O(1)
*/

#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    bool judgeSquareSum(int c) {
        long left = 0;
        long right = static_cast<long>(sqrt(c));

        while (left <= right) {
            long sum = left * left + right * right;

            if (sum < c)
                left++;
            else if (sum > c)
                right--;
            else {
                return true;
            }
        }

        return false;
    }
};