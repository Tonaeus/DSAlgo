/* 
    Problem
     - https://leetcode.com/problems/check-balanced-string/description/

    Patterns
     - One Pass
*/

#include <bits/stdc++.h>
using namespace std;

// Solution 1: One Pass

// Time Complexity: O(n)
// Space Complexity: O(1)

class Solution {
public:
    bool isBalanced(string num) {
        int evenIndexSum = 0;
        int oddIndexSum = 0;

        for (int i = 0; i < num.size(); i++) {
            (i % 2 == 0 ? evenIndexSum : oddIndexSum) += num[i] - '0';
        }

        return evenIndexSum == oddIndexSum;
    }
};
