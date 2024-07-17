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
        string str;
        dfs(ans, str, n);
        return ans;
    }
private: 
    void dfs(vector<string>& ans, string& str, int n) {
        if (n == 0) {
            ans.push_back(str);
            return;
        }
        if (str.empty() || str.back() == '1') {
            str.push_back('0');
            dfs(ans, str, n - 1);
            str.pop_back();

            str.push_back('1');
            dfs(ans, str, n - 1);
            str.pop_back();
        }
        else {
            str.push_back('1');
            dfs(ans, str, n - 1);
            str.pop_back();
        }
        return;
    }
};
