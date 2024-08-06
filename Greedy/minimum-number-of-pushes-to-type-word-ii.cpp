/* 
    Problem
     1. Find the minimum number of key presses required to type a given string, using a remapped telephone keypad, where each letter is mapped to exactly one key

    Approaches
     1. Map the letters that appear more frequently in the string to the earlier positions of the keys, and then count the number of presses required for each occurrence of each letter in the string
      a. Consider that there are only 8 keys available for mapping to letters

    Data Structures
     - Array
    Algorithms

    Time Complexity
     - O(n)
    Space Complexity
     - O(1)
*/

#include <bits/stdc++.h>
using namespace std;

// Solution 1

class Solution {
public:
    int minimumPushes(string word) {
        vector<int> freq(26);
        for (char c : word) {
            freq[c - 'a']++;
        }      

        vector<pair<int, int>> arr;
        for (int i = 0; i < 26; i++) {
            arr.push_back({freq[i], i});
        }
        sort(arr.begin(), arr.end(), greater<>());

        vector<int> mp(26);
        for (int i = 0; i < 26; i++) {
            mp[arr[i].second] = i / 8 + 1;
        }

        int ans = 0;
        for (char c : word) {
            ans += mp[c - 'a'];
        }   

        return ans;
    }
};

// Solution 1.1

class Solution {
public:
    int minimumPushes(string word) {
        vector<int> freq(26);
        for (char c : word) {
            freq[c - 'a']++;
        }      
        sort(freq.rbegin(), freq.rend());

        int ans = 0;
        for (int i = 0; i < 26; i++) {
            if (freq[i] == 0) break;
            ans += freq[i] * (i / 8 + 1);
        }

        return ans;
    }
};