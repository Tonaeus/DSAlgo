/* 
    Approaches
     1. Flip current bit and next 2 bits if it is 0
     2. Flip current bit if it is 0
      a. Consider that (bit + window flips) % 2 = actual bit

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

// Solution 1

class Solution {
public:
    int minOperations(vector<int>& nums) {
        int ans = 0;
        queue<int> q;
        for (int i = 0; i < nums.size(); i++) {
            if (!q.empty() && i - 3 + 1 > q.front()) {
                q.pop();
            }
            if ((nums[i] + q.size()) % 2 == 0) {
                if (i + 3 > nums.size()) {
                    return -1;
                }
                ans++;
                q.push(i);
            }
        }
        return ans;
    }
};

// Solution 2

class Solution {
public:
    int minOperations(vector<int>& nums) {
        int ans = 0;
        int windowFlips = 0;
        for (int i = 0; i < nums.size(); i++) {
            if (i > 3 - 1 && nums[i - 3] == 2) {
                windowFlips--;
            }
            if ((nums[i] + windowFlips) % 2 == 0) {
                if (i + 3 > nums.size()) {
                    return -1;
                }
                nums[i] = 2;
                windowFlips++;
                ans++;
            }
        }
        return ans;
    }
};