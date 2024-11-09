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

        priority_queue<pii, vector<pii>, greater<pii>> mnh;
        mnh.push({0, k});

        while (!mnh.empty()) {
            int fm = mnh.top().second;
            int fd = mnh.top().first;
            mnh.pop();

            if (fd != dist[fm]) {
                continue;
            }

            for (auto& nbr : adj[fm]) {
                int to = nbr.first;
                int td = nbr.second;

                if (dist[fm] + td < dist[to]) {
                    dist[to] = dist[fm] + td;
                    mnh.push({dist[to], to});
                }
            }
        }

        int ans = *max_element(dist.begin() + 1, dist.end());
        return ans == INT_MAX ? -1 : ans;
    }
};
