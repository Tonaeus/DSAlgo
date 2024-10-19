/* 
    Problem
     - https://leetcode.com/problems/coin-change-ii/description/

    Patterns
     - 0/1 Knapsack (Unbounded)

    Comments
     - Decision: Choose either to use or not use the current coin denomination
     - Subproblem: Number of combinations that make up the current amount
     - Base case: Number of unused coin denomination == 0, amount == 0
     - State: Number of unused coin denomination, amount

     - Consider that different paths may contain the same coins
     - Consider no solutions 
*/

#include <bits/stdc++.h>
using namespace std;

// Solution 1: Top-Down DP 

// Time Complexity: O(n•amount)
// Space Complexity: O(n•amount)

class Solution {
public:
    int change(int amount, vector<int>& coins) {
        int n = coins.size();
        vector<vector<int>> dp(n + 1, vector<int>(amount + 1, -1));
        return dfs(coins, n, amount, dp);
    }

private:
    int dfs(vector<int>& coins, int i, int amount, vector<vector<int>>& dp) {
        if (i == 0) return 0;
        if (amount == 0) return 1;

        if (dp[i][amount] != -1) return dp[i][amount];

        if (coins[i - 1] > amount) {
            return dp[i][amount] = dfs(coins, i - 1, amount, dp);
        }

        return dp[i][amount] = dfs(coins, i - 1, amount, dp) + dfs(coins, i, amount - coins[i - 1], dp);
    }
};

// Solution 2: Bottom-Up DP

// Time Complexity: O(n•amount)
// Space Complexity: O(n•amount)

class Solution {
public:
    int change(int amount, vector<int>& coins) {
        int n = coins.size();
        vector<vector<int>> dp(n + 1, vector<int>(amount + 1, 0));
        dp[0][0] = 1;

        for (int i = 1; i <= n; i++) {
            for (int j = 0; j <= amount; j++) {
                if (coins[i - 1] > j) {
                    dp[i][j] = dp[i - 1][j];
                }
                else {
                    dp[i][j] = dp[i - 1][j] + dp[i][j - coins[i - 1]];
                }
            }
        }

        return dp[n][amount];
    }
};

// Solution 3: Space Optimized Bottom-Up DP

// Time Complexity: O(n•amount)
// Space Complexity: O(amount)

class Solution {
public:
    int change(int amount, vector<int>& coins) {
        int n = coins.size();
        vector<int> dp(amount + 1, 0);
        dp[0] = 1;

        for (int i = 0; i < n; i++) {
            for (int j = coins[i]; j <= amount; j++) {
                dp[j] = dp[j] + dp[j - coins[i]];
            }
        }

        return dp[amount];
    }
};
