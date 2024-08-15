/* 
    Problem
     - Find the indices of two elements in an integer array that add up to a target number

    Approaches
     1. Check if the current addend is a complement to a previous addend

    Data Structures
     - Hash map
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
    vector<int> twoSum(vector<int>& nums, int target) {
        unordered_map<int, int> mp;
        for (int i = 0; i < nums.size(); i++) {
            if (mp.contains(nums[i])) {
                return {mp[nums[i]], i};
            }
            else {
                mp[target - nums[i]] = i;
            }
        }
        return {};
    }
};