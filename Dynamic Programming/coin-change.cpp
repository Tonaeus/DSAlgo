/* 
    Approaches
     1. Find the minimum number of coins needed for (amount - coin) recursively 
      a. Subproblem -- mimimum coin for a given amount
      b. State -- amount 
      c. Base case -- amount == 0 or amount < 0

    Data Structures
    Algorithms

    Time Complexity
    Space Complexity
*/

#include <bits/stdc++.h>
using namespace std;

// Solution 1

class Solution {
public:
    int coinChange(vector<int>& coins, int amount) {
        vector<int> dp(amount + 1, INT_MAX);
        return dfs(coins, amount, dp);
    }
private:
    int dfs(vector<int>& coins, int amount, vector<int>& dp) {
        if (amount == 0) return 0;  
        if (amount < 0) return -1;

        if (dp[amount] != INT_MAX) return dp[amount];

        for (int coin : coins) {
            int subAns = dfs(coins, amount - coin, dp);
            if (subAns != -1) {
                dp[amount] = min(dp[amount], subAns + 1);  
            }
        }
        if (dp[amount] == INT_MAX) dp[amount] = -1;

        return dp[amount];
    }
};

// Solution 1.1

class Solution {
public:
    int coinChange(vector<int>& coins, int amount) {
        vector<int> dp(amount + 1, INT_MAX);
        dp[0] = 0;

        for (int i = 1; i <= amount; i++) {
            for (int coin: coins) {
                if (i - coin >= 0) {
                    int subAns = dp[i - coin];
                    if (subAns != -1) {
                        dp[i] = min(dp[i], subAns + 1);
                    }
                }
            }
            if (dp[i] == INT_MAX) dp[i] = -1;
        }

        return dp[amount];
    }
};
