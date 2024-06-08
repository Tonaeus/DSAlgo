/* 
    Approaches
     1. Find the index with the same remainder as a previous index
      a. Consider the first index being part of the sum
      b. Consider consecutive 0s

    Data Structures
     - Hash map
    Algorithms
     - Prefix sum

    Time Complexity
     - O(n)
    Space Complexity
     - O(n)
 */

#include <bits/stdc++.h>
using namespace std;

class Solution_1 {
public:
    bool checkSubarraySum(vector<int>& nums, int k) {
        unordered_map<int, int> mp = {{0, -1}};
        int sum = 0; 

        for (int i = 0; i < nums.size(); i++) {
            sum += nums[i];
            int r = sum % k;
            if (mp.find(r) != mp.end()) {
                if (i - mp[r] > 1) {
                    return true;
                }
                continue; 
            }
            mp[r] = i;
        }

        return false;
    }
};