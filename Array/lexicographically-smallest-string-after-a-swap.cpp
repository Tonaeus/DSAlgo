/* 
    Problem
     - Find the smallest integer, given a one-time operation to swap adjacent digits with the same parity

    Approaches
     1. Swap the current and previous digits if the current digit is less than the previous one and both have the same parity

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
    string getSmallestString(string s) {
        for (int i = 1; i < s.length(); i++) {
            if (s[i] % 2 == s[i - 1] % 2 && s[i] < s[i - 1]) {
                swap(s[i], s[i - 1]);
                break;
            }
        }
        return s;
    }
};