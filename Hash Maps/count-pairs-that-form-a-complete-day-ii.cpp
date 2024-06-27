/* 
    Approaches
     1. Count how many times the complementary hour of the current hour appears

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


