/* 
    Problem
     - https://leetcode.com/problems/longest-palindromic-substring/description/

    Patterns
     - Manacher's Algorithm
*/

#include <bits/stdc++.h>
using namespace std;

// Solution 1: Manacher's Algorithm

// Time Complexity: O(n)
// Space Complexity: O(n)

class Solution {
public:
    string longestPalindrome(string s) {
        string t = "#";
        for (char c: s) {
            t += string(1, c) + "#";
        }

        int n = t.size();
        t = "$" + t + "^";

        vector<int> p(n + 2);
        int l = 1; 
        int r = 1;

        int center = 0;   
        int radius = 0;   

        for (int i = 1; i <= n; i++) {
            p[i] = max(0, min((r - i), p[l + (r - i)]));
            while (t[i - p[i]] == t[i + p[i]]) {
                p[i]++;
            }
            if (i + p[i] > r) {
                l = i - p[i];
                r = i + p[i];
            }
            if (p[i] > radius) {
                center = i;
                radius = p[i];
            }
        }

        int start = (center - radius) / 2; 
        return s.substr(start, radius - 1);  
    }
};
