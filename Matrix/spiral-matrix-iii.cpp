/* 
    Problem
     - Find the order of coordinates visited in a "rows" x "cols" grid by moving in a clockwise spiral pattern from a given starting position

    Approaches
     1. Move to the right by 1 step, down by 1 step, left by 2 steps, up by 2 steps, and repeat this sequence such that the steps increase by 1 every 2 direction changes

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
    vector<vector<int>> spiralMatrixIII(int rows, int cols, int rStart, int cStart) {
        vector<vector<int>> ans = {{rStart, cStart}};
        vector<vector<int>> dir = {{0, 1}, {1, 0}, {0, -1}, {-1, 0}}; // right, down, left, up
        int steps = 1;
        int d = 0;

        int r = rStart, c = cStart;
        while (ans.size() < rows * cols) {
            for (int i = 0; i < 2; i++) {
                for (int j = 0; j < steps; j++) {
                    r += dir[d][0];
                    c += dir[d][1];
                    if ((0 <= r && r < rows) && (0 <= c && c < cols)) {
                        ans.push_back({r, c});
                    }
                }
                d = (d + 1) % 4;
            }
            steps++;
        }

        return ans;
    }
};