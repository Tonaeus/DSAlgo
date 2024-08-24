/* 
    Problem
     - Find the maximum total energy boost that can be obtained in the next 'n' hours by consuming one of two energy drinks each hour, where there is a one-hour penalty for switching drinks

    Approaches
     1. Choose either the same energy drink or the other energy drink
      a. Subproblem: Maximum total energy boost
      b. Base case: Hour >= n
      c. States: Hour 

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
    long long maxEnergyBoost(vector<int>& energyDrinkA, vector<int>& energyDrinkB) {
        int n = energyDrinkA.size();
        vector<vector<long long>> dp(n, vector<long long>(2, -1));
        return max(dfs(energyDrinkA, energyDrinkB, 0, 0, dp), dfs(energyDrinkA, energyDrinkB, 0, 1, dp));
    }

private:
    long long dfs(vector<int>& energyDrinkA, vector<int>& energyDrinkB, int h, int d, vector<vector<long long>>& dp) {
        if (h >= energyDrinkA.size()) return 0;
        if (dp[h][d] != -1) return dp[h][d];

        long long ans = d == 0 ? energyDrinkA[h] : energyDrinkB[h];
        ans += max(dfs(energyDrinkA, energyDrinkB, h + 1, d, dp), dfs(energyDrinkA, energyDrinkB, h + 2, !d, dp));

        return dp[h][d] = ans;
    }
};

// Solution 1.1

class Solution {
public:
    long long maxEnergyBoost(vector<int>& energyDrinkA, vector<int>& energyDrinkB) {
        int n = energyDrinkA.size();
        vector<vector<long long>> dp(n + 2, vector<long long>(2, -1));
        dp[n][0] = dp[n + 1][0] = 0;
        dp[n][1] = dp[n + 1][1] = 0;

        for (int h = n - 1; h >= 0; h--) {
            dp[h][0] = energyDrinkA[h] + max(dp[h + 1][0], dp[h + 2][1]);
            dp[h][1] = energyDrinkB[h] + max(dp[h + 1][1], dp[h + 2][0]);
        }

        return max(dp[0][0], dp[0][1]);
    }
};

// Solution 1.2

class Solution {
public:
    long long maxEnergyBoost(vector<int>& energyDrinkA, vector<int>& energyDrinkB) {
        int n = energyDrinkA.size();
        vector<vector<long long>> dp(2, vector<long long>(2, -1));
        dp[0][0] = 0;
        dp[0][1] = 0;
        dp[1][0] = 0;
        dp[1][1] = 0;

        for (int h = n - 1; h >= 0; h--) {
            long long currA = energyDrinkA[h] + max(dp[0][0], dp[1][1]);
            long long currB = energyDrinkB[h] + max(dp[0][1], dp[1][0]);

            dp[1][0] = dp[0][0];
            dp[1][1] = dp[0][1];
            dp[0][0] = currA;
            dp[0][1] = currB;
        }

        return max(dp[0][0], dp[0][1]);
    }
};