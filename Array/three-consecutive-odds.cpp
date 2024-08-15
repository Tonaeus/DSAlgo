/* 
    Problem 
     - Find out if there are three consecutive odd numbers in the array

    Approaches
     1. Count the current number of consecutive odd numbers

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

class Solution {
public:
    bool threeConsecutiveOdds(vector<int>& arr) {
        int cnt = 0;
        for (int i = 0; i < size(arr); i++) {
            if (arr[i] % 2 != 0) cnt++;
            else cnt = 0;
            if (cnt == 3) return true;
        }
        return false;
    }
};