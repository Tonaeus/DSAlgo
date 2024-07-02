/* 
    Approaches
     1. Count the frequency of each character in both strings and check if they are the same

    Data Structures
     - Array
    Algorithms

    Time Complexity
     - O(max(n, m)) -> n = length of s, m = length of t
    Space Complexity
     - O(1)
*/

#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    bool isAnagram(string s, string t) {
        vector<int> sFreq(26);
        vector<int> tFreq(26);

        for (int i = 0; i < s.length() && i < t.length(); i++) {
            sFreq[s[i]-'a']++;
            tFreq[t[i]-'a']++;
        }

        return s.length() == t.length() && sFreq == tFreq;
    }
};