/* 
    Problem
     - https://leetcode.com/problems/house-robber-ii/description/

    Patterns
     - Fibonacci

    Comments
     - Perform DP twice with each time excluding a different house from the same pair of houses
*/

#include <bits/stdc++.h>
using namespace std;

// Solution 1: 

// Time Complexity: O(n)
// Space Complexity: O(1)

class Solution {
public:
    int rob(vector<int>& nums) {
        int n = nums.size();

        if (n == 1) return nums[0];

        int dp1[2];
        dp1[0] = 0;
        dp1[1] = nums[1];

        for (int i = 3; i <= n; i++) {
            dp1[i & 1 ^ 1] = max(dp1[i & 1], dp1[i & 1 ^ 1] + nums[i - 1]);
        }

        int dp2[2];
        dp2[0] = 0;
        dp2[1] = nums[0];

        for (int i = 2; i < n; i++) {
            dp2[i & 1] = max(dp2[i & 1 ^ 1], dp2[i & 1] + nums[i - 1]);
        }

        return max(dp1[n & 1 ^ 1], dp2[(n - 1) & 1]);
    }
};
