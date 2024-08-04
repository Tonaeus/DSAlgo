/* 
    Problem
     - Find the number of players who win the game, where player "i" wins if they pick strictly more than "i" balls of the same colour

    Approaches
     1. Count the number of balls of each colour that each player picks, and check if a player picks any ball of the same colour "i + 1" times
      a. Consider that a player can pick strictly more than "i" balls of the same colour multiple times

    Data Structures
     - Array
     - Hash set
    Algorithms

    Time Complexity
     - O(n)
    Space Complexity
     - O(n)
*/

#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int winningPlayerCount(int n, vector<vector<int>>& pick) {
        vector<vector<int>> mp(n, vector<int>(10 + 1));
        unordered_set<int> set;

        for (auto& p : pick) {
            int player = p[0];
            int ball = p[1];

            mp[player][ball]++;

            if (mp[player][ball] == player + 1) {
                set.insert(player);
            }
        }

        return set.size();
    }
};