/* 
    Problem
     - Find the nth ugly number, where an ugly number is a positive integer with prime factors limited to 2, 3, and 5

    Approaches
     1. Choose the minimum of the three candidates for the ith ugly number, where each candidate is the product of one of the prime factors 2, 3, or 5 and its respective next ugly number
      a. Subproblem: ith ugly number
      b. Base case: i = 1
      c. States: i
      d. Subproblem: Next ugly number for each of the prime factors 2, 3, and 5
      e. Base case: i = 1
      f. State: i

    Data Structures
    Algorithms

    Time Complexity
     - O(n)
    Space Complexity
     - O(n)
*/

#include <bits/stdc++.h>
using namespace std;

// Solution 1

class Solution {
public:
    int nthUglyNumber(int n) {
        vector<int> dp(n + 1);
        dp[1] = 1;

        vector<int> p2(n + 1);
        vector<int> p3(n + 1);
        vector<int> p5(n + 1);
        p2[1] = 1;
        p3[1] = 1;
        p5[1] = 1;

        for (int i = 2; i <= n; i++) {
            int twoMul = dp[p2[i - 1]] * 2;
            int threeMul = dp[p3[i - 1]] * 3;
            int fiveMul = dp[p5[i - 1]] * 5;

            dp[i] = min({twoMul, threeMul, fiveMul});

            p2[i] = dp[i] == twoMul ? p2[i - 1] + 1 : p2[i - 1];
            p3[i] = dp[i] == threeMul ? p3[i - 1] + 1 : p3[i - 1];
            p5[i] = dp[i] == fiveMul ? p5[i - 1] + 1 : p5[i - 1];
        }
        
        return dp[n];
    }
};

// Solution 1.1

class Solution {
public:
    int nthUglyNumber(int n) {
        vector<int> dp(n + 1);
        dp[1] = 1;

        int p2 = 1;
        int p3 = 1;
        int p5 = 1;

        for (int i = 2; i <= n; i++) {
            int twoMul = dp[p2] * 2;
            int threeMul = dp[p3] * 3;
            int fiveMul = dp[p5] * 5;

            dp[i] = min({twoMul, threeMul, fiveMul});

            if (dp[i] == twoMul) p2++;
            if (dp[i] == threeMul) p3++;
            if (dp[i] == fiveMul) p5++;
        }
        
        return dp[n];
    }
};