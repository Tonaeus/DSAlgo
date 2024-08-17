/* 
    Problem
     - Find the maximum distance between any 2 integers from different arrays, given an array of sorted arrays, where the distance between two integers a and b is defined as their absolute difference 

    Approaches
     1. Calculate the difference between the global largest integer and the current smallest integer, and the difference between the current largest integer and the global smallest integer, then compare these two differences to the global maximum difference
      a. Consider that the maximum difference is between an integer at the back of an array and an integer at the front an array
      b. Consider that the smallest and largest integers may be in the same array
      
    Data Structures
     - Array
    Algorithms

    Time Complexity
     - O(n)
    Space Complexity
     - O(1)
*/

#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int maxDistance(vector<vector<int>>& arrays) {
        int mn = arrays[0].front();
        int mx = arrays[0].back();;
        int mxDist = 0;

        for (int i = 1; i < arrays.size(); i++) {
            mxDist = max(mxDist, mx - arrays[i].front());
            mxDist = max(mxDist, arrays[i].back() - mn);
  
            mn = min(mn, arrays[i].front());
            mx = max(mx, arrays[i].back());
        }

        return mxDist;
    }
};