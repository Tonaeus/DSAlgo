/* 
    Problem
     - Find the number of good nodes in a given tree, where a node is good if all of its subtrees have the same size

    Approaches
     1. Count if the size of each subtree of the current node is the same
      a. Consider that a tree with n nodes has exactly n - 1 edges
      b. Consider that a leaf node is a good node

    Data Structures
     - Tree
    Algorithms
     - Depth-first search

    Time Complexity
     - O(n)
    Space Complexity
     - O(n)
*/

#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int countGoodNodes(vector<vector<int>>& edges) {
        vector<vector<int>> g(edges.size() + 1);
        for (auto e : edges) {
            g[e[0]].push_back(e[1]);
            g[e[1]].push_back(e[0]);
        }

        int ans = 0;
        dfs(g, ans, 0, -1);

        return ans;
    }

private:
    int dfs(vector<vector<int>>& g, int& ans, int v, int p) {        
        int cnt = 0;
        int prevCnt = -1;
        int flag = true;

        for (int nbr : g[v]) {
            if (nbr != p) {
                int currCnt = dfs(g, ans, nbr, v);
                cnt += currCnt; 
                
                if (prevCnt == -1) {
                    prevCnt = currCnt;
                }
                else if (prevCnt != currCnt) {
                    flag = false;
                }
            }
        }

        if (cnt == 0 || flag) {
            ans++;
        }

        return cnt + 1;
    }
};