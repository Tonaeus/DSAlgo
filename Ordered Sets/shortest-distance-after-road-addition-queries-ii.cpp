/* 
    Problem
     - Find the shortest path from city 0 to city n - 1 each time a new unidirectional road is added, where the destination city of added roads is not between the source and destination cities of other added roads, given that initially, there is a unidirectional road from city i to city i + 1 for all cities 0 <= i < n - 1

    Approaches
     1. Add the first road from "queries" to the graph, remove all cities between the source and destination cities of the newly added road, determine the shortest unweighted path from city 0 to city n - 1, and then repeat with the next road until no roads remain in "queries"
      a. Consider that the shortest unweighted path is equal to the number of unremoved cities minus 1

    Data Structures
     - Graph
     - Ordered set
    Algorithms

    Time Complexity
     - O(v•log(v)+q•log(v))
    Space Complexity
     - O(v)
*/

#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    vector<int> shortestDistanceAfterQueries(int n, vector<vector<int>>& queries) {
        set<int> set;
        for (int i = 0; i < n; i++) {
            set.insert(i);
        }
        
        vector<int> ans(queries.size());
        for (int i = 0; i < queries.size(); i++) {
            helper(set, queries[i][0], queries[i][1]);
            ans[i] = set.size() - 1;
        }

        return ans;
    }

private: 
    void helper(set<int>& set, int src, int dest) {
        auto l = set.lower_bound(src + 1); 
        auto r = set.upper_bound(dest - 1); 
        set.erase(l, r);
    }
};