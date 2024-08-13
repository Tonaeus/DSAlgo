/* 
    Problem 
     - Find the number of islands in an m x n binary grid, where an island is defined as a group of "1"s connected horizontally or vertically

    Approaches
     1. Visit each node and set all nodes of each encountered island to '0' before continuing to the next node

    Data Structures
     - Graph
    Algorithms
     - Depth-first search

    Time Complexity
     - O(m•n)
    Space Complexity
     - O(m•n)
*/

#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int numIslands(vector<vector<char>>& grid) {
        int m = grid.size();
        int n = grid[0].size();
        int ans = 0;

        for (int i = 0; i < m; i++) {
            for (int j = 0; j < n; j++) {
                if (grid[i][j] == '1') {
                    dfs(grid, i, j, m, n);
                    ans++;
                }
            }
        }

        return ans;
    }
private:
    void dfs(vector<vector<char>>& grid, int i, int j, int m, int n) {
        if (i < 0 || i >= m || j < 0 || j >= n || grid[i][j] == '0') {
            return;
        }

        grid[i][j] = '0';

        dfs(grid, i - 1, j, m, n);
        dfs(grid, i + 1, j, m, n);
        dfs(grid, i, j - 1, m, n);
        dfs(grid, i, j + 1, m, n);
    }
};