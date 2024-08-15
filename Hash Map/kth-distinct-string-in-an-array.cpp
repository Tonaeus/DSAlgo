/* 
    Problem
     - Find the kth unique string in a string array

    Approaches
     1. Count the frequency of each string in the array, and then determine the kth string in the array with a frequency of 1

    Data Structures
     - Hash map
    Algorithms

    Time Complexity
     - O(n)
    Space Complexity
     - O(n)
*/

#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    string kthDistinct(vector<string>& arr, int k) {
        unordered_map<string, int> freq;
        for (auto& s : arr) {
            freq[s]++;
        }

        for (auto& s : arr) {
            if (freq[s] == 1) {
                k--;
            } 
            if (k == 0) {
                return s;
            }
        }

        return "";
    }
};