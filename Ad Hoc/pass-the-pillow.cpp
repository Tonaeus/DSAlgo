/* 
    Problem
     - Find the person who is holding the pillow after some back and forth passes

    Approaches
     1. Count the number of passes in the final period

    Data Structures
    Algorithms

    Time Complexity
     - O(1)
    Space Complexity
     - O(1)
*/

#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int passThePillow(int n, int time) {
        int period = 2 * n - 2;
        int lst = n;
        int pass = time % period; 
        return pass >= lst ? period - pass + 1: pass + 1;
    }
};