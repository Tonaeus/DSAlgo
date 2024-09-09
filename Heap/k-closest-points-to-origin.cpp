/* 
    Problem 
     - Find the k closest points to the origin based on Euclidean distance, given an array of points

    Approaches
     1. Calculate the Euclidean distance between the origin and each point, sort all of the distances in ascending order, and select the first k points
     2. Calculate the Euclidean distance between the origin and each point, and select the distance and deselect the kth largest distance only if the distance is less than the kth largest distance

    Data Structures
     - Heap
    Algorithms

    Time Complexity
     - O(n•log(k))
    Space Complexity
     - O(n)
*/

#include <bits/stdc++.h>
using namespace std;

// Solution 1

class Solution {
public:
    vector<vector<int>> kClosest(vector<vector<int>>& points, int k) {
        priority_queue<pair<double, pair<int, int>>, vector<pair<double, pair<int, int>>>, greater<>> mnh;
        vector<vector<int>> ans(k);

        for (const auto& point : points) {
            double x = point[0];
            double y = point[1];
            double d = sqrt(pow(x, 2) + pow(y, 2));
            mnh.push({d, {x, y}});
        }

        for (int i = 0; i < k; i++) {
            pair<double, pair<int, int>> point = mnh.top();
            mnh.pop();
            int x = point.second.first;
            int y = point.second.second;
            ans[i] = {x, y};
        }

        return ans;
    }
};

// Solution 2

class Solution {
public:
    vector<vector<int>> kClosest(vector<vector<int>>& points, int k) {
        priority_queue<pair<double, pair<int, int>>> mxh;
        vector<vector<int>> ans(k);

        for (const auto& point : points) {
            double x = point[0];
            double y = point[1];
            double d = sqrt(pow(x, 2) + pow(y, 2));
            
            if (mxh.size() < k) {
                mxh.push({d, {x, y}});
            }
            else if (d < mxh.top().first) {
                mxh.pop();
                mxh.push({d, {x, y}});
            }
        }

        for (int i = 0; i < k; i++) {
            pair<double, pair<int, int>> point = mxh.top();
            mxh.pop();
            int x = point.second.first;
            int y = point.second.second;
            ans[i] = {x, y};
        }

        return ans;
    }
};
