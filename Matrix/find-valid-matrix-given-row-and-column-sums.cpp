/* 
    Problem
     - Find the matrix, given the sum of each row and the sum of each column

    Approaches
     1. Set the current element in the matrix to the minimum between its current row sum and current column sum
      a. Consider that the total row sum equals the total column sum
      b. Consider that if the current element is greater than the minimum, then there will be a surplus in the row or column sum
      c. Consider that if the current element is less than the minimum, there will be a deficit in the row or column sum

    Data Structures
     - Matrix
    Algorithms

    Time Complexity
     - O(m•n)
    Space Complexity
     - O(m•n)
*/

#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    vector<vector<int>> restoreMatrix(vector<int>& rowSum, vector<int>& colSum) {
        int row = rowSum.size();
        int col = colSum.size();
        vector<vector<int>> ans(row, vector<int>(col, 0));

        for (int i = 0; i < row; i++) {
            for (int j = 0; j < col; j++) {
                ans[i][j] = min(rowSum[i], colSum[j]);

                rowSum[i] -= ans[i][j];
                colSum[j] -= ans[i][j]; 
            }
        }

        return ans;
    }
};