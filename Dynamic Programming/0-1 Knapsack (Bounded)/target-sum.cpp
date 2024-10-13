/* 
    Problem
     - https://leetcode.com/problems/target-sum/description/

    Patterns
     - O/1 Knapsack (Bounded)

    Comments
     - Decision: Choose either to add or substract the current integer
     - Subproblem: Number of expressions for the current target
     - Base case: Number of unused integers == 0
     - State: Number of unused integers, target
*/

#include <bits/stdc++.h>
using namespace std;

// Solution 1: Top-Down DP

// Time Complexity: O(n•sum)
// Space Complexity: O(n•sum)

class Solution {
public:
    int findTargetSumWays(vector<int>& nums, int target) {
        int sum = accumulate(nums.begin(), nums.end(), 0);
        if (abs(target) > sum) return 0;

        int n = nums.size();
        int offset = -target + sum;

        vector<vector<int>> dp(n + 1, vector<int>(sum * 2 + 1, -1));
        return dfs(nums, target, n, dp, offset);
    }   

private: 
    int dfs(vector<int>& nums, int tar, int i, vector<vector<int>>& dp, int offset) {
        if (i == 0) return tar == 0 ? 1 : 0;

        if (dp[i][tar + offset] != -1) return dp[i][tar + offset];

        int add = dfs(nums, tar + nums[i - 1], i - 1, dp, offset);
        int sub = dfs(nums, tar - nums[i - 1], i - 1, dp, offset);

        return dp[i][tar + offset] = add + sub;
    }
};

// Solution 2: Bottom-Up DP

// Time Complexity: O(n•sum)
// Space Complexity: O(n•sum)

class Solution {
public:
    int findTargetSumWays(vector<int>& nums, int target) {
        int sum = accumulate(nums.begin(), nums.end(), 0);
        if (abs(target) > sum) return 0;

        int n = nums.size();
        int offset = -target + sum;

        vector<vector<int>> dp(n + 1, vector<int>(sum * 2 + 1, 0));
        dp[0][0 + offset] = 1;
        
        for (int i = 1; i <= n; i++) {
            for (int tar = target - sum; tar <= target + sum; tar++) {
                if (tar + nums[i - 1] + offset <= sum * 2) {
                    dp[i][tar + offset] += dp[i - 1][tar + nums[i - 1] + offset];
                }
                if (tar - nums[i - 1] + offset >= 0) {
                    dp[i][tar + offset] += dp[i - 1][tar - nums[i - 1] + offset];
                }
            }
        }

        return dp[n][target + offset];
    }
};

// Solution 3: Space Optimized Bottom-Up DP

// Time Complexity: O(n•sum)
// Space Complexity: O(sum)

class Solution {
public:
    int findTargetSumWays(vector<int>& nums, int target) {
        int sum = accumulate(nums.begin(), nums.end(), 0);
        if (abs(target) > sum) return 0;

        int n = nums.size();
        int offset = -target + sum;

        vector<vector<int>> dp(2, vector<int>(sum * 2 + 1, 0));
        dp[0][0 + offset] = 1;
        
        for (int i = 1; i <= n; i++) {
            fill(dp[1].begin(), dp[1].end(), 0);
            for (int tar = target - sum; tar <= target + sum; tar++) {
                if (tar + nums[i - 1] + offset <= sum * 2) {
                    dp[1][tar + offset] += dp[0][tar + nums[i - 1] + offset];
                }
                if (tar - nums[i - 1] + offset >= 0) {
                    dp[1][tar + offset] += dp[0][tar - nums[i - 1] + offset];
                }
            }
            dp[0] = dp[1];
        }

        return dp[1][target + offset];
    }
};
