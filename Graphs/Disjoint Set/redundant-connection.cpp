/* 
    Problem 
     - Find the edge that can be removed so that the graph is a tree of "n" nodes

    Approaches
     1. Build the graph by connecting 2 nodes at a time, and if a connection results in a cycle, then remove the edge in that connection

    Data Structures
     - Disjoint-set
    Algorithms

    Time Complexity
     - O(v)
    Space Complexity
     - O(v)
*/

#include <bits/stdc++.h>
using namespace std;

class DisjointSet {
public:
    DisjointSet (int n) : par(n), rank(n) {
        iota(begin(par), end(par), 0);
    }
    int doFind(int x) {
        if (x == par[x]) return x;
        return par[x] = doFind(par[x]);
    }
    bool doUnion(int x, int y) {
        int xp = doFind(x), yp = doFind(y);
        if (xp == yp) return false;
        
        if (rank[xp] > rank[yp]) {
            par[yp] = par[xp];
        }
        else if (rank[yp] > rank[xp]) {
            par[xp] = par[yp];
        }
        else {
            par[xp] = yp, rank[yp]++;
        }

        return true; 
    }
private:
    vector<int> par, rank;
};

class Solution {
public:
    vector<int> findRedundantConnection(vector<vector<int>>& edges) {
        DisjointSet ds(size(edges) + 1);
        for (auto& e : edges) {
            if (!ds.doUnion(e[0], e[1])) {
                return e;
            }
        }
        return {};
    }
};