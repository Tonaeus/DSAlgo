/* 
    Problem 
     - Remove all digits, given the operation to delete the first digit and the closest non-digit character to its left

    Approaches
     1. Remove the most recent added letter when the current character is a digit

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

class Solution {
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
