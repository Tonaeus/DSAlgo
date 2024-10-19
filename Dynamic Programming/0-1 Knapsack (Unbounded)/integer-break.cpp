/* 
    Problem
     - https://leetcode.com/problems/integer-break/description/

    Patterns
     - 0/1 Knapsack (Unbounded)

    Comments
     - Decision: Choose either to use or not use the current integer
     - Subproblem: Maximum product for the current target
     - Base case: Number of unused integers == 0, target == 0
     - State: Number of unused integers, target

     - https://twchen.gitbook.io/leetcode/dynamic-programming/integer-break
*/

#include <bits/stdc++.h>
using namespace std;

// Solution 1: Top-Down DP

// Time Complexity: O(n^2)
// Space Complexity: O(n^2)

class Solution {
public:
    int integerBreak(int n) {
        vector<vector<int>> dp(n, vector<int>(n + 1, -1));
        return dfs(n - 1, n, dp);
    }

private: 
    int dfs(int i, int tgt, vector<vector<int>>& dp) {
        if (i == 0) return 0;
        if (tgt == 0) return 1;

        if (dp[i][tgt] != -1) return dp[i][tgt];

        if (i > tgt) {
            return dp[i][tgt] = dfs(i - 1, tgt, dp); 
        }

        return dp[i][tgt] = max(dfs(i - 1, tgt, dp), dfs(i, tgt - i, dp) * i); 
    }
};

// Solution 2: Bottom-Up DP

// Time Complexity: O(n^2)
// Space Complexity: O(n^2)

class Solution {
public:
    int integerBreak(int n) {
        vector<vector<int>> dp(n, vector<int>(n + 1, 0));
        dp[0][0] = 1;

        for (int i = 1; i < n; i++) {
            for (int tgt = 0; tgt <= n; tgt++) {
                if (i > tgt) {
                    dp[i][tgt] = dp[i - 1][tgt];
                }
                else {
                    dp[i][tgt] = max(dp[i - 1][tgt], dp[i][tgt - i] * i);
                }
            }
        }

        return dp[n - 1][n];
    }
};

// Solution 3: Space Optimized Bottom-Up DP

// Time Complexity: O(n^2)
// Space Complexity: O(n)

class Solution {
public:
    int integerBreak(int n) {
        vector<int> dp(n + 1, 0);
        dp[0] = 1;

        for (int i = 0; i < n; i++) {
            for (int tgt = i; tgt <= n; tgt++) {
                dp[tgt] = max(dp[tgt], dp[tgt - i] * i);
            }
        }

        return dp[n];
    }
};

// Solution 4: Mathematical optimization

// Time Complexity: O(log(n))
// Space Complexity: O(1)

class Solution {
public:
    int integerBreak(int n) {
        if (n == 2) return 1;
        if (n == 3) return 2;
        
        if (n % 3 == 0) {
            return pow(3, n / 3);
        }
        if (n % 3 == 1) {
            return pow(3, (n - 4) / 3) * 2 * 2;
        }
        if (n % 3 == 2) {
            return pow(3, (n - 2) / 3) * 2;
        }

        return -1;
    }
};
