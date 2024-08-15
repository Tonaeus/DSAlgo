/* 
    Problem
     - Find the kth smallest absolute difference between any two elements in an integer array

    Approaches
     1. Search from 0 to the maximum difference between any pairs to identify the difference with "k" pairs having a difference equal to or less than it
      a. Consider that a greater difference will have more pairs with a difference equal to or less than it
      b. Consider that there may be multiple differences with "k" pairs having a difference equal to or less than them
      c. Consider that if x is a potential difference, then y > x is not a potential difference 
      d. Consider that if x is not a potential difference, then y < x is not a potential difference

    Data Structures
    Algorithms
     - Binary search

    Time Complexity
     - O(n•log(n)+n•log(M)) -> n = size of nums, M = maximum difference between any 2 pair
    Space Complexity
     - O(log(n))
*/

#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int smallestDistancePair(vector<int>& nums, int k) {
        sort(nums.begin(), nums.end());

        int lo = 0;
        int hi = nums.back() - nums.front();

        while (lo <= hi) {
            int mid = lo + (hi - lo) / 2;
            
            if (count(nums, mid) >= k) {
                hi = mid - 1;
            }
            else {
                lo = mid + 1;
            }
        }

        return lo;
    }
private: 
    int count(vector<int>& nums, int diff) {
        int cnt = 0; 

        int l = 0;
        for (int r = 0; r < nums.size(); r++) {
            while (nums[r] - nums[l] > diff) {
                l++;
            }
            cnt += r - l;
        }

        return cnt; 
    }
};