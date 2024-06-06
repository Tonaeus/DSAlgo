/* 
    Approaches
     1. Find the intersection of each characters
    Comments
     - First iteration use first word frequency for common count

    Data Structures
     - Array
    Algorithms

    Time Complexity
     - O(n) -> n = characters
    Space Complexity
     - O(1)
 */

#include <bits/stdc++.h>
using namespace std;

class Solution_1 {
public:
    vector<string> commonChars(vector<string>& words) {
        unordered_map<char, int> mp1;
        unordered_map<char, int> mp2;
        unordered_map<char, int> mp3;
        vector<string> arr;

        for (auto c: words[0]) {
            mp1[c]++;
        }

        for (int i = 1; i < words.size(); i++) {
            for (auto c: words[i]) {
                mp2[c]++;
            }
            for (auto& [key, value]: mp2) {
                if (mp1.find(key) != mp1.end()) {
                    mp3[key] = min(mp1[key], value);
                } 
            }
            mp1 = mp3;
            mp2.clear();
            mp3.clear();
        }

        for (auto& it: mp1) {
            for (int i = 0; i < it.second; i++) {
                arr.push_back(string{it.first});
            }
        }

        return arr;
    }
};

class Solution_1_1 {
public:
    vector<string> commonChars(vector<string>& words) {
        vector<int> commonCount(26, INT_MAX);
        vector<string> ans;

        for (const auto& w: words) {
            vector<int> count(26, 0);
            for (auto c: w) {
                count[c - 'a']++;
            }
            for (int i = 0; i < 26; i++) {
                commonCount[i] = min(commonCount[i], count[i]);
            }
        }

        for (int i = 0; i < 26; i++) {
            for (int j = 0; j < commonCount[i]; j++) {
                ans.push_back(string(1, i + 'a'));
            }
        }

        return ans;
    }
};