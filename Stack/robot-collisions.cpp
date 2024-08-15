/* 
    Problem
     - Find the health of the robots, given that all robots will start to move simultaneously at the same speed, either left or right

    Approaches
     1. Compare the current robot to the previous robot if the current robot is moving against the direction of the previous robot

    Data Structures
     - Hash map
     - Stack
    Algorithms

    Time Complexity
     - O(n•log(n))
    Space Complexity
     - O(n)
*/

#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    vector<int> survivedRobotsHealths(vector<int>& positions, vector<int>& healths, string directions) {
        unordered_map<int, int> mp;
        for (int i = 0; i < positions.size(); i++) {
            mp[positions[i]] = i;
        }
        sort(positions.begin(), positions.end());
        stack<int> stk;
        for (int pos : positions) {
            int i = mp[pos];
            if (directions[i] == 'R') {
                stk.push(i);
                continue;
            }
            while (!stk.empty() && directions[stk.top()] == 'R' && healths[i] != 0) {
                int j = stk.top();
                stk.pop();
                if (healths[i] > healths[j]) {
                    healths[j] = 0;
                    healths[i]--;
                }
                else if (healths[j] > healths[i]) {
                    healths[i] = 0;
                    healths[j]--;
                    stk.push(j);
                }
                else {
                    healths[i] = healths[j] = 0;
                }
            }
            if (healths[i] != 0) {
                stk.push(i);
            }
        }
        vector<int> ans;
        for (int i = 0; i < healths.size(); i++) {
            if (healths[i] > 0) {
                ans.push_back(healths[i]);
            }
        }
        return ans;
    }
};