/* 
    Problem
     - Find all integers that appear in both of the given arrays, including duplicates

    Approaches
     1. Count the frequency of each integer in the first array, then check if each element in the second array exists in this frequency

    Data Structures
     - Array
    Algorithms

    Time Complexity
     - O(max(n, m)) -> n = size of nums1, m = size of nums2
    Space Complexity
     - O(n)
*/

#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    vector<int> intersect(vector<int>& nums1, vector<int>& nums2) {
        vector<int> freq(1001);
        vector<int> ans;

        for (int n : nums1) {
            freq[n]++;
        }

        for (int n : nums2) {
            if (freq[n] >= 1) {
                ans.push_back(n);
                freq[n]--;
            }
        }

        return ans;
    }
};