/* 
    Problem
     - Find out if there exists a good subarray, given an integer array and an integer "k", where a good subarray is a subarray with a size of at least 2 and a sum that is a multiple of "k"

    Approaches
     1. Determine if there are two different positions with the same modulo "k"
      a. Consider that the initial modulo "k" is 0
      b. Consider that consecutive elements can have the same modulo "k"

    Data Structures
     - Hash map
    Algorithms
     - Prefix sum

    Time Complexity
     - O(n)
    Space Complexity
     - O(k)
*/

#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    bool checkSubarraySum(vector<int>& nums, int k) {
        unordered_map<int, int> mp = {{0, -1}};
        int sum = 0; 

        for (int i = 0; i < nums.size(); i++) {
            sum = (sum + nums[i]) % k;

            if (mp.find(sum) != mp.end()) {
                if (i - mp[sum] > 1) {
                    return true;
                }
            }
            else {
                mp[sum] = i;  
            }
        }

        return false;
    }
};