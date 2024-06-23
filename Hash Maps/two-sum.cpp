/* 
    Approaches
     1. Keep track of potential complements so that if a complement of the current addend is found, then the solution is also found

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