/* 
    Problem
     - Find the minimum element in the array of averages obtained by repeatedly removing the smallest and largest elements from an array of integers and adding their average to the array of averages

    Approaches
     1. Iterate from both ends of the sorted array, calculate the average, and update the minimum average

    Data Structures
    Algorithms

    Time Complexity
     - O(n•log(n))
    Space Complexity
     - O(1)
*/

#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    double minimumAverage(vector<int>& nums) {
        sort(nums.begin(), nums.end());
        double ans = INT_MAX;
        int l = 0;
        int r = nums.size() - 1;
        while (l < r) {
            ans = min(ans, static_cast<double>((nums[r] + nums[l]))/2);
            l++;
            r--;
        }
        return ans;
    }
};