/* 
    Problem
     - https://leetcode.com/problems/partition-equal-subset-sum/description/

    Patterns 
     - 0/1 Knapsack (Bounded)

    Comments
     - Decision: Choose either to include or exclude the current integer in the subset
     - Subproblem: Whether the unused integers can form a subset that sums to the current target
     - Base case: Number is unused intergers = 0, target == 0
     - State: Number of unused integers, target
*/

#include <bits/stdc++.h>
using namespace std;

// Solution 1: Top-Down DP

// Time Complexity: O(n•sum)
// Space Complexity: O(n•sum)

class Solution {
public:
    bool canPartition(vector<int>& nums) {
        int sum = accumulate(nums.begin(), nums.end(), 0);
        if (sum % 2 != 0) return false;

        int n = nums.size();
        int target = sum / 2;

        vector<vector<int>> dp(n + 1, vector<int>(target + 1, -1));
        return dfs(nums, target, n, dp);
    }

private:
    bool dfs(vector<int>& nums, int tar, int i, vector<vector<int>>& dp) {
        if (i == 0) return false;
        if (tar == 0) return true; 

        if (dp[i][tar] != -1) return dp[i][tar];

        if (nums[i - 1] > tar) {
            return dp[i][tar] = dfs(nums, tar, i - 1, dp);
        }

        return dp[i][tar] = dfs(nums, tar, i - 1, dp) | dfs(nums, tar - nums[i - 1], i - 1, dp);
    }
};

// Solution 2: Bottom-Up DP

// Time Complexity: O(n•sum)
// Space Complexity: O(n•sum)

class Solution {
public:
    bool canPartition(vector<int>& nums) {
        int sum = accumulate(nums.begin(), nums.end(), 0);
        if (sum % 2 != 0) return false;

        int n = nums.size();
        int target = sum / 2;

        vector<vector<int>> dp(n + 1, vector<int>(target + 1, false));
        dp[0][0] = true;

        for (int i = 1; i <= n; i++) {
            for (int tar = 0; tar <= target; tar++) {
                if (nums[i - 1] > tar) {
                    dp[i][tar] = dp[i - 1][tar]; 
                }
                else {
                    dp[i][tar] = dp[i - 1][tar] | dp[i - 1][tar - nums[i - 1]];
                }
            }
        }

        return dp[n][target];
    }
};

// Solution 3: Space Optimized Bottom-Up DP

// Time Complexity: O(n•sum)
// Space Complexity: O(sum)

class Solution {
public:
    bool canPartition(vector<int>& nums) {
        int sum = accumulate(nums.begin(), nums.end(), 0);
        if (sum % 2 != 0) return false;

        int n = nums.size();
        int target = sum / 2;

        vector<int> dp(target + 1, false);
        dp[0] = true;

        for (int i = 0; i < n; i++) {
            for (int tar = target; tar >= nums[i]; tar--) {
                dp[tar] = dp[tar] | dp[tar - nums[i]];
            }
        }

        return dp[target];
    }
};
