/* 
    Problem
     - Find out if a player can win, given that a player wins by choosing either all single-digit or all double-digit numbers, and the sum of their chosen numbers is strictly greater than the sum of the remaining numbers

    Approaches
     1. Calculate the sum of single-digit numbers and the sum of double-digit numbers, and then compare if the sums are the same

    Data Structures
    Algorithms

    Time Complexity
     - O(n)
    Space Complexity
     - O(1)
*/

#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    bool canAliceWin(vector<int>& nums) {
        int singleSum = 0;
        int doubleSum = 0;
        for (int n : nums) {
            if (n < 10) {
                singleSum += n;
            } 
            else {
                doubleSum += n;
            }
        }
        return singleSum != doubleSum;
    }
};