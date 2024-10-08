/* 
    Problem
     - Find the minimum number of characters that need to be deleted to make a string balanced, where a string is balanced if there is no pair of indices (i, j) such that i < j and s[i] = "b" and s[j] = "a"

    Approaches
     1. Choose either to delete the current "a" or delete all previous "b"s recursively 
      a. Subproblem 1: Minimum number of deletions 
      b. Base case 1: String length = 0
      c. State 1: String
      d. Subproblem 2: Number of "b"s in each s.substr(0, i)
      e. Base case 2: String length = 0
      f. State 2: String
      d. Consider that if s.substr(0, i) is solved, then s.substr(0, i + 1) can also be solved

    Data Structures
    Algorithms

    Time Complexity
     - O(n)
    Space Complexity
     - O(1)
*/

#include <bits/stdc++.h>
using namespace std;

// Solution 1

class Solution {
public:
    int minimumDeletions(string s) {
        int n = s.length();
        vector<int> dp1(n + 1, -1);
        vector<int> dp2(n + 1, -1);
        auto [ans, bCnt] = dfs(s, n, dp1, dp2);
        return ans;
    }
private: 
    pair<int, int> dfs(string& s, int i, vector<int>& dp1, vector<int>& dp2) {
        if (i == 0) return {0, 0};
        if (dp1[i] != -1 && dp2[i] != -1) return {dp1[i], dp2[i]};

        auto [subAns, subBCnt] = dfs(s, i - 1, dp1, dp2);

        int ans = INT_MAX;
        int bCnt = 0;

        if (s[i - 1] == 'a') {
            ans = min(subAns + 1, subBCnt);
            bCnt = subBCnt;
        }
        else {
            ans = subAns;
            bCnt = subBCnt + 1;
        }
        
        return {dp1[i] = ans, dp2[i] = bCnt};
    }
};

// Solution 1.1

class Solution {
public:
    int minimumDeletions(string s) {
        int n = s.length();
        vector<int> dp1(n + 1, -1);
        vector<int> dp2(n + 1, -1);
        dp1[0] = 0;
        dp2[0] = 0;

        for (int i = 1; i <= n; i++) {
            int ans = INT_MAX;
            int bCnt = 0;

            if (s[i - 1] == 'a') {
                ans = min(dp1[i - 1] + 1, dp2[i - 1]);
                bCnt = dp2[i - 1]; 
            } else {
                ans = dp1[i - 1];
                bCnt = dp2[i - 1] + 1;
            }
            
            dp1[i] = ans, dp2[i] = bCnt;
        }

        return dp1[n];
    }
};

// Solution 1.2

class Solution {
public:
    int minimumDeletions(string s) {
        int ans = 0;
        int bCnt = 0;

        for (char c : s) {
            if (c == 'a') {
                ans = min(ans + 1, bCnt);
            }
            else {
                bCnt++;
            }
        }

        return ans;
    }
};