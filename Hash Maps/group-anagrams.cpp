/* 
    Problem 
     - Find all groups of anagrams in an array of strings

    Approaches
     1. Group strings that have the same character frequency together

    Data Structures
     - Hash map
     - Array
    Algorithms

    Time Complexity
     - O(n•k) -> O(n•k) -> n = number of words, k = average length of each word
    Space Complexity
     - O(n•k)
*/

#include <bits/stdc++.h>
using namespace std;

// Solution 1

class Solution {
public:
    vector<vector<string>> groupAnagrams(vector<string>& strs) {
        unordered_map<string, vector<string>> mp;

        for (const auto& s : strs) {
            string t = s;
            sort(t.begin(), t.end());
            mp[t].push_back(s);
        }

        vector<vector<string>> ans;

        for (const auto& [key, anagrams] : mp) {
            ans.push_back(anagrams);
        }

        return ans;
    }
};

// Solution 1.1

class Solution {
public:
    vector<vector<string>> groupAnagrams(vector<string>& strs) {
        unordered_map<string, vector<string>> mp;

        for (const auto& s : strs) {
            vector<int> freq(26);
            for (int i = 0; i < s.length(); i++) {
                freq[s[i] - 'a']++;
            }
            string freqS;
            for (int i = 0; i < 26; i++) {
                freqS += '#' + to_string(freq[i]);
            }
            mp[freqS].push_back(s);
        }

        vector<vector<string>> ans;

        for (const auto& [key, anagrams] : mp) {
            ans.push_back(anagrams);
        }

        return ans;
    }
};