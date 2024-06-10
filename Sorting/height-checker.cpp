/* 
    Approaches
     1. Count the differences between the original and sorted array

    Data Structures
    Algorithms

    Time Complexity
     - O(n•log(n))
    Space Complexity
     - O(n)
 */

#include <bits/stdc++.h>
using namespace std;

class Solution_1 {
public:
    int heightChecker(vector<int>& heights) {
        vector<int> copy = heights;
        sort(copy.begin(), copy.end());
        
        int ans = 0;

        for (int i = 0; i < heights.size(); i++) {
            ans += heights[i] == copy[i] ? 0 : 1;
        }

        return ans;
    }
};