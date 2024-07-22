/* 
    Problem
     - Find the order of people’s names based on their heights

    Approaches
     1. Combine the names and heights, then sort them by height

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
    vector<string> sortPeople(vector<string>& names, vector<int>& heights) {
        vector<pair<int, string>> peoples;
        for (int i = 0; i < names.size(); i++) {
            peoples.push_back({heights[i], names[i]});
        }

        sort(peoples.begin(), peoples.end(), greater<>());

        vector<string> ans;
        for (const auto& p : peoples) {
            ans.push_back(p.second);
        }

        return ans;
    }
};