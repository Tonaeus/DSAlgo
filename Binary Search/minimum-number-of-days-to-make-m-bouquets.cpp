/* 
    Approaches
     1. Find a day on which the number of required bouquets can be created, and then try to find an earlier day where the same can be achieved
      a. Consider that the number of bouquets that can be created increases strictly with each passing day

    Data Structures
    Algorithms
     - Binary search

    Time Complexity
     - O(n•log(d)) -> n = number of flowers, d = days between latest and earliest bloom
    Space Complexity
     - O(1)
*/

#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int minDays(vector<int>& bloomDay, int m, int k) {
        int ans = -1;
        auto [low_it, high_it] = minmax_element(bloomDay.begin(), bloomDay.end());
        int low = *low_it, high = *high_it;

        while (low <= high) {
            int mid = low + (high - low) / 2;

            if (helper(bloomDay, k, mid) >= m) {
                high = mid - 1;
                ans = mid;
            }
            else {
                low = mid + 1;
            }
        }

        return ans; 
    }
private:
    int helper(vector<int>& bloomDay, int k, int d) {
        int ans = 0;

        int count = 0;
        for (int i = 0; i < bloomDay.size(); i++) {
            if (bloomDay[i] <= d) {
                count++;
            }
            else {
                count = 0;
            }

            if (count == k) {
                ans++;
                count = 0;
            }
        }

        return ans;
    }
};