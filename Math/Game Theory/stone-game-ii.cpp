/* 
    Problem
     - Find the maximum number of stones Alice can collect if she and Bob take turns playing optimally, starting with Alice, where on each turn a player can take stones from the first X remaining piles (1 ≤ X ≤ 2M) and M is updated to max(M, X), starting with M = 1
    
    Approaches
     1. Choose the number of remaining piles that will result in the greatest number of stones if the current player is Alice, and choose the number of remaining piles that will result in the fewest number of stones if the current player is Bob
      a. Consider that Alice wants to maximize her own score
      b. Consider that Bob wants to minimize his opponent's score
      c. Subproblem: Optimal number of stones for Alice in the current turn
      d. Base case: Number of remaining piles = 0
      e. State: Number of remaining piles and number of piles to take

    Data Structures
    Algorithms
     - Minimax 

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
    int stoneGameII(vector<int>& piles) {
        int n = piles.size();
        vector<vector<vector<int>>> dp(n, vector<vector<int>>(n + 1, vector<int>(2, -1)));
        return minimax(piles, 0, 1, 0, dp);
    }

private:
    int minimax(vector<int>& piles, int i, int M, int player, vector<vector<vector<int>>>& dp) {
        if (i == piles.size()) return 0;
        if (dp[i][M][player] != -1) return dp[i][M][player];

        if (player == 0) {
            int ans = 0;
            int sum = 0;
            for (int X = 1; X <= 2 * M; X++) {
                if (i + X - 1 < piles.size()) {
                    sum += piles[i + X - 1];
                    ans = max(ans, sum + minimax(piles, i + X, max(M, X), 1, dp));
                }
            }
            return dp[i][M][player] = ans;
        }
        else {
            int ans = INT_MAX;
            for (int X = 1; X <= 2 * M; X++) {
                if (i + X - 1 < piles.size()) {
                    ans = min(ans, minimax(piles, i + X, max(M, X), 0, dp));
                }
            }
            return dp[i][M][player] = ans;
        }
    }
};

// Solution 1.1

class Solution {
public:
    int stoneGameII(vector<int>& piles) {
        int n = piles.size();
        vector<vector<vector<int>>> dp(n, vector<vector<int>>(n + 1, vector<int>(2, -1)));
        return minimax(piles, 0, 1, 0, dp);
    }

private:
    int minimax(vector<int>& piles, int i, int M, int player, vector<vector<vector<int>>>& dp) {
        if (i == piles.size()) return 0;
        if (dp[i][M][player] != -1) return dp[i][M][player];

        int ans = player == 0 ? 0 : INT_MAX;
        int sum = 0;
        
        for (int X = 1; X <= 2 * M; X++) {
            if (i + X - 1 < piles.size()) {
                if (player == 0) {
                    sum += piles[i + X - 1];
                    ans = max(ans, sum + minimax(piles, i + X, max(M, X), 1, dp));
                }
                else {
                    ans = min(ans, minimax(piles, i + X, max(M, X), 0, dp));
                }
            }
        }

        return dp[i][M][player] = ans;
    }
};

// Solution 1.2

class Solution {
public:
    int stoneGameII(vector<int>& piles) {
        int n = piles.size();
        vector<vector<vector<int>>> dp(n + 1, vector<vector<int>>(n + 1, vector<int>(2, -1)));
        for (int M = 1; M < n + 1; M++) {
            for (int player = 0; player < 2; player++) {
                dp[n][M][player] = 0;
            }
        }

        for (int i = n - 1; i >= 0; i--) {
            for (int M = n; M >= 1; M--) {
                for (int player = 0; player < 2; player++) { 
                    int ans = player == 0 ? 0 : INT_MAX;
                    int sum = 0;

                    for (int X = 1; X <= 2 * M; X++) {
                        if (i + X - 1 < piles.size()) {
                            if (player == 0) {
                                sum += piles[i + X - 1];
                                ans = max(ans, sum + dp[i + X][max(M, X)][1]);
                            }
                            else {
                                ans = min(ans, dp[i + X][max(M, X)][0]);
                            }
                        }
                    }

                    dp[i][M][player] = ans;
                }
            }
        }

        return dp[0][1][0];
    }
};

// Solution 1.3

class Solution {
public:
    int stoneGameII(vector<int>& piles) {
        int n = piles.size();
        vector<vector<vector<int>>> dp(n + 1, vector<vector<int>>(n + 1, vector<int>(2, -1)));
        for (int M = 1; M <= n; M++) {
            dp[n][M][0] = 0;
            dp[n][M][1] = 0;
        }

        for (int i = n - 1; i >= 0; i--) {
            for (int M = n; M >= 1; M--) {
                dp[i][M][0] = 0;  
                dp[i][M][1] = INT_MAX;  
                int sum = 0;

                for (int X = 1; X <= 2 * M; X++) {
                    if (i + X - 1 < piles.size()) {
                        sum += piles[i + X - 1];
                        dp[i][M][0] = max(dp[i][M][0], sum + dp[i + X][max(M, X)][1]);
                        dp[i][M][1] = min(dp[i][M][1], dp[i + X][max(M, X)][0]);
                    }
                }
            }
        }

        return dp[0][1][0];
    }
};