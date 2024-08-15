/* 
    Problem 
     - Find the size of the longest subarray, where the difference between any two elements of the subawaay is less or equal to the limit

    Approaches
     1. Shift the subarray's start to the position following the element causing the difference between the smallest and largest element in the subarray to exceed the limit 

    Data Structures
     - Monotonic queue
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
    int longestSubarray(vector<int>& nums, int limit) {
        int ans = 0;
        deque<int> imq, dmq;

        int l = 0;
        for (int r = 0; r < nums.size(); r++) {
            while (!imq.empty() && imq.back() > nums[r]) {
                imq.pop_back();
            }
            imq.push_back(nums[r]);
            
            while (!dmq.empty() && dmq.back() < nums[r]) {
                dmq.pop_back();
            }
            dmq.push_back(nums[r]);

            while (dmq.front() - imq.front() > limit) {
                if (imq.front() == nums[l]) {
                    imq.pop_front();
                }
                if (dmq.front() == nums[l]) {
                    dmq.pop_front();
                }
                l++;
            }

            ans = max(ans, r - l + 1);
        }

        return ans;
    }
};