/* 
    Problem
     - Find the minimum difference between the largest and smallest values in an integer array, given the operation of changing the value of any element, where the operation can be performed at most 3 times

    Approaches
     1. Remove a total of 3 elements from either the leftmost end, the rightmost end, or both ends of the sorted array
      a. Consider that removing an element is equivalent to changing its value to any value strictly between the 3rd smallest and the 3rd largest values

    Data Structures
    Algorithms

    Time Complexity
     - O(n)
    Space Complexity
     - O(1)
*/

#include <bits/stdc++.h>
using namespace std;

// Solution 1

class Solution {
public:
    int minDifference(vector<int>& nums) {
        if (nums.size() < 5) return 0;

        sort(nums.begin(), nums.end());

        int ans = nums.back() - nums[0];

        int l = 0;
        int r = nums.size() - 4;
        while (l < 4) {
            ans = min(ans, nums[r] - nums[l]);
            l++;
            r++;
        }

        return ans;
    }
};

// Solution 1.1

class Solution {
public:
    int minDifference(vector<int>& nums) {
        if (nums.size() < 5) return 0;

        nth_element(nums.begin(), nums.begin() + 3, nums.end());
        sort(nums.begin(), nums.begin() + 4);
        nth_element(nums.begin() + 4, nums.end() - 4, nums.end());
        sort(nums.end() - 4, nums.end());

        int ans = nums.back() - nums[0];

        int l = 0;
        int r = nums.size() - 4;
        while (l < 4) {
            ans = min(ans, nums[r] - nums[l]);
            l++;
            r++;
        }

        return ans;
    }
};