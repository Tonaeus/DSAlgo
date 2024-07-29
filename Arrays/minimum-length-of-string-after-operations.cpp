/* 
    Problem
     - Find the minimum length of a string, given the operation to delete both the closest matching characters on the left and right of a character

    Approaches
     1. Count the frequency of each character, and then reduce the frequency of each character to 1 or 2
      a. Consider that an operation can be performed if there are at least 3 of the same character

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
    int minimumLength(string s) {
        vector<int> freq(26);
        for (const char c : s) {
            freq[c - 'a']++;
        } 
        for (int i = 0; i < 26; i++) {
            if (freq[i]) {
                freq[i] = freq[i] % 2 == 1 ? 1 : 2;  
            }
        }
        return accumulate(freq.begin(), freq.end(), 0);
    }
};