/* 
    Approaches
     1. Order elements by the second array and append the remaining sorted elements

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