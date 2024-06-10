/* 
    Approaches
     1. Remove the most recent added letter when a digit is encountered 

    Data Structures
     - String
    Algorithms

    Time Complexity
     - O(n)
    Space Complexity
     - O(n)
*/

#include <bits/stdc++.h>
using namespace std;

class Solution_1 {
public:
    string clearDigits(string s) {
        string ans = "";
        for (auto c: s) {
            if (isdigit(c)) {
                ans.pop_back();
            }
            else {
                ans.push_back(c);
            }
        }
        return ans;
    }
};
