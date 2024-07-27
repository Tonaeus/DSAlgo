/* 
    Problem
     - Find the city with the smallest number of other cities that are reachable within a given distance

    Approaches
     1. Determine the shortest path between all city pairs, and then count the number of cities reachable within the given distance for each city

    Data Structures
     - Graph
    Algorithms
     - Floyd-Warshall

    Time Complexity
     - O(v^3)
    Space Complexity
     - O(v^2)
*/

#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int findTheCity(int n, vector<vector<int>>& edges, int distanceThreshold) {
        vector<vector<int>> dist(n, vector<int>(n, INT_MAX));
        for (int i = 0; i < n; i++) {
            dist[i][i] = 0;
        }

        for (const auto& e : edges) {
            dist[e[0]][e[1]] = e[2];
            dist[e[1]][e[0]] = e[2];
        }

        for (int k = 0; k < n; k++) {
            for (int i = 0; i < n; i++) {
                for (int j = 0; j < n; j++) {
                    if (dist[i][k] < INT_MAX && dist[k][j] < INT_MAX) {
                        dist[i][j] = min(dist[i][j], dist[i][k] + dist[k][j]);
                    }
                }
            }
        }

        int ans = -1; 
        int minCnt = n;

        for (int i = 0; i < n; i++) {
            int srcCnt = 0;
            for (int j = 0; j < n; j++) {
                if (dist[i][j] <= distanceThreshold) {
                    srcCnt++;
                }
            }

            if (srcCnt <= minCnt) {
                minCnt = srcCnt;
                ans = i;
            }
        }

        return ans;
    }
};