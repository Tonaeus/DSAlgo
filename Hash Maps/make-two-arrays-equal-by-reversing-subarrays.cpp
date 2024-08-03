/* 
    Problem
     - Find out if it is possible to make two arrays equal, given the operation of selecting any non-empty subarray of "arr" and reversing it
  
    Approaches
     1. Determine if the two arrays contain the same elements

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
    bool canBeEqual(vector<int>& target, vector<int>& arr) {
        unordered_map<int, int> freq;
        for (int num : target) {
            freq[num]++;
        }

        for (int num : arr) {
            if (!freq.contains(num)) return false;

            freq[num]--;
            if (freq[num] == 0) {
                freq.erase(num);
            }
        }

        return true;
    }
};