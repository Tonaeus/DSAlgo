/* 
    Problem

    Approaches

    Data Structures
    Algorithms

    Time Complexity
    Space Complexity
*/

#include <bits/stdc++.h>
using namespace std;

class neighborSum {
public:
    neighborSum(vector<vector<int>>& grid) : grid(grid), n(grid.size()) {}

    int adjacentSum(int value) {
        auto [row, col] = findPosition(value);
        int l = col == 0 ? 0 : grid[row][col - 1];
        int r = col == n - 1 ? 0 : grid[row][col + 1];
        int u = row == 0 ? 0 : grid[row - 1][col];
        int d = row == n - 1 ? 0 : grid[row + 1][col];
        return l + r + u + d;
    }

    int diagonalSum(int value) {
        auto [row, col] = findPosition(value);
        int ul = row == 0 || col == 0 ? 0 : grid[row - 1][col - 1];
        int ur = row == 0 || col == n - 1 ? 0 : grid[row - 1][col + 1];  
        int dl = row == n - 1 || col == 0 ? 0 : grid[row + 1][col - 1];
        int dr = row == n - 1 || col == n - 1 ? 0 : grid[row + 1][col + 1];
        return ul + ur + dl + dr;
    }

private:
    vector<vector<int>> grid;
    int n;

    pair<int, int> findPosition(int value) {
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < n; j++) {
                if (grid[i][j] == value) {
                    return {i, j};
                }
            }
        }
        return {-1, -1};
    }
};