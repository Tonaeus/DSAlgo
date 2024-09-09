/* 
    Problem
     - Find the number of regions in a square grid, where the grid is represented by a string array containing the characters "/", "\", and " ", which divide the grid into separate regions

    Approaches
     1. Convert the grid into a binary matrix representation, and then count the number of groups of horizontally and vertically adjacent "0"s 

    Data Structures
     - Matrix
    Algorithms
     - Flood Fill

    Time Complexity
     - O(n^2)
    Space Complexity
     - O(n^2)
*/

#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int regionsBySlashes(vector<string>& grid) {
        int n = grid.size();
        vector<vector<int>> g(n * 3, vector<int>(n * 3));
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < n; j++) {
                int r = i * 3;
                int c = j * 3; 
                if (grid[i][j] == '/') {
                    g[r + 2][c] = 1;
                    g[r + 1][c + 1] = 1;
                    g[r][c + 2] = 1;
                }
                else if (grid[i][j] == '\\') {
                    g[r][c] = 1;
                    g[r + 1][c + 1] = 1;
                    g[r + 2][c + 2] = 1;
                }
            }
        }

        int ans = 0;
        for (int i = 0; i < n * 3; i++) {
            for (int j = 0; j < n * 3; j++) {
                if (g[i][j] == 0) {
                    dfs(g, n * 3, i, j);
                    ans++;
                }
            }
        }

        return ans;
    }

private: 
    void dfs(vector<vector<int>>& g, int n, int i, int j) {
        if (i < 0 || i >= n || j < 0 || j >= n || g[i][j] == 1) {
            return;
        }

        g[i][j] = 1;

        dfs(g, n, i - 1, j);
        dfs(g, n, i + 1, j);
        dfs(g, n, i, j - 1);
        dfs(g, n, i, j + 1);
    }
};