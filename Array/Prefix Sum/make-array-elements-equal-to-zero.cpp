/* 
    Problem
     - https://leetcode.com/problems/make-array-elements-equal-to-zero/description/

    Patterns
     - Prefix Sum
*/

#include <bits/stdc++.h>
using namespace std;

// Solution 1: Brute Force 

// Time Complexity: O(n^2)
// Space Complexity: O(1)

class Solution {
public:
    int countValidSelections(vector<int>& nums) {
        int n = nums.size();
        
        int ans = 0;
        for (int i = 0; i < n; i++) {
            if (nums[i] == 0) {
                int before = accumulate(nums.begin(), nums.begin() + i, 0);
                int after = accumulate(nums.begin() + i, nums.end(), 0);

                if (before == after) {
                    ans += 2;
                }
                else if (abs(before - after) == 1) {
                    ans += 1;
                }
            }
        }

        return ans;
    }
};

// Solution 2: Prefix Sum 

// Time Complexity: O(n)
// Space Complexity: O(1)

class Solution {
public:
    int countValidSelections(vector<int>& nums) {
        int n = nums.size();
        int totalSum = accumulate(nums.begin(), nums.end(), 0);
        int prefixSum = 0;

        int ans = 0;
        for (int i = 0; i < n; i++) {
            if (nums[i] == 0) {
                int before = prefixSum;
                int after = totalSum - prefixSum; 

                if (before == after) {
                    ans += 2;
                }
                else if (abs(before - after) == 1) {
                    ans += 1;    
                }
            }

            prefixSum += nums[i];
        }

        return ans;
    }
};
