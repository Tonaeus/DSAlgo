/* 
    Problem
     - Find the minimum number of coins needed to make up a target amount, given an array of coin denominations and an unlimited supply of each type of coin
    
    Approaches
     1. Choose the coin that results in the fewest remaining coins needed recursively
      a. Subproblem: Minimum number of coins needed to make up the current amount
      b. Base case: Amount = 0 or amount < 0
      c. State: Amount 

    Data Structures
    Algorithms

    Time Complexity
     - O(n•a) -> n = number of coin denominations, a = amount
    Space Complexity
     - O(a)
*/

#include <bits/stdc++.h>
using namespace std;

// Solution 1

class Solution {
public:
    int coinChange(vector<int>& coins, int amount) {
        vector<int> dp(amount + 1, -2);
        return dfs(coins, amount, dp);
    }
private:
    int dfs(vector<int>& coins, int amount, vector<int>& dp) {
        if (amount == 0) return 0;  
        if (amount < 0) return -1;

        if (dp[amount] != -2) return dp[amount];

        int ans = INT_MAX;
        for (int coin : coins) {
            int subAns = dfs(coins, amount - coin, dp);
            if (subAns != -1) {
                ans = min(ans, subAns + 1);  
            }
        }

        return dp[amount] = ans < INT_MAX ? ans : -1;
    }
};

// Solution 1.1

class Solution {
public:
    int coinChange(vector<int>& coins, int amount) {
        vector<int> dp(amount + 1, -2);
        dp[0] = 0;

        for (int i = 1; i <= amount; i++) {
            int ans = INT_MAX;
            for (int coin: coins) {
                if (i - coin >= 0) {
                    int subAns = dp[i - coin];
                    if (subAns != -1) {
                        ans = min(ans, subAns + 1);
                    }
                }
            }
            dp[i] = ans < INT_MAX ? ans : -1;
        }

        return dp[amount];
    }
};