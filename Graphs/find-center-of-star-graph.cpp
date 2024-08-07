/* 
    Problem
     - Find the node that is connected to all other nodes, given an array of edges

    Approaches
     1. Identify the node with a degree of n - 1
     2. Identify the node with more than 1 edge

    Data Structures
     - Graph
    Algorithms

    Time Complexity
     - O(1)
    Space Complexity
     - O(1)
*/

#include <bits/stdc++.h>
using namespace std;

// Solution 1

class Solution {
public:
    int findCenter(vector<vector<int>>& edges) {
        unordered_map<int, int> mp;

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

// Solution 2

class Solution {
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

// Solution 2.1

class Solution {
public:
    int findCenter(vector<vector<int>>& edges) {
        if (edges[0][0] == edges[1][0] || edges[0][0] == edges[1][1]) {
            return edges[0][0]; 
        } 
        else {
            return edges[0][1]; 
        }
    }
};