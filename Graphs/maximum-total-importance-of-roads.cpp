/* 
    Approaches
     1. Find the degree of each node and multiply each degree, from smallest to largest, by the numbers 1 to n

    Data Structures
     - Graph
    Algorithms

    Time Complexity
     - O(n•log(n))
    Space Complexity
     - O(n)
*/

#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    long long maximumImportance(int n, vector<vector<int>>& roads) {
        long long ans = 0;
        vector<int> deg(n);

        for (auto& road : roads) {
            deg[road[0]]++;
            deg[road[1]]++;
        }

        sort(deg.begin(), deg.end());

        for (int i = 0; i < n; i++) {
            ans += (long long) deg[i] * (i + 1);
        }

        return ans;
    }
};