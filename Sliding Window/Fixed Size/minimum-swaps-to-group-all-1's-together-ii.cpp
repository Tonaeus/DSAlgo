/* 
    Problem
     - Find the minimum number of swaps needed to group all the "1"s together at any location in the array, where a swap involves exchanging the values between two distinct positions

    Approaches
     1. Determine the window of size equal to the number of "1"s that contains the most "1"s, and then calculate the difference between the number of "1"s and the number of "0"s in that window
      a. Consider that the array is circular 

    Data Structures
    Algorithms
    
    Time Complexity
     - O(n)
    Space Complexity
     - O(1)
*/

#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int minSwaps(vector<int>& nums) {
        int n = nums.size();
        int cnt = accumulate(nums.begin(), nums.end(), 0);
        
        int mxWindow = 0;
        for (int i = 0; i < cnt; i++) {
            if (nums[i] == 1) {
                mxWindow++;
            }
        }

        int window = mxWindow;
        for (int i = cnt; i < n + cnt; i++) {
            if (nums[(i - cnt) % n] == 1) {
                window--;
            }
            if (nums[i % n] == 1) {
                window++;
            }
            mxWindow = max(mxWindow, window);
        }
        
        return cnt - mxWindow;
    }
};