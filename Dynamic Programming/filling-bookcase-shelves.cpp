/* 
    Problem
     - Find the minimum possible height of the entire bookshelf after placing the books in order, given the sequence of the books, the thickness and height of each book, and the width of the shelf

    Approaches
     1. Choose either to place the book on the same shelf or on the next shelf recursively
      a. Subproblem: Minimum height of the entire bookshelf using available books
      b. Base case: Available books = 0
      c. State: Available books

    Data Structures
    Algorithms

    Time Complexity
     - O(n•w) -> n = number of books, w = width of shelf
    Space Complexity
     - O(n)
*/

#include <bits/stdc++.h>
using namespace std;

// Solution 1

class Solution {
public:
    int minHeightShelves(vector<vector<int>>& books, int shelfWidth) {
        int n = books.size();
        vector<int> dp(n + 1, -1);
        return dfs(books, shelfWidth, n, dp);
    }
    int dfs(vector<vector<int>>& books, int shelfWidth, int i, vector<int>& dp) {
        if (i == 0) return 0;
        if (dp[i] != -1) return dp[i];
        
        int shelfW = shelfWidth;
        int shelfH = 0; 

        int ans = INT_MAX;
        for (int j = i; j > 0; j--) {
            int w = books[j - 1][0];
            int h = books[j - 1][1];
            if (shelfW < w) break;
            shelfW -= w;
            shelfH = max(shelfH, h);
            ans = min(ans, dfs(books, shelfWidth, j - 1, dp) + shelfH);
        }

        return dp[i] = ans;
    }
};

// Solution 1.1

class Solution {
public:
    int minHeightShelves(vector<vector<int>>& books, int shelfWidth) {
        int n = books.size();
        vector<int> dp(n + 1, -1);
        dp[0] = 0;

        for (int i = 1; i <= n; i++) {
            int shelfW = shelfWidth;
            int shelfH = 0; 

            int ans = INT_MAX;
            for (int j = i; j > 0; j--) {
                int w = books[j - 1][0];
                int h = books[j - 1][1];
                if (shelfW < w) break;
                shelfW -= w;
                shelfH = max(shelfH, h);
                ans = min(ans, dp[j - 1] + shelfH);
            }
            dp[i] = ans;
        }

        return dp[n];
    }
};