/* 
    Problem
     - https://leetcode.com/problems/fibonacci-number/

    Patterns
     - Fibonacci
*/

#include <bits/stdc++.h>
using namespace std;

// Solution 1: Top-Down DP

// Time Complexity: O(n)
// Space Complexity: O(n)

class Solution {
public:
    int fib(int n) {
        int dp[n + 1];
        memset(dp, -1, sizeof(dp));
        return dfs(n, dp);
    }

private:
    int dfs(int n, int dp[]) {
        if (n == 0) return 0;
        if (n == 1) return 1; 

        if (dp[n] != - 1) return dp[n];

        return dp[n] = dfs(n - 1, dp) + dfs(n - 2, dp);
    }
};

// Solution 2: Bottom-Up DP

// Time Complexity: O(n)
// Space Complexity: O(n)

class Solution {
public:
    int fib(int n) {
        if (n <= 1) return n;

        int dp[n + 1];
        dp[0] = 0;
        dp[1] = 1;

        for (int i = 2; i <= n; i++) {
            dp[i] = dp[i - 1] + dp[i - 2];
        }

        return dp[n];
    }
};

// Solution 3: Space Optimized Bottom-Up DP

// Time Complexity: O(n)
// Space Complexity: O(1)

class Solution {
public:
    int fib(int n) {
        if (n <= 1) return n;

        int dp[2];
        dp[0] = 0;
        dp[1] = 1;

        for (int i = 2; i <= n; i++) {
            dp[i & 1] = dp[i & 1 ^ 1] + dp[i & 1];
        }

        return dp[n & 1];
    }
};
