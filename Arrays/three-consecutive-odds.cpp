/* 
    Approaches
     1. Iterate through the array and use a counter to track the number of consecutive odd numbers

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