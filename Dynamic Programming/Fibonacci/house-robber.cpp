/* 
    Problem
     - https://leetcode.com/problems/house-robber/description/

    Patterns
     - Fibonacci 

    Comments 
     - Decision: Choose either the previous house or the house before the previous house and the latest seen house
     - Subproblem: Maximum amount of money for the number of seen house
     - Base case: Number of seen houses == 0, Number of seen houses == 1
     - State: Number of seen houses 
*/

#include <bits/stdc++.h>
using namespace std;

// Solution 1: Space Optimized

// Time Complexity: O(n)
// Space Complexity: O(1)

class Solution {
public:
    int rob(vector<int>& nums) {
        int n = nums.size();

        int dp[2];
        dp[0] = 0;
        dp[1] = nums[0];

        for (int i = 2; i <= n; i++) {
            dp[i & 1] = max(dp[i & 1 ^ 1], dp[i & 1] + nums[i - 1]);
        }

        return dp[n & 1];
    }
};
