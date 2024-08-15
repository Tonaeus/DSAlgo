/* 
    Problem
     - Find the number of passengers who are strictly more than 60 years old, given information about each passenger in a compressed string

    Approaches
     1. Extract each passenger's age from their information string and count them if their age is greater than 60

    Data Structures
     - String
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
    int countSeniors(vector<string>& details) {
        int ans = 0;
        for (const auto& d : details) {
            int age = (d[11] - '0') * 10 + (d[12] - '0');
            if (age > 60) {
                ans++;
            }
        }
        return ans;
    }
};