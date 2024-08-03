/* 
    Problem
     - Find out if any integer appears more than once in an integer array

    Approaches
     1. Check if the current element is equal to a previous element

    Data Structures
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
    bool containsDuplicate(vector<int>& nums) {
        unordered_set<int> s;
        for (int i = 0; i < nums.size(); i++) {
            if (s.contains(nums[i])) {
                return true;
            }
            s.insert(nums[i]);
        }
        return false;
    }
};