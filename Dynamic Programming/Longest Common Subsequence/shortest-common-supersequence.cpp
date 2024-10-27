/* 
    Problem
     - https://leetcode.com/problems/shortest-common-supersequence/description/

    Patterns
     - Longest Common Subsequence

    Comments
     - Backtrack to construct the shortest common supersequence
*/

#include <bits/stdc++.h>
using namespace std;

// Solution 1: Top-Down DP

// Time Complexity: O(m•n)
// Space Complexity: O(m•n)

class Solution {
public:
    string shortestCommonSupersequence(string str1, string str2) {
        int m = str1.length();
        int n = str2.length();
        vector<vector<int>> dp(m + 1, vector<int>(n + 1, INT_MAX));
        dfs(str1, str2, m, n, dp);

        string ans;
        int i = m;
        int j = n;

        while (i > 0 and j > 0) {
            if (str1[i - 1] == str2[j - 1]) {
                ans += str1[i - 1];
                i--, j--;
            }
            else if (dp[i - 1][j] < dp[i][j - 1]) {
                ans += str1[i - 1];
                i--;
            }
            else {
                ans += str2[j - 1];
                j--;
            }
        }

        while (i > 0) {
            ans += str1[i - 1];
            i--;
        }

        while (j > 0) {
            ans += str2[j - 1];
            j--;
        }

        reverse(ans.begin(), ans.end());

        return ans;
    }

private:
    int dfs(string& str1, string& str2, int m, int n, vector<vector<int>>& dp) {
        if (m == 0) return n;
        if (n == 0) return m;
        
        if (dp[m][n] != INT_MAX) return dp[m][n];

        if (str1[m - 1] == str2[n - 1]) {
            return dp[m][n] = dfs(str1, str2, m - 1, n - 1, dp) + 1;
        }

        return dp[m][n] = min(dfs(str1, str2, m - 1, n, dp) + 1, dfs(str1, str2, m, n - 1, dp) + 1);
    }
};

// // Solution 2: Bottom-Up DP

// // Time Complexity: O(m•n)
// // Space Complexity: O(m•n)

class Solution {
public:
    string shortestCommonSupersequence(string str1, string str2) {
        int m = str1.length();
        int n = str2.length();
        vector<vector<int>> dp(m + 1, vector<int>(n + 1, 0));

        for (int i = 1; i <= m; i++) {
            dp[i][0] = i;
        }
        for (int j = 1; j <= n; j++) {
            dp[0][j] = j;
        }

        for (int i = 1; i <= m; i++) {
            for (int j = 1; j <= n; j++) {
                if (str1[i - 1] == str2[j - 1]) {
                    dp[i][j] = dp[i - 1][j - 1] + 1;
                }
                else {
                    dp[i][j] = min(dp[i - 1][j] + 1, dp[i][j - 1] + 1);
                }
            }
        }

        string ans;
        int i = m;
        int j = n;

        while (i > 0 and j > 0) {
            if (str1[i - 1] == str2[j - 1]) {
                ans += str1[i - 1];
                i--, j--;
            }
            else if (dp[i - 1][j] < dp[i][j - 1]) {
                ans += str1[i - 1];
                i--;
            }
            else {
                ans += str2[j - 1];
                j--;
            }
        }

        while (i > 0) {
            ans += str1[i - 1];
            i--;
        }

        while (j > 0) {
            ans += str2[j - 1];
            j--;
        }

        reverse(ans.begin(), ans.end());

        return ans;
    }
};
