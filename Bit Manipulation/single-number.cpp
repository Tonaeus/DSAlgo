/* 
    Problem 
     - Find the number that appears only once, given an integer array where every element, except for one, appears twice

    Approaches
     1. Calculate the XOR of the array
      a. Consider that the XOR of a number with itself is 0

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
    int singleNumber(vector<int>& nums) {
        int ans = 0;
        for (int n: nums) {
            ans ^= n;
        }
        return ans;
    }
};