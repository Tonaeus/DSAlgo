/* 
    Problem
     - Find the second minimum time to travel from node 1 to node "n"

    Approaches
     1. Determine the second path that reaches the destination and takes a different amount of time than the first path that reaches the destination
      a. Consider that the amount of time it takes to travel from one level to the next is the same
      c. Consider that the second path is at most 2 levels away
      b. Consider allowing each node to be visited twice

    Data Structures
     - Graph
    Algorithms
     - Breadth-first search

    Time Complexity
     - O(v+e)
    Space Complexity
     - O(v+e)
*/

#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int secondMinimum(int n, vector<vector<int>>& edges, int time, int change) {
        vector<vector<int>> g(n + 1);
        for (const auto& e : edges) {
            g[e[0]].push_back(e[1]);
            g[e[1]].push_back(e[0]);
        }

        queue<pair<int,int>> q;
        vector<int> time1(n + 1, -1), time2(n + 1, -1);
        q.push({1, 1});
        time1[1] = 0;

        while (!q.empty()) {
            auto [v, cnt] = q.front();
            q.pop();

            int currTime = cnt == 1 ? time1[v] : time2[v];
            int nextTime = currTime;
            nextTime += (currTime / change) % 2 == 1 ? change - (currTime % change) : 0; 
            nextTime += time;

            for (int nbr : g[v]) {
                if (time1[nbr] == -1) {
                    time1[nbr] = nextTime;
                    q.push({nbr, 1});
                }
                else if (time2[nbr] == -1 && time1[nbr] != nextTime) {
                    if (nbr == n) {
                        return nextTime;
                    }
                    time2[nbr] = nextTime;
                    q.push({nbr, 2});
                }
            }
        }

        return -1;
    }
};