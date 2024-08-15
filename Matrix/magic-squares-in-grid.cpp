/* 
    Problem
     - Find the number of magic squares in a "row" x "col" grid of integers, where a magic square is a 3 x 3 grid filled with distinct numbers from 1 to 9, such that each row, column, and diagonal has the same sum

    Approaches
     1. Scan each 3 by 3 grid, and count it if the grid has distinct numbers from 1 to 9 and if each row, column, and diagonal sums to 15
      a. Consider that each row, column, and diagonal will have a sum of 15 because 1 + 2 + 3 + ... + 9 = 45 and 45 / 3 = 15
      b. Consider that the center will always be 5, the opposite sides will always add up to 10, and the opposite corners will always add up to 10

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
    int numMagicSquaresInside(vector<vector<int>>& grid) {
        int m = grid.size();
        int n = grid[0].size();
        if (m < 3 || n < 3) return 0;
        
        int ans = 0;
        for (int i = 1; i < m - 1; i++) {
            for (int j = 1; j < n - 1; j++) {
                if (helper(grid, i, j)) {
                    ans++;
                }
            }
        }

        return ans;
    }

private:
    bool helper(vector<vector<int>>& grid, int r, int c) {
        vector<bool> seen(10);
        for (int i = 0; i < 3; i++) {
            for (int j = 0; j < 3; j++) {
                int num = grid[r - 1 + i][c - 1 + j];
                if (num < 1 || num > 9 || seen[num]) {
                    return false;
                }
                seen[num] = true;
            }
        }

        // Check the diagonals
        if (grid[r - 1][c - 1] + grid[r + 1][c + 1] != 10) return false;
        if (grid[r - 1][c + 1] + grid[r + 1][c - 1] != 10) return false;

        // Check the first row and column 
        if (grid[r - 1][c - 1] + grid[r - 1][c] + grid[r - 1][c + 1] != 15) return false; 
        if (grid[r - 1][c - 1] + grid[r][c - 1] + grid[r + 1][c - 1] != 15) return false; 
        
        // Check the second row and column
        if (grid[r][c - 1] + grid[r][c + 1] != 10) return false;
        if (grid[r - 1][c] + grid[r + 1][c] != 10) return false;

        return true;
    }
};