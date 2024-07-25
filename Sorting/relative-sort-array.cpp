/* 
    Problem 
     - Sort "array 1" such that elements appear in the order specified by "array 2", with any elements not in "array 2" placed at the end of "array 1" in ascending order

    Approaches
     1. Separate the elements from "array 1" into those present in and those absent from "array 2", then combine the ordered present elements with the sorted absent elements

    Data Structures
    Algorithms

    Time Complexity
     - O(m+n•log(n)) -> n = size of arr1, m = size of arr2
    Space Complexity
     - O(m+n)
*/

#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    vector<int> relativeSortArray(vector<int>& arr1, vector<int>& arr2) {
        unordered_map<int, int> mp;
        vector<int> present, absent;

        for (int ele: arr2) {
            mp[ele] = 0;
        }

        for (int ele: arr1) {
            if (mp.find(ele) != mp.end()) {
                mp[ele]++;
            }
            else {
                absent.push_back(ele);
            }
        }

        for (int ele: arr2) {
            for (int i = 0; i < mp[ele]; i++) {
                present.push_back(ele);
            }
        }

        sort(absent.begin(), absent.end());
        present.insert(present.end(), absent.begin(), absent.end());
        return present;
    }
};