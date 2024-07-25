/* 
    Problem 
     - Find the minimum number of moves needed to make every integer in the array unique, given that each move increments an integer by 1

    Approaches
     1. Calculate the total increments needed so that each element is greater than the previous one in the sorted array

    Data Structures
    Algorithms

    Time Complexity
     - O(n•log(n))
    Space Complexity
     - O(log(n))
*/

#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int minIncrementForUnique(vector<int>& nums) {
        int ans = 0;
        sort(nums.begin(), nums.end());

        for (int i = 1; i < nums.size(); i++) {
            if (nums[i] <= nums[i - 1]) {
                ans += nums[i - 1] - nums[i] + 1;
                nums[i] = nums[i - 1] + 1;
            }
        }
        
        return ans;
    }   
};