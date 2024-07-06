/* 
    Approaches
     1. Count the freqency of each integer and sort by highest to lowest frequency 

    Data Structures
     - Heap
    Algorithms
     - Bucket sort

    Time Complexity
     - O(n)
    Space Complexity
     - O(n)
*/

#include <bits/stdc++.h>
using namespace std;

// Solution 1

class Solution {
public:
    vector<int> topKFrequent(vector<int>& nums, int k) {
        unordered_map<int, int> mp;
        vector<pair<int,int>> mxh;
        vector<int> ans;

        for (int n : nums) {
            mp[n]++;
        } 

        for (auto [k ,v] : mp) {
            mxh.push_back({v, k});
        }
        make_heap(mxh.begin(), mxh.end());

        for (int i = 0; i < k; i++) {
            ans.push_back(mxh.front().second);   
            pop_heap(mxh.begin(), mxh.end());    
            mxh.pop_back();    
        }

        return ans;
    }
};

// Solution 1.1

class Solution {
public:
    vector<int> topKFrequent(vector<int>& nums, int k) {
        unordered_map<int, int> mp;
        vector<vector<int>> freq(nums.size() + 1);
        vector<int> ans;

        for (int n : nums) {
            mp[n]++;
        } 

        for (auto [k ,v] : mp) {
            freq[v].push_back(k);
        }

        for (int i = nums.size(); i >= 0; i--) {
            while (!freq[i].empty() && k > ans.size()) {
                ans.push_back(freq[i].back());
                freq[i].pop_back();
            }
        }

        return ans;
    }
};