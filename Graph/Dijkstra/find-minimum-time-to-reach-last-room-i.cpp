/* 
    Problem
     - https://leetcode.com/problems/find-minimum-time-to-reach-last-room-i/description/

    Patterns
     - Dijkstra's Algorithm
*/

#include <bits/stdc++.h>
using namespace std;

// Solution 1: Dijkstra's Algorithm

// Time Complexity: O(m•n•log(m•n))
// Space Complexity: O(m•n)

class Solution {
public:
    int minTimeToReach(vector<vector<int>>& moveTime) {
        int m = moveTime.size();
        int n = moveTime[0].size();

        vector<vector<int>> time(m, vector<int>(n, INT_MAX));
        time[0][0] = 0;

        using tiii = tuple<int, int, int>;
        priority_queue<tiii, vector<tiii>, greater<tiii>> pq;
        pq.emplace(0, 0, 0);

        vector<vector<int>> directions = {{0, 1}, {1, 0}, {0, -1}, {-1, 0}};
        while (!pq.empty()) {
            auto [t, i, j] = pq.top();
            pq.pop();

            if (i == m - 1 and j == n - 1) {
                return t;
            }

            if (t != time[i][j]) {
                continue;
            }

            for (auto& d : directions) {
                int ni = i + d[0];
                int nj = j + d[1];

                if (outOfBound(ni, nj, m, n)) {
                    continue;
                }

                int nt = max(t, moveTime[ni][nj]) + 1;

                if (nt < time[ni][nj]) {
                    time[ni][nj] = nt;
                    pq.emplace(nt, ni, nj);
                }
            }
        }

        return -1; 
    }

private: 
    bool outOfBound(int i, int j, int m, int n) {
        return i < 0 or i >= m or j < 0 or j >= n;
    }
};
