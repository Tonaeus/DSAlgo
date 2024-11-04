/* 
    Problem
     - https://leetcode.com/problems/longest-palindromic-subsequence/description/

    Patterns
     - Longest Common Subsequence

    Comments
     - Find the longest common subsequence between the given string and its reverse
*/

#include <bits/stdc++.h>
using namespace std;

// Solution 1: Space Optimized Bottom-Up DP

// Time Complexity: O(n^2)
// Space Complexity: O(n)

class Solution {
public:
    int longestPalindromeSubseq(string s) {
        string t(s.rbegin(), s.rend());
        int m = s.length();
        int n = m;

        int dp[2][n + 1];
        memset(dp, 0, sizeof(dp));

        for (int i = 1; i <= m; i++) {
            for (int j = 1; j <= n; j++) {
                if (s[i - 1] == t[j - 1]) {
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
