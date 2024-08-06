/* 
    Problem
     - Find the sum of the numbers from the 1-based index "left" to "right" inclusively in the sorted array formed by the sums of all non-empty subarrays of "nums"

    Approaches
     1. Calculate the sum of all non-empty subarrays of the given array, sort these sums in increasing order to form a new array, and then add up the sums within the specified range of the sorted array
     2. Search from the minimum to the maximum sum of a subarray to identify the sum of the first k smallest subarray sums
      a. Consider that if x is a potential sum of the first k smallest subarray sums, then y > x is not a potential sum of the first k smallest subarray sums
      b. Consider that if x is not a potential sum of the first k smallest subarray sums, then y < x is not a potential sum of the first k smallest subarray sums
      c. Consider that there may be multiple subarrays with the same sum as the kth sum of the sorted array

    Data Structures
    Algorithms
     - Binary search

    Time Complexity
     - O(n•log(sum)) -> n = size of nums, sum = maximum sum of a subarray
    Space Complexity
     - O(1)
*/

#include <bits/stdc++.h>
using namespace std;

// Solution 1

class Solution {
public:
    int rangeSum(vector<int>& nums, int n, int left, int right) {
        vector<int> arr;
        for (int i = 0; i < n; i++) {
            int sum = 0;
            for (int j = i; j < n; j++) {
                sum += nums[j];
                arr.push_back(sum);
            } 
        } 
        sort(arr.begin(), arr.end());

        const int mod = 1e9 + 7;
        int ans = 0;
        for (int i = left - 1; i < right; i++) {
            ans = (ans + arr[i]) % mod;
        }

        return ans;
    }
};

// Solution 2

class Solution {
public:
    int rangeSum(vector<int>& nums, int n, int left, int right) {
        const int mod = 1e9 + 7;
        return (sumOfFirstK(nums, n, right) - sumOfFirstK(nums, n, left - 1)) % mod;
    }
private: 
    pair<int, long long> countAndSum(vector<int>& nums, int n, int tar) {
        int cnt = 0;
        long long currentSum = 0, windowSum = 0, totalSum = 0;
        
        int l = 0;
        for (int r = 0; r < n; r++) {
            currentSum += nums[r];
            windowSum += nums[r] * (r - l + 1);
            while (currentSum > tar) {
                windowSum -= currentSum;
                currentSum -= nums[l];
                l++;
            }
            cnt += r - l + 1;
            totalSum += windowSum;
        }

        return {cnt, totalSum};
    }
    long long sumOfFirstK(vector<int>& nums, int n, int k) {
        int mnSum = *min_element(nums.begin(), nums.end());
        int mxSum = accumulate(nums.begin(), nums.end(), 0);
        int lo = mnSum;
        int hi = mxSum;

        while (lo <= hi) {
            int mid = lo + (hi - lo) / 2;

            if (countAndSum(nums, n, mid).first >= k) {
                hi = mid - 1;
            }
            else {
                lo = mid + 1;
            }
        }
        
        auto [cnt, sum] = countAndSum(nums, n, lo);
        return sum - lo * (cnt - k);
    }
};