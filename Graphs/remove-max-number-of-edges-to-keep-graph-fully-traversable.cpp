/* 
    Problem 
     - Find the maximum number of edges that can be removed so that both Alice and Bob can still fully traverse a given graph, where the graph has edges with the type of Alice-only, Bob-only, and both

    Approaches
     1. Build a connected graph for Alice and Bob individually, count the number of edges used, and then subtract that number from the given number of edges
      a. Consider that the nodes are labeled from 1 to n and not 0 to n - 1
      b. Consider building each graph using edges that are for both Alice and Bob first

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
    DisjointSet (int n) : par(n), rank(n), cpnt(n - 1) { 
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
        
        cpnt--;
        return true; 
    }
    bool isConnected() {
        return cpnt == 1;
    }
private:
    vector<int> par, rank;
    int cpnt;
};

class Solution {
public:
    int maxNumEdgesToRemove(int n, vector<vector<int>>& edges) {
        DisjointSet alice(n + 1), bob(n + 1);
        int cnt = 0;

        for (int i = 0; i < size(edges); i++) {
            if (edges[i][0] == 3) {
                cnt += alice.doUnion(edges[i][1], edges[i][2]) && bob.doUnion(edges[i][1], edges[i][2]);
            }
        }

        for (int i = 0; i < size(edges); i++) {
            if (edges[i][0] == 1) {
                cnt += alice.doUnion(edges[i][1], edges[i][2]);
            }
            else if (edges[i][0] == 2) {
                cnt += bob.doUnion(edges[i][1], edges[i][2]);
            }
        }

        return alice.isConnected() && bob.isConnected() ? size(edges) - cnt : -1;
    }
};