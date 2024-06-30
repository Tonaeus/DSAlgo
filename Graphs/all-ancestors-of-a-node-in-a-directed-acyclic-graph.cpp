/* 
    Approaches
     1. Add each node as the ancestor to all of its descendant arrays and then sort those arrays
      a. Consider that nodes are added to the descendant array in ascending order

    Data Structures
    Algorithms
     - Depth-first search

    Time Complexity
     - O(n•(n+e))
    Space Complexity
     - O(n^2)
*/

#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    vector<vector<int>> getAncestors(int n, vector<vector<int>>& edges) {
        vector<vector<int>> ans(n);
        vector<vector<int>> g(n);

        for (auto e : edges) {
            g[e[0]].push_back(e[1]);
        }

        for (int i = 0; i < n; i++) {
            vector<bool> visited(n, false);
            dfs(ans, g, visited, i, i);
        }
        
        return ans;
    }
private:
    void dfs(vector<vector<int>>& ans, vector<vector<int>>& g, vector<bool>& visited, int anc, int curr) {
        visited[curr] = true;
        for (int chd : g[curr]) {
            if (!visited[chd]) {
                ans[chd].push_back(anc);
                dfs(ans, g, visited, anc, chd);
            }
        }
        return;
    }
};