/* 
    Problem
     - https://leetcode.com/problems/zero-array-transformation-i/description/

    Patterns
     - Line Sweep
*/

#include <bits/stdc++.h>
using namespace std;

// Solution 1: Line Sweep

// Time Complexity: O(q + n)
// Space Complexity: O(n)

class Solution {
public:
    bool isZeroArray(vector<int>& nums, vector<vector<int>>& queries) {
        int n = nums.size();
        vector<int> line(n);

        for (auto& q : queries) {
            line[q[0]]++;
            if (q[1] + 1 < n) {
                line[q[1] + 1]--;
            }
        }

        int cnt = 0;
        for (int i = 0; i < n; i++) {
            cnt += line[i];
            if (nums[i] > cnt) {
                return false;
            }
        }

        return true;
    }
};
