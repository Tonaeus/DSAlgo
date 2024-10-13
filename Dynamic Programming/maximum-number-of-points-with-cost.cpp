/* 
    Problem
     - Find the maximum number of points by choosing one cell per row in an m x n integer matrix, where the points are calculated as the sum of the chosen cells minus the absolute difference between the column indices of the chosen cells in consecutive rows

    Approaches
     1. Choose the cell from the previous row that would yield the greatest increase in points for each cell recursively, and then choose the cell with the most points in the last row
      a. Subproblem 1: Maximum number of points for each cell 
      b. Base case 1: Row = 0
      c. State 1: Row
      d. Subproblem 2: Maximum number of points from the cell in the previous row and to the left of the current column
      e. Base case 2: Column = 0
      f. State 2: Column 
      g. Subproblem 3: Maximum number of points from the cell in the previous row and to the right of the current column
      h. Base case 3: Column = n - 1
      i. State 3: Column
      j. Consider that if the maximum points in each cell of row i are solved, then the maximum points in each cell of row i + 1 can also be solved
      k. Consider that if the maximum points coming from the left and right are solved, then the maximum point for the current cell can also be solved

    Data Structures
    Algorithms

    Time Complexity
     - O(m•n)
    Space Complexity
     - O(n)
*/

#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    long long maxPoints(vector<vector<int>>& points) {
        int m = points.size();
        int n = points[0].size();

        vector<long long> dp(n, -1);
        for (int i = 0; i < n; i++) {
            dp[i] = points[0][i];
        }

        vector<long long> left(n);
        vector<long long> right(n);

        for (int i = 1; i < m; i++) {
            left[0] = dp[0];
            for (int j = 1; j < n; j++) {
                left[j] = max(left[j - 1] - 1, dp[j]);
            }

            right[n - 1] = dp[n - 1];
            for (int j = n - 2; j >= 0; j--) {
                right[j] = max(right[j + 1] - 1, dp[j]);
            }

            for (int j = 0; j < n; j++) {
                dp[j] = points[i][j] + max(left[j], right[j]);
            }
        }

        return *max_element(dp.begin(), dp.end());
    }
};