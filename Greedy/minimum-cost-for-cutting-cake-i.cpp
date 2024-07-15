/* 
    Problem
     - Find the minimum total cost to cut the entire cake into 1 x 1 pieces

    Approaches
     1. Perform the cuts from greatest to least cost to minimize the total cost
      a. Consider that earlier cuts are performed fewer times than later cuts

    Data Structures
    Algorithms

    Time Complexity
     - O(m•log(m)+n•log(n))
    Space Complexity
     - O(1)
*/

#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int minimumCost(int m, int n, vector<int>& horizontalCut, vector<int>& verticalCut) {
        sort(horizontalCut.begin(), horizontalCut.end());
        sort(verticalCut.begin(), verticalCut.end());
        int h_pieces = 1, v_pieces = 1;
        int ans = 0;
        while (!horizontalCut.empty() || !verticalCut.empty()) {
            if (verticalCut.empty()) {
                ans += v_pieces * horizontalCut.back();
                horizontalCut.pop_back();
                h_pieces++;
            }
            else if (horizontalCut.empty()) {
                ans += h_pieces * verticalCut.back();
                verticalCut.pop_back();
                v_pieces++;
            }
            else if (horizontalCut.back() > verticalCut.back()) {
                ans += v_pieces * horizontalCut.back();
                horizontalCut.pop_back();
                h_pieces++;
            }
            else {
                ans += h_pieces * verticalCut.back();
                verticalCut.pop_back();
                v_pieces++;
            }
        }
        return ans;
    }
};
