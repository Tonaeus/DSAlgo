/* 
    Approaches
     1. Count the number of times the binary array starts with 0, transitions from 0 to 1, or transitions from 1 to 0
      a. Consider that if all indices up to index i are solved, then only indices j > i need to be solved

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
    int minOperations(vector<int>& nums) {
        int prev = nums[0];
        int ans = !prev;
        for (int i = 1; i < nums.size(); i++) {
            int curr = nums[i];
            if (prev != curr) { 
                ans++; 
                prev = curr;
            }
        }
        return ans;
    }
};

