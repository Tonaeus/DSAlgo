/* 
    Problem
     - Find the frequency of each chemical element, given a chemical formula

    Approaches
     1. Count each chemical element by multiplying its current count by the current multiplier

    Data Structures
     - Binary search tree
     - Stack
    Algorithms

    Time Complexity
     - O(n•log(n))
    Space Complexity
     - O(n)
*/

#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    string countOfAtoms(string formula) {
        map<string, int> bst;
        stack<int> stk({1});
        int cnt = 1;
        for (int i = formula.length() - 1; i >= 0; i--) {
            if (isdigit(formula[i])) {
                int j = i;
                while (isdigit(formula[i - 1])) {
                    i--;
                }
                cnt = stk.top() * stoi(formula.substr(i, j - i + 1));
            }
            else if (formula[i] == ')') {
                stk.push(cnt);
            }
            else if (formula[i] == '(') {
                stk.pop();
                cnt = stk.top();
            }
            else {
                int j = i;
                while (islower(formula[i])) {
                    i--;
                }
                string name = formula.substr(i, j - i + 1);
                bst[name] += cnt;
                cnt = stk.top();
            }
        }
        string ans;
        for (const auto& [key, val] : bst) {
            ans += key;
            ans += val != 1 ? to_string(val) : "";
        }
        return ans;
    }
};