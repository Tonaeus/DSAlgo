/* 
    Problem
     - Find the number of students who are not in their correct positions, given that the students are asked to stand in a single file line in increasing order by height

    Approaches
     1. Count the number of position in the original array that is different from the sorted array

    Data Structures
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