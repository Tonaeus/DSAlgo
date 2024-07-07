/* 
    Problem
     - Find the maximum number of filled bottles, given the operation to exchange empty bottles

    Approaches
     1. Calculate the sum of the initial filled bottles and the exchanged filled bottles 
      a. Consider that every numExhange - 1 empty bottles can be exchanged by borrowing an empty bottle
      b. Consider setting aside an empty bottle from the initial bottles 

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
    int numWaterBottles(int numBottles, int numExchange) {
        return numBottles + (numBottles - 1) / (numExchange - 1);
    }
};