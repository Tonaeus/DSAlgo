/* 
    Problem
     - Shift the string to the right by k steps

    Approaches
     1. Find where the k steps end, start the encrypted string at that position, and wrap around the remaining parts

    Data Structures
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
    string getEncryptedString(string s, int k) {
        k %= s.length();
        return s.substr(k, s.length() - k) + s.substr(0, k);
    }
};