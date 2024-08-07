/* 
    Problem
     - Find the shortest path from city 0 to city n - 1 each time a new unidirectional road is added, given that initially, there is a unidirectional road from city i to city i + 1 for all city 0 <= i < n - 1

    Approaches
     1. Add the first edge from "queries" to the graph, determine the shortest unweighted path from city 0 to city n - 1, and then repeat with the next edge until no edges remain in "queries"

    Data Structures
     - Graph
    Algorithms
     - Breadth-first search

    Time Complexity
     - O(q•(v•e)) -> q = size of queries
    Space Complexity
     - O(q+v+e)
*/

#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    vector<int> shortestDistanceAfterQueries(int n, vector<vector<int>>& queries) {
        vector<vector<int>> g(n);
        for (int i = 1; i < n; i++) {
            g[i - 1].push_back(i);
        }

        vector<int> ans(queries.size());
        for (int i = 0; i < queries.size(); i++) {
            g[queries[i][0]].push_back(queries[i][1]);
            ans[i] = bfs(g);
        }

        return ans;
    }
private: 
    int bfs(vector<vector<int>>& g) {
        int n = g.size();
        int dist = 0;

        vector<bool> visited(n);
        queue<int> q;

        visited[0] = true;
        q.push(0);

        while(!q.empty()) {
            int size = q.size();
            dist++;

            for (int j = 0; j < size; j++) {
                int v = q.front();
                q.pop();

                for (int nbr : g[v]) {
                    if (nbr == n - 1) {
                        return dist;
                    }
                    if (!visited[nbr]) {
                        visited[nbr] = true;
                        q.push(nbr);
                    }
                }
            }
        }

        return -1;
    }
};