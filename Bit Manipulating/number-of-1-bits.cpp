/* 
    Approaches
     1. Count the number of bits that are 1 needed to represent the integer in binary form
     2. Count if the least significant bit is a 1, shift the bits to the right, and repeat with the new least significant bit
     3. Count the amount of time needed to remove all bits that are 1
      a. Consider that the AND operation copies bits that are the same and produces a 0 for bits that are different
      b. Consider that when subtracting 1 from a number, all bits inclusively between the first bit that is a 1 from the right and the least significant bit are flipped

    Data Structures
    Algorithms

    Time Complexity
     - O(log(n))
    Space Complexity
     - O(1)
*/

#include <bits/stdc++.h>
using namespace std;

// Solution 1

class Solution {
public:
    int hammingWeight(int n) {
        int ans = 0;
        while (n) {
            if (n % 2 == 1) ans++;
            n /= 2;
        }
        return ans;
    }
};

// Solution 2

class Solution {
public:
    int hammingWeight(int n) {
        int ans = 0;
        while (n) {
            if (n & 1) ans++;
            n >>= 1;
        }
        return ans;
    }
};

// Solution 3

class Solution {
public:
    int hammingWeight(int n) {
        int ans = 0;
        while (n) {
            n = n & (n - 1);
            ans++;
        }
        return ans;
    }
};