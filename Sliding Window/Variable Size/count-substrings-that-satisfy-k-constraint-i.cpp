/* 
    Problem
     - Find the number of non-empty substrings in a binary string "s" that contain at most "k" zeros or at most "k" ones

    Approaches
     1. Count all the new substrings created by the current element
      a. Consider that the number of new substrings created equals the current window size

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
    int countKConstraintSubstrings(string s, int k) {
        int n = s.length();
        int ans = 0;

        int zeros = 0;
        int ones = 0;

        int l = 0;
        for (int r = 0; r < n; r++) {
            if (s[r] == '0') zeros++;
            if (s[r] == '1') ones++;

            while (zeros > k && ones > k) {
                if (s[l] == '0') zeros--;
                if (s[l] == '1') ones--;
                l++;
            }

            ans += r - l + 1;
        }

        return ans;
    }
};