/* 
    Problem
     - https://leetcode.com/problems/smallest-number-with-all-set-bits/description/

    Patterns
     - Most Significant Bit
*/

#include <bits/stdc++.h>
using namespace std;

// Solution 1: Most Significant Bit

// Time Complexity: O(1)
// Space Complexity: O(1)

class Solution {
public:
    int smallestNumber(int n) {
        int msbPos = log2(n);
        return (2 << msbPos) - 1;
    }
};
