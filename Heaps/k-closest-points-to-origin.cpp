/* 
    Approaches
     1. Sort the magnitude of the points in ascending order and get the first k points
      a. Consider that the magnitude is a real number

    Data Structures
     - Heap
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
    vector<vector<int>> kClosest(vector<vector<int>>& points, int k) {
        priority_queue<pair<double, pair<int, int>>, vector<pair<double, pair<int, int>>>, greater<>> pq;
        vector<vector<int>> ans;

        for (int i = 0; i < points.size(); i++) {
            double x = points[i][0];
            double y = points[i][1];
            double d = sqrt(pow(x, 2) + pow(y, 2));
            pq.push({d, {x, y}});
        }

        for (int i = 0; i < k; i++) {
            pair<double, pair<int, int>> point = pq.top();
            pq.pop();
            int x = point.second.first;
            int y = point.second.second;
            ans.push_back({x, y});
        }

        return ans;
    }
};