/* 
    Problem
     - https://leetcode.com/problems/network-delay-time/description/

    Patterns
     - Dijkstra Algorithm 
*/

#include <bits/stdc++.h>
using namespace std;

// Solution 1: Dijkstra's Algorithm

// Time Complexity: O((v + e)log(v))
// Space Complexity: O(v + e)

class Solution {
public:
    int networkDelayTime(vector<vector<int>>& times, int n, int k) {
        using pii = pair<int, int>;
        
        vector<vector<pii>> adj(n + 1);
        for (auto& v : times) {
            adj[v[0]].push_back({v[1], v[2]});
        }

        vector<int> dist(n + 1, INT_MAX);
        dist[k] = 0;

        priority_queue<pii, vector<pii>, greater<pii>> mxh;
        mxh.push({0, k});

        while (!mxh.empty()) {
            int fm = mxh.top().second;
            int d = mxh.top().first;
            mxh.pop();

            if (d != dist[fm]) {
                continue;
            }

            for (auto& nbr : adj[fm]) {
                int to = nbr.first;
                int d = nbr.second;

                if (dist[fm] + d < dist[to]) {
                    dist[to] = dist[fm] + d;
                    mxh.push({dist[to], to});
                }
            }
        }

        int ans = *max_element(dist.begin() + 1, dist.end());
        return ans == INT_MAX ? -1 : ans;
    }
};
