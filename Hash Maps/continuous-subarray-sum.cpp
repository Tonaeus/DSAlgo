/* 
    Approaches
     1. Find an index where the remainder has already been seen
      a. Consider the initial remainder being 0
      b. Consider consecutive elements having the same remainder

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

class Solution_1 {
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