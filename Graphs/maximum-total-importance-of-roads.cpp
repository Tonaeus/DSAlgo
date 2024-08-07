/* 
    Problem
     - Find the maximum total importance of all roads after assigning values from 1 to n to each of n cities, where the importance of a road is defined as the sum of the values of the two cities it connects 

    Approaches
     1. Count the number of edges each city is connected to, assign values from 1 to n so that cities with more connections receive higher values, and then use these values to calculate the importance of each road and the total importance

    Data Structures
     - Graph
    Algorithms

    Time Complexity
     - O(e)
    Space Complexity
     - O(v)
*/

#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    long long maximumImportance(int n, vector<vector<int>>& roads) {
        vector<int> deg(n);
        for (auto& road : roads) {
            deg[road[0]]++;
            deg[road[1]]++;
        }

        sort(deg.begin(), deg.end());

        long long ans = 0;
        for (int i = 0; i < n; i++) {
            ans += (long long) deg[i] * (i + 1);
        }

        return ans;
    }
};