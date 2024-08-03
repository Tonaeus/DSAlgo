/* 
    Problem
     - Find the number of index pairs (i, j) in an integer array "hours", where i < j and the sum of hours[i] and hours[j] equals a complete day

    Approaches
     1. Count if the current hour is a complement to a previous hour
      a. Consider that the current hour may be a complement to multiple previous hours

    Data Structures
     - Hash map
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
    long long countCompleteDayPairs(vector<int>& hours) {
        vector<int> mp(24, 0);
        long long ans = 0;

        for (int i = 0; i < hours.size(); i++) {
            int tmp = hours[i] % 24; 
            if (mp[(24 - tmp) % 24] != 0) {
                ans += mp[(24 - tmp) % 24];
            }
            mp[tmp]++;
        }

        return ans;
    }
};