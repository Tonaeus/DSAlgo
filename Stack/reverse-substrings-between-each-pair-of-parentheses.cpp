/* 
    Problem
     - Find the string formed by reversing the substrings within each pair of matching round brackets, starting from the innermost pair, and removing all round brackets

    Approaches
     1. Reverse the substring from the last "(" up to the current ")" each time a ")" is found, and then remove both "(" and ")" 
     2. Check if the current character is a "(" or a ")", and if it is, jump to its pair and reverse the direction, otherwise, add it to the string

    Data Structures
     - Stack
     - Hash map
    Algorithms

    Time Complexity
     - O(n)
    Space Complexity
     - O(n)
*/

#include <bits/stdc++.h>
using namespace std;

// Solution 1

class Solution {
public:
    string reverseParentheses(string s) {
        string stk;

        for (char c : s) {
            if (c == ')') {
                string tmp;
                while (stk.back() != '(') {
                    tmp += stk.back();
                    stk.pop_back();
                }
                stk.pop_back();
                stk += tmp;
            }
            else {
                stk.push_back(c);
            }
        }

        return stk;
    }
};

// Solution 1.1

class Solution {
public:
    string reverseParentheses(string s) {
        stack<int> stk;
        string ans;

        for (char c : s) {
            if (c == '(') {
                stk.push(ans.size());
            }
            else if (c == ')') {
                reverse(ans.begin() + stk.top(), ans.end());
                stk.pop();
            }
            else {
                ans.push_back(c);
            }
        }

        return ans;
    }
};

// Solution 2

class Solution {
public:
    string reverseParentheses(string s) {
        stack<int> stk;
        unordered_map<int, int> mp;

        for (int i = 0; i < s.length(); i++) {
            if (s[i] == '(') {
                stk.push(i);
            }
            else if (s[i] == ')') {
                int j = stk.top();
                stk.pop();
                mp[i] = j;
                mp[j] = i;
            }
        }

        string ans;
        int dir = 1;
        for (int i = 0; i < s.length(); i += dir) {
            if (s[i] == '(' || s[i] == ')') {
                i = mp[i];
                dir *= -1;
            }
            else {
                ans.push_back(s[i]);
            }
        }

        return ans;
    }
};