/* 
    Problem
     - Find the minimum number of operations needed to make every element in an integer array divisible by 3, where each operation consists of adding or subtracting 1 from any element

    Approaches
     1. Count the number of elements that are not divisible by 3

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
    int minimumOperations(vector<int>& nums) {
        int ans = 0;
        for (int i = 0; i < nums.size(); i++) {
            if (nums[i] % 3 != 0) ans++;
        }
        return ans;
    }
};