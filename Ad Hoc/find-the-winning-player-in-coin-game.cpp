/* 
    Problem
     - Find the winning player, given that players pick up coins with a total value of 115 from coins with values of 75 and 10, where there are "x" coins with a value of 75 and "y" coins with a value of 10

    Approaches
     1. Check if there are a sufficient number of coins after each turn
      a. Consider that the same amount of each type of coin will be used in each turn

    Data Structures
    Algorithms

    Time Complexity
     - O(1)
    Space Complexity
     - O(1)
*/

#include <bits/stdc++.h>
using namespace std;

// Solution 1 

class Solution {
public:
    string losingPlayer(int x, int y) {
        bool flag = false;
        while (x >= 1 && y >= 4) {
            x -= 1;
            y -= 4;
            flag = !flag;
        }
        return flag ? "Alice" : "Bob";
    }
};

// Solution 1.1

class Solution {
public:
    string losingPlayer(int x, int y) {
        return min(x, y/4) % 2 == 1 ? "Alice" : "Bob";
    }
};