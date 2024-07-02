/* 
    Approaches
     1. Keep track of previously seen elements and check if new elements have already been seen

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