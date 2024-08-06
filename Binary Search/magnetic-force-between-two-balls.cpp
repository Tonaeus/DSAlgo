/* 
    Problem 
     - Find the minimum distance between any two balls such that the total distance between all balls is maximized, given the positions of the baskets where the balls are to be placed

    Approaches
     1. Search from 1 to the equal distance between "m" balls to identify the minimum distance between any two balls 
      a. Consider that if x is a potential distance, then y < x is not a potential distance
      b. Consider that if x is not a potential distance, then y > x is not a potential distance

    Data Structures
    Algorithms
     - Binary search

    Time Complexity
     - O(n•log(n)+n•log(k/m)) -> n = number of positions, k = maximum position, m = number of balls
    Space Complexity
     - O(log(n))
*/

#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int maxDistance(vector<int>& position, int m) {
        sort(position.begin(), position.end());
        int ans = 0;
        int lo = 1;
        int hi = (position.back() - position.front()) / (m - 1);
        while (lo <= hi) {
            int mid = lo + (hi - lo) / 2;
            
            if (helper(position, m, mid)) {
                ans = mid;
                lo = mid + 1;
            } 
            else {
                hi = mid - 1;
            }
        }

        return ans;
    }
private: 
    bool helper(vector<int>& position, int m, int dist) {
        int cnt = 1;
        int prevPos = position.front();

        for (int i = 1; i < position.size() && cnt < m; i++) {
            int currPos = position[i];
            if (currPos - prevPos >= dist) {
                cnt++;
                prevPos = currPos;
            }
        }

        return cnt == m;
    }
};