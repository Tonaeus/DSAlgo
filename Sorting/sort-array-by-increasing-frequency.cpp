/* 
    Problem
     - Sort the array by the frequency of each integer in increasing order, and if two integers have the same frequency, sort them in decreasing order

    Approaches
     1. Count the frequency of each integer, and then sort the array first by frequency and second by value

    Data Structures
     - Hash map
    Algorithms

    Time Complexity
     - O(n•log(n));
    Space Complexity
     - O(n)
*/

#include <bits/stdc++.h>
using namespace std;

// Solution 1

class Solution {
public:
    vector<int> frequencySort(vector<int>& nums) {
        unordered_map<int, int> mp;
        for (int n : nums) {
            mp[n]++;
        }

        vector<pair<int,int>> a; 
        for (const auto [key, val] : mp) {
            a.push_back({val, key});
        }

        auto cmp = [](const pair<int, int>& a, const pair<int, int>& b) { return a.first != b.first ? a.first < b.first : a.second > b.second; };
        sort(a.begin(), a.end(), cmp);

        vector<int> ans;
        for (auto& ele : a) {
            for (int i = 0; i < ele.first; i++) {
                ans.push_back(ele.second);
            }
        }

        return ans;
    }
};

// Solution 1.1

class Solution {
public:
    vector<int> frequencySort(vector<int>& nums) {
        unordered_map<int, int> mp;
        for (int n : nums) {
            mp[n]++;
        }

        auto cmp = [&](const int a, const int b) { return mp[a] != mp[b] ? mp[a] < mp[b] : a > b; };
        sort(nums.begin(), nums.end(), cmp);     

        return nums;
    }
};