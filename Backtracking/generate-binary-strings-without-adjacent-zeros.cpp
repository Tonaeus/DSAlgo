/* 
    Problem 
     - Find all binary strings of a specified length that do not have adjacent zeros

    Approaches
     1. Build the binary string bit by bit
      a. Consider that if the current character is a "0", then the next can only be a "1"
      b. Consider that if the current character is a "1", then the next can be either a "0" or a "1"

    Data Structures
    Algorithms

    Time Complexity
     - O(2^n)
    Space Complexity
     - O(2^n)
*/

#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    vector<string> validStrings(int n) {
        vector<string> ans;
        dfs(ans, "", n);
        return ans;
    }
private: 
    void dfs(vector<string>& ans, string s, int n) {
        if (n == 0) {
            ans.push_back(s);
            return;
        }
        if (s.empty() || s.back() == '1') {
            dfs(ans, s + '0', n - 1);
            dfs(ans, s + '1', n - 1);
        }
        else {
            dfs(ans, s + '1', n - 1);
        }
        return;
    }
};
