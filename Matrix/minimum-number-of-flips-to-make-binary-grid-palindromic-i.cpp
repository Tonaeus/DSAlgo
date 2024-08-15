/* 
    Problem
     - Find the minimum number of cells in a binary matrix that need to be flipped to make either all rows or all columns palindromic

    Approaches
     1. Count the mirrored difference between the first and second halves of each row and column, and then determine whether making all rows or all columns palindromic requires fewer flips

    Data Structures
     - Matrix
    Algorithms

    Time Complexity
     - O(m•n)
    Space Complexity
     - O(1)
*/

#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int minFlips(vector<vector<int>>& grid) {
        int m = grid.size();
        int n = grid[0].size();
        int rowRes = 0;
        for (int i = 0; i < m; i++) {
            rowRes += rowHelper(grid, i, n);
        }
        int colRes = 0;
        for (int i = 0; i < n; i++) {
            colRes += colHelper(grid, i, m);
        }
        return min(rowRes, colRes);
    }
private:
    int rowHelper(vector<vector<int>>& grid, int row, int size) {
        int l = 0;
        int r = size - 1;
        int res = 0;
        while (l < r) {
            if (grid[row][l] != grid[row][r]) {
                res++;
            }
            l++;
            r--;
        }
        return res;
    }
    int colHelper(vector<vector<int>>& grid, int col, int size) {
        int b = 0;
        int t = size - 1;
        int res = 0;
        while (b < t) {
            if (grid[b][col] != grid[t][col]) {
                res++;
            }
            b++;
            t--;
        }
        return res;
    }
};