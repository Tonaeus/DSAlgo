/* 
    Problem
     - Find the minimum possible area of a rectangle, given a binary matrix, such that all the "1"s in grid lie inside the area

    Approaches
     1. Locate the farthest element with a 1 to the left, right, bottom, and top, and then calculate the area

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
    int minimumArea(vector<vector<int>>& grid) {
        int l = INT_MAX, r = 0, b = INT_MAX, t = 0;
        
        for (int i = 0; i < grid.size(); i++) {
            for (int j = 0; j < grid[0].size(); j++) {
                if (grid[i][j] == 1) {
                    l = min(l, j);
                    r = max(r, j);
                    b = min(b, i);
                    t = max(t, i);
                }
            }
        }

        return (r - l + 1) * (t - b + 1);
    }
};



