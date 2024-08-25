/* 
    Problem
     - Find the minimum number of turns the printer needs to print the given string, where the printer can print a sequence of identical characters starting and ending at any position in each turn, such that all characters inclusively between the starting and ending positions are overwritten

    Approaches
     1. Choose either to print a single character or a sequence of characters
      a. Subproblem: Minimum number of turns
      b. Base case: Length of substring = 0
      c. State: Starting and ending position of substring
      
    Data Structures
    Algorithms

    Time Complexity
     - O(n^3)
    Space Complexity
     - O(n^2)
*/

#include <bits/stdc++.h>
using namespace std;

// Solution 1

class Solution {
public:
    int strangePrinter(string s) {
        int n = s.length();
        vector<vector<int>> dp(n, vector<int>(n, -1));
        return dfs(s, 0, n - 1, dp);
    }

private: 
    int dfs(string& s, int i, int j, vector<vector<int>>& dp) {
        if (i > j) return 0;
        if (dp[i][j] != -1) return dp[i][j];

        int ans = 1 + dfs(s, i + 1, j, dp);
        for (int k = i + 1; k <= j; k++) {
            if (s[i] == s[k]) {
                ans = min(ans, dfs(s, i, k - 1, dp) + dfs(s, k + 1, j, dp));
            }
        }

        return dp[i][j] = ans;
    }
};

// Solution 1.1 

class Solution {
public:
    int strangePrinter(string s) {
        int n = s.length();
        vector<vector<int>> dp(n + 1, vector<int>(n, -1));
        for (int i = 1; i < n + 1; i++) {
            dp[i][i - 1] = 0;
        }
        
        for (int i = n - 1; i >= 0; i--) {
            for (int j = i; j < n; j++) {
                int ans = 1 + dp[i + 1][j];
                for (int k = i + 1; k <= j; k++) {
                    if (s[i] == s[k]) {
                        ans = min(ans, dp[i][k - 1] + dp[k + 1][j]);
                    }
                }
                dp[i][j] = ans;
            }
        }

        return dp[0][n - 1];
    }
};