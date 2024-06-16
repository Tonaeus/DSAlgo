/* 
    Approaches
     1. Solve the interval from 1 to n and add the patch that increases the interval the most whenever a patch is needed
      a. Consider that if [0, a] is solved, then adding b, where b <= a + 1, means that [0, a + b] is solved 

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
    int minPatches(vector<int>& nums, int n) {
        long upperBound = 1;
        int i = 0;
        int ans = 0;
        
        while (upperBound <= n) {
            if (i < nums.size() && nums[i] <= upperBound) {
                upperBound += nums[i];
                i++;
            }
            else {
                upperBound += upperBound;
                ans++;
            }
        }

        return ans;
    }
};