/* 
    Approaches
     1. Join two nodes together at a time, and if the two nodes create a cycle, return the edge that joins the two nodes

    Data Structures
     - Disjoint-set
    Algorithms

    Time Complexity
     - O(n)
    Space Complexity
     - O(n)
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