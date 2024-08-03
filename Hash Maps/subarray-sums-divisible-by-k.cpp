/* 
    Problem
     - Find the number of non-empty subarrays that have a sum divisible by "k"

    Approaches
     1. Count the positions that have the same modulo "k" as a previous position
      a. Consider that the initial modulo "k" is 0
      b. Consider joining the new subarrays with the previous subarrays

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
    int subarraysDivByK(vector<int>& nums, int k) {
        unordered_map<int, int> mp = {{0, 1}};
        int sum = 0, ans = 0;

        for (int i = 0; i < nums.size(); i++) {
            sum = (sum + nums[i]) % k;
            if (sum < 0) { 
                sum += k;
            }
            if (mp.find(sum) != mp.end()) {
                ans += mp[sum];
                mp[sum]++;
            }
            else {
                mp[sum] = 1;
            }
        }

        return ans;
    }
};