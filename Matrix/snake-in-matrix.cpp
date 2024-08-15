/* 
    Problem
     - Find the final cell where a snake ends up in a grid, given that the snake starts at cell 0 and follows a sequence of commands

    Approaches
     1. Determine the row and column indices of the snake after each command, and then calculate the linear index from the final row and column indices

    Data Structures
     - Matrix
     - Hash map
    Algorithms

    Time Complexity
     - O(m) -> m = number of commands
    Space Complexity
     - O(1)
*/

#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int finalPositionOfSnake(int n, vector<string>& commands) {
        unordered_map<string, vector<int>> mp = {
            {"UP", {-1, 0}},
            {"RIGHT", {0, 1}},
            {"DOWN", {1, 0}},
            {"LEFT", {0, -1}}
        };

        int i = 0, j = 0;
        for (auto c : commands) {
            i += mp[c][0];
            j += mp[c][1];
        }

        return (i * n) + j;
    }
};