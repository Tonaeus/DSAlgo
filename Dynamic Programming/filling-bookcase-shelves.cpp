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
        vector<int> dp(n + 1, INT_MAX);
        return dfs(books, n, shelfWidth, dp);
    }
    int dfs(vector<vector<int>>& books, int i, int shelfWidth, vector<int>& dp) {
        if (i == 0) return 0;
        if (dp[i] != INT_MAX) return dp[i];
        
        int shelfW = shelfWidth;
        int shelfH = 0; 

        for (int j = i; j > 0; j--) {
            int w = books[j - 1][0];
            int h = books[j - 1][1];
            if (shelfW < w) break;
            shelfW -= w;
            shelfH = max(shelfH, h);
            dp[i] = min(dp[i], dfs(books, j - 1, shelfWidth, dp) + shelfH);
        }

        return dp[i];
    }
};

// Solution 1.1

class Solution {
public:
    int minHeightShelves(vector<vector<int>>& books, int shelfWidth) {
        int n = books.size();
        vector<int> dp(n + 1, INT_MAX);
        dp[0] = 0;

        for (int i = 1; i <= n; i++) {
            int shelfW = shelfWidth;
            int shelfH = 0; 

            for (int j = i; j > 0; j--) {
                int w = books[j - 1][0];
                int h = books[j - 1][1];
                if (shelfW < w) break;
                shelfW -= w;
                shelfH = max(shelfH, h);
                dp[i] = min(dp[i], dp[j - 1] + shelfH);
            }
        }

        return dp[n];
    }
};