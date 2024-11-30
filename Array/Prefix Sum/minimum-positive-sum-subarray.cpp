/* 
    Problem
     - https://leetcode.com/problems/minimum-positive-sum-subarray/description/

    Patterns
     - Prefix Sum 
*/

#include <bits/stdc++.h>
using namespace std;

// Solution 1: Prefix Sum

// Time Complexity: O(n•(r - l))
// Space Complexity: O(n)

class Solution {
public:
    int minimumSumSubarray(vector<int>& nums, int l, int r) {
        int n = nums.size();

        vector<int> prefixSum(n + 1);
        for (int i = 1; i <= n; i++) {
            prefixSum[i] = prefixSum[i - 1] + nums[i - 1];
        }

        int ans = INT_MAX;
        for (int i = 0; i < n; i++) {
           for (int j = i + l - 1; j <= i + r - 1 and j < n; j++) {
                int sum = prefixSum[j + 1] - prefixSum[i];
                if (sum > 0) {
                    ans = min(ans, sum);
                }
           }
        }

        return ans == INT_MAX ? -1 : ans;
    }
};

// Solution 1: Space Optimized Prefix Sum

// Time Complexity: O(n•r)
// Space Complexity: O(1)

class Solution {
public:
    int minimumSumSubarray(vector<int>& nums, int l, int r) {
        int n = nums.size();

        int ans = INT_MAX;
        for (int i = 0; i < n; i++) {
            int sum = 0;
            for (int j = i; j <= i + r - 1 and j < n; j++) {
                sum += nums[j];
                if (j - i + 1 >= l and sum > 0) {
                    ans = min(ans, sum);
                }
            }
        }

        return ans == INT_MAX ? -1 : ans;
    }
};
