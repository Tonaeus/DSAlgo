/* 
    Problem
     - Find the matrix using numbers from 1 to k exactly once, given conditions where each pair of numbers should either be above and below or to the left and right of each other
    
    Approaches
     1. Determine the order of elements that satisfy both the row and column conditions, and then place the numbers from 1 to k in the corresponding positions in the matrix
      a. Consider that each row and each column will have only one element that is not a "0"
      b. Consider that there can be no solution if there is a contradiction in the conditions

    Data Structures
     - Graph
    Algorithms
     - Depth-first search
     - Topological sort

    Time Complexity
     - O(k^2)
    Space Complexity
     - O(k^2)
*/

#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    vector<vector<int>> buildMatrix(int k, vector<vector<int>>& rowConditions, vector<vector<int>>& colConditions) {
        unordered_map<int, vector<int>> g;
        for (const auto& e: rowConditions) {
            g[e[0]].push_back(e[1]);
        }
        vector<int> rowOrder = topoSort(g, k);

        g.clear();
        for (const auto& e: colConditions) {
            g[e[0]].push_back(e[1]);
        }
        vector<int> colOrder = topoSort(g, k);

        if (rowOrder.empty() || colOrder.empty()) return {};

        unordered_map<int, pair<int, int>> mp;
        for (int i = 0; i < k; i++) {
            mp[rowOrder[i]].first = i;
            mp[colOrder[i]].second = i;
        }

        vector<vector<int>> ans(k, vector<int>(k, 0));
        for (int i = 1; i <= k; i++) {
            int row = mp[i].first;
            int col = mp[i].second;
            ans[row][col] = i;
        }

        return ans;
    }
private: 
    bool dfs(int src, unordered_map<int, vector<int>>& g, unordered_set<int>& visited, unordered_set<int>& path, vector<int>& res) {
        if (path.contains(src)) return false;
        if (visited.contains(src)) return true;
        
        path.insert(src);
        visited.insert(src);

        for (int nbr : g[src]) {
            if (!dfs(nbr, g, visited, path, res)) {
                return false;
            }
        }

        path.erase(src);
        res.push_back(src);
        return true; 
    }
    vector<int> topoSort(unordered_map<int, vector<int>>& g, int k) {
        vector<int> res;
        unordered_set<int> visited;
        unordered_set<int> path; 

        for (int i = 1; i <= k; i++) {
            if (!dfs(i, g, visited, path, res)) {
                return {};
            }
        }

        reverse(res.begin(), res.end());
        return res;
    }
};