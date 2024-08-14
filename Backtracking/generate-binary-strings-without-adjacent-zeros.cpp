/* 
    Problem 
     - Find all binary strings of a specified length that do not have adjacent zeros

    Approaches
     1. Choose whether to add a "0" bit or a "1" bit
      a. Valid choice: If the current character is a "0", then the next can only be a "1", and if the current character is a "1", then the next can be either a "0" or a "1"
      b. Valid solution: n = 0
      c. State: String and n
     
    Data Structures
    Algorithms

    Time Complexity
     - O(n•2^n)
    Space Complexity
     - O(n•2^n)
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
        }

        str.push_back('1');
        dfs(ans, str, n - 1);
        str.pop_back();

        return;
    }
};