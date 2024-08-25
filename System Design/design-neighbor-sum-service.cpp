/* 
    Problem
     - Create a class that returns the sum of adjacent or diagonal neighbours of a specified value, given in an n x n grid with distinct values in the range [0, n^2 - 1]

    Approaches
     1. Map values to their positions to quickly compute the sum of adjacent or diagonal neighbours of a specified value

    Data Structures
     - Array
    Algorithms

    Time Complexity
     - Constructor: O(n^2)
     - `adjacentSum`: O(1)
     - `diagonalSum`: O(1)
    Space Complexity
     - O(n^2)
*/

#include <bits/stdc++.h>
using namespace std;

class NeighborSum {
public:
    NeighborSum(vector<vector<int>>& grid) : grid(grid), n(grid.size()) {
        mp.resize(n * n, {-1, -1});
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < n; j++) {
                mp[grid[i][j]] = {i, j};
            }
        }
    }

    int adjacentSum(int value) {
        auto [row, col] = mp[value];
        int l = col == 0 ? 0 : grid[row][col - 1];
        int r = col == n - 1 ? 0 : grid[row][col + 1];
        int u = row == 0 ? 0 : grid[row - 1][col];
        int d = row == n - 1 ? 0 : grid[row + 1][col];
        return l + r + u + d;
    }

    int diagonalSum(int value) {
        auto [row, col] = mp[value];
        int ul = row == 0 || col == 0 ? 0 : grid[row - 1][col - 1];
        int ur = row == 0 || col == n - 1 ? 0 : grid[row - 1][col + 1];  
        int dl = row == n - 1 || col == 0 ? 0 : grid[row + 1][col - 1];
        int dr = row == n - 1 || col == n - 1 ? 0 : grid[row + 1][col + 1];
        return ul + ur + dl + dr;
    }

private:
    vector<vector<int>> grid;
    vector<pair<int, int>> mp;
    int n;
};