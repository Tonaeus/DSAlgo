/* 
    Approaches
     1. Iterate from 1 to the greatest distance possible between m balls until the total distance between the balls exceed the maximum position
      a. Consider that if x is a potential distance, then y < x is not a potential distance
      b. Consider that if x is not a potential distance, then y > x is not a potential distance

    Data Structures
    Algorithms
     - Binary search

    Time Complexity
     - O(n•log(k•n/m)) -> n = number of positions, k = maximum position, m = number of balls
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
    bool helper(vector<int>& position, int m, int f) {
        int countBalls = 1;
        int prevPos = position.front();

        for (int i = 1; i < position.size() && countBalls < m; i++) {
            int currPos = position[i];
            if (currPos - prevPos >= f) {
                countBalls++;
                prevPos = currPos;
            }
        }

        return countBalls == m;
    }
};