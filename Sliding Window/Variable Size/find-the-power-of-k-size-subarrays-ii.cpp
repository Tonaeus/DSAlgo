/* 
    Problem
     - Find the power of all subarrays of size "k" in the array "nums", where the power of a subarray is defined as its maximum element if the subarray is consecutive and sorted, and -1 otherwise 

    Approaches
     1. Check if the current window is of size k and is consecutive, and if so, add the current element to the array

    Data Structures
    Algorithms

    Time Complexity
     - O(n)
    Space Complexity
     - O(n-k)
*/

#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    vector<int> resultsArray(vector<int>& nums, int k) {
        int n = nums.size();
        vector<int> ans(n - k + 1, -1); 

        int l = 0;
        for (int r = 0; r < n; r++) {
            if (r - l + 1 > k) {
                l++;
            }
            if (r != 0 && nums[r] - 1 != nums[r - 1]) {
                l = r;
            }

            if (r - l + 1 == k) {
                ans[r - k + 1] = nums[r];
            }
        }

        return ans;
    }
};