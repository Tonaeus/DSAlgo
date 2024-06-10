/* 
    Approaches
     1. Find the node with a degree of n - 1
     2. Find the node with a degree of > 1 

    Data Structures
     - Graph
    Algorithms

    Time Complexity
     - O(n)
    Space Complexity
     - O(n)
*/

#include <bits/stdc++.h>
using namespace std;

class Solution_1 {
public:
    int findCenter(vector<vector<int>>& edges) {
        unordered_map<int, int> mp;
        int v = -1;

        for (int i = 0; i < edges.size(); i++) {
            mp[edges[i][0]]++;
            mp[edges[i][1]]++;
        }

        for (auto& it: mp) {
            if (it.second == edges.size()) {
                return it.first;
            } 
        }

        return 0; 
    }
};

class Solution_2 {
public:
    int findCenter(vector<vector<int>>& edges) {
        set<int> visted;

        for (auto e: edges) {
            if (visted.find(e[0]) != visted.end()) 
                return e[0];
            if (visted.find(e[1]) != visted.end()) 
                return e[1];

            visted.insert(e[0]);
            visted.insert(e[1]);
        }

        return 0;
    }
};