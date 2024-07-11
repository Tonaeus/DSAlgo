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
        for (int i = 1; i < n + 1; i++) {
            if (colors[i % n] != colors[(i - 1) % n] && colors[i % n] != colors[(i + 1) % n]) {
                ans++;
            }
        }
        return ans;
    }
};

