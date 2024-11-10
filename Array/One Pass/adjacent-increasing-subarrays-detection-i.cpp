/* 
    Problem
     - https://leetcode.com/problems/adjacent-increasing-subarrays-detection-i/description/

    Patterns
     - One Pass
*/

#include <bits/stdc++.h>
using namespace std;

// Solution 1: One Pass

// Time Complexity: O(n)
// Space Complexity: O(n)

class Solution {
public:
    bool hasIncreasingSubarrays(vector<int>& nums, int k) {
        int n = nums.size();
        vector<int> arr(n, 1);
        
        for (int i = 1; i < n; i++) {
            if (nums[i] > nums[i - 1]) {
                arr[i] = arr[i - 1] + 1;
            }
            if (i >= k and arr[i] >= k and arr[i - k] >= k) {
                return true;
            }
        }

        return false;
    }
};

// Solution 2: Space Optimized One Pass

// Time Complexity: O(n)
// Space Complexity: O(1)

class Solution {
public:
    bool hasIncreasingSubarrays(vector<int>& nums, int k) {
        int n = nums.size();
        int prev = nums[0];
        nums[0] = 1;
        
        for (int i = 1; i < n; i++) {
            int curr = nums[i];
            nums[i] = curr > prev ? nums[i - 1] + 1 : 1;

            if (i >= k and nums[i] >= k and nums[i - k] >= k) {
                return true;
            }

            prev = curr;
        }

        return false;
    }
};