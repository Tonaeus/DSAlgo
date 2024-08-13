/* 
    Problem
     - Find the minimum cost to convert a source string to a target string, given arrays of character-to-character operations with associated costs for each operation

    Approaches
     1. Determine the least cost for each character pair change, then calculate the total cost to change each character in the source string to match the target string
      a. Consider that the same character pair can have different costs
    
    Data Structures
     - Graph
    Algorithms
     - Floyd-Warshall

    Time Complexity
     - O(m+n) -> m = size of an operation array, n = length of a string
    Space Complexity
     - O(1)
*/

#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    long long minimumCost(string source, string target, vector<char>& original, vector<char>& changed, vector<int>& cost) {
        vector<vector<int>> dist(26, vector<int>(26, INT_MAX));
        for (int i = 0; i < 26; i++) {
            dist[i][i] = 0;
        }
        
        for (int i = 0; i < original.size(); i++) {
            dist[original[i] - 'a'][changed[i] - 'a'] = min(dist[original[i] - 'a'][changed[i] - 'a'], (cost[i]));
        }

        for (int k = 0; k < 26; k++) {
            for (int i = 0; i < 26; i++) {
                for (int j = 0; j < 26; j++) {
                    if (dist[i][k] < INT_MAX && dist[k][j] < INT_MAX) {
                        dist[i][j] = min(dist[i][j], dist[i][k] + dist[k][j]);
                    }
                }
            }
        }

        long long ans = 0;

        for (int i = 0; i < source.length(); i++) {
            int cst = dist[source[i] - 'a'][target[i] - 'a'];
            if (cst == INT_MAX) {
                return -1;
            }
            ans += cst;
        }

        return ans;
    }
};