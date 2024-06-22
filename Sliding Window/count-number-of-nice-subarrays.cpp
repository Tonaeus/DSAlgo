/* 
    Approaches
     1. Count the amount of even numbers up until the first odd number + 1 each time there is a new odd number in the k odd numbers subarray

    Data Structures
     - Queue
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
    int numberOfSubarrays(vector<int>& nums, int k) {
        int ans = 0;
        queue<pair<int, int>> q;
        for (int i = 0; i < nums.size(); i++) {
            if (nums[i] % 2 != 0) {
                q.push({q.empty() ? -1 : q.back().second, i});
            }
            if (q.size() > k) q.pop();
            if (q.size() == k) { 
                ans += q.front().second - q.front().first;
            }
        }
        return ans;
    }
};

class Solution {
public:
    int numberOfSubarrays(vector<int>& nums, int k) {
        int ans = 0;
        int count = 0;
        int l = 0, mid = 0;
        for (int r = 0; r < nums.size(); r++) {
            if (nums[r] % 2 != 0) count++;
            while (count > k) {
                if (nums[l] % 2 != 0) count--;
                l++;
            }
            if (count == k) {
                mid = l;
                while (nums[mid] % 2 == 0) { mid++; }
                ans += mid - l + 1;
            }
        }
        return ans;
    }
};