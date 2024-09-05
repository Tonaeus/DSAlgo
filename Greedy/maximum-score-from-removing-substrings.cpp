/* 
    Problem
     - Find the maximum points, given the operations to gain x points by removing substring "ab" and gain y points by removing substring "ba" 

    Approaches
     1. Calculate the points gained by performing the operation that yields the most points before performing the other operation
      a. Consider that if "ab" is removed in the first phase, then "ab" will not be created in the second phase because there will be no substring "abab" in the second phase
      b. Consider that if "ba" is removed in the first phase, then "ba" will not be created in the second phase because there will be no substring "baba" in the second phase
     
    Data Structures
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
    int maximumGain(string s, int x, int y) {
        if (y > x) {
            return helper(s, "ba", y) + helper(s, "ab", x);
        }
        else {
            return helper(s, "ab", x) + helper(s, "ba", y);
        }
    }

private: 
    int helper(string& s, string substr, int p) {
        int res = 0;
        string stk;
        
        for (char c : s) {
            if (!stk.empty() && stk.back() == substr[0] && c == substr[1]) {
                stk.pop_back();
                res += p;
            } 
            else {
                stk.push_back(c);
            }
        }
        
        s = stk;

        return res;
    }
};

// Solution 1.1 

class Solution {
public:
    int maximumGain(string s, int x, int y) {
        if (y > x) {
            return helper(s, "ba", y) + helper(s, "ab", x);
        }
        else {
            return helper(s, "ab", x) + helper(s, "ba", y);
        }
    }

private: 
    int helper(string& s, string substr, int p) {
        int res = 0;
        int i = 0;

        for (int j = 0; j < s.length(); j++) {
            if (i > 0 && s[i - 1] == substr[0] && s[j] == substr[1]) {
                res += p;
                i--;
            } 
            else {
                s[i] = s[j];
                i++;
            }
        }
        
        s.resize(i);

        return res;
    }
};