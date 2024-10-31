/* 
    Problem
     - https://leetcode.com/problems/min-cost-climbing-stairs/description/

    Patterns
     - Fibonacci

    Comments
     - The top of the floor is one step above the top of the staircase

     - Decision: Choose either the previous step or the step before the previous step to reach the current step/floor
     - Subproblem: Minimum cost to reach the current step/floor
     - Base case: Step == 0, step == 1
     - State: Step
*/

#include <bits/stdc++.h>
using namespace std;

// Solution 1: Spaced Optimized Bottom-Up DP

// Time Complexity: O(n)
// Space Complexity: O(1)

class Solution {
public:
    int minCostClimbingStairs(vector<int>& cost) {
        int n = cost.size();

        int dp[2];
        dp[0] = 0;
        dp[1] = 0;

        for (int i = 2; i <= n; i++) {
            dp[i & 1] = min(dp[i & 1 ^ 1] + cost[i - 1], dp[i & 1] + cost[i - 2]);
        }

        return dp[n & 1];
    }
};
