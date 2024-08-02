/* 
    Problem
     - Find the number of alternating groups, where an alternating group is a group in which each element differs from its immediate neighbours

    Approaches
     1. Count if the current element is different from the previous and next elements

    Data Structures
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
    int numberOfAlternatingGroups(vector<int>& colors) {
        int n = colors.size();
        int ans = 0;
        for (int i = 0; i < n; i++) {
            int prev = (i - 1 + n) % n;
            int next = (i + 1) % n;
            if (colors[i] != colors[prev] && colors[i] != colors[next]) {
                ans++;
            }
        }
        return ans;
    }
};