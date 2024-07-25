/* 
    Problem
     - Sort the array by the mapped value of each integer in increasing order, and if two integers have the same mapped value, sort them by their original position

    Approaches
     1. Store each integer's mapped value and position together in an array, and then sort the array first by mapped value and second by position

    Data Structures
    Algorithms

    Time Complexity
     - O(n•log(n))
    Space Complexity
     - O(n)
*/

#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    vector<int> sortJumbled(vector<int>& mapping, vector<int>& nums) {
        vector<pair<int, int>> a;
        for (int i = 0; i < nums.size(); i++) {
            int input = nums[i];
            int output = 0;
            int pos = 1;
            if (input == 0) {
                output = mapping[0];
            }
            while (input) {
                int dig = input % 10;
                input /= 10;
                output += mapping[dig] * pos;
                pos *= 10;
            }
            a.push_back({output, i});
        }

        auto cmp = [&](const pair<int, int>& a, const pair<int, int>& b){ return a.first != b.first ? a.first < b.first : a.second < b.second; };
        sort(a.begin(), a.end(), cmp);

        vector<int> ans;
        for (const auto& ele : a) {
            ans.push_back(nums[ele.second]);
        }

        return ans;
    }
};