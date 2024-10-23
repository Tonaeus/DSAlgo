/* 
    Problem
     - https://leetcode.com/problems/longest-common-subsequence/description/

    Patterns
     - Longest Common Subsequence

    Comments
     - Decision: Choose to include the character if it is the current character in both sequences
     - Subproblem: Length of longest subsequence
     - Base case: Length of sequence 1 == 0, length of sequence 2 == 0
     - State: Length of sequence 1, length of sequence 2
*/

#include <bits/stdc++.h>
using namespace std;

// Solution 1: Top-Down DP

// Time Complexity: O(m•n)
// Space Complexity: O(m•n)

class Solution {
public:
    int longestCommonSubsequence(string text1, string text2) {
        int m = text1.length();
        int n = text2.length();
        vector<vector<int>> dp(m + 1, vector<int>(n + 1, -1));
        return dfs(text1, text2, m, n, dp);
    }

private: 
    int dfs(string& text1, string& text2, int m, int n, vector<vector<int>>& dp) {
        if (m == 0 or n == 0) return 0;

        if (dp[m][n] != -1) return dp[m][n];

        if (text1[m - 1] == text2[n - 1]) {
            return dp[m][n] = dfs(text1, text2, m - 1, n - 1, dp) + 1;
        }

        return dp[m][n] = max(dfs(text1, text2, m - 1, n, dp), dfs(text1, text2, m , n - 1, dp));
    }
};

// Solution 2: Bottom-Up DP

// Time Complexity: O(m•n)
// Space Complexity: O(m•n)

class Solution {
public:
    int longestCommonSubsequence(string text1, string text2) {
        int m = text1.length();
        int n = text2.length();
        vector<vector<int>> dp(m + 1, vector<int>(n + 1, 0));

        for(int i = 1; i <= m; i++) {
            for (int j = 1; j <= n; j++) {
                if (text1[i - 1] == text2[j - 1]) {
                    dp[i][j] = dp[i - 1][j - 1] + 1;
                }
                else {
                    dp[i][j] = max(dp[i - 1][j], dp[i][j - 1]);
                }
            }
        }

        return dp[m][n];
    }
};

// Solution 2: Space Optimized Bottom-Up DP

// Time Complexity: O(m•n)
// Space Complexity: O(n)

class Solution {
public:
    int longestCommonSubsequence(string text1, string text2) {
        int m = text1.length();
        int n = text2.length();
        vector<vector<int>> dp(2, vector<int>(n + 1, 0));

        for(int i = 1; i <= m; i++) {
            for (int j = 1; j <= n; j++) {
                if (text1[i - 1] == text2[j - 1]) {
                    dp[i & 1][j] = dp[i & 1 ^ 1][j - 1] + 1;
                }
                else {
                    dp[i & 1][j] = max(dp[i & 1 ^ 1][j], dp[i & 1][j - 1]);
                }
            }
        }

        return dp[m & 1][n];
    }
};
