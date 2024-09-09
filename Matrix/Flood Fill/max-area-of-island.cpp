/* 
    Problem 
     - Find the maximum area of an island in an m x n binary matrix, where an island is defined as a group of "1"s connected horizontally or vertically

    Approaches
     1. Count the nodes belonging to each island and keep track of the island with the most nodes

    Data Structures
     - Matrix
    Algorithms
     - Flood fill

    Time Complexity
     - O(m•n)
    Space Complexity
     - O(m•n)
*/

#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int maxAreaOfIsland(vector<vector<int>>& grid) {
        int m = grid.size();
        int n = grid[0].size();
        int ans = 0;

        for (int i = 0; i < m; i++) {
            for (int j = 0; j < n; j++) {
                if (grid[i][j] == 1) {
                    ans = max(ans, dfs(grid, i, j, m, n));
                }
            }
        }

        return ans;
    }
private:
    int dfs(vector<vector<int>>& grid, int i, int j, int m, int n) {
        if (i < 0 || i >= m || j < 0 || j >= n || grid[i][j] == 0) {
            return 0;
        }

        grid[i][j] = 0;

        return dfs(grid, i - 1, j, m, n) + dfs(grid, i + 1, j, m, n) + 
               dfs(grid, i, j - 1, m, n) + dfs(grid, i, j + 1, m, n) + 1;
    }
};