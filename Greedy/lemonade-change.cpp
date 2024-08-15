/* 
    Problem
     - Find out if it is possible to provide the correct change to every customer at a lemonade stand, given that there is no change at the lemonade stand initially, and each customer pays with either a $5, $10, or $20 bill

    Approaches
     1. Check if there are a sufficient number of bills for change when using $10 bills before $5 bills

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
    bool lemonadeChange(vector<int>& bills) {
        vector<int> mp(3);

        for (int b : bills) {
            mp[b / 10]++;

            while (b - 10 > 0 && mp[1] > 0) {
                b -= 10;
                mp[1]--;
            }
            while (b - 5 > 0) {
                b -= 5;
                mp[0]--;
            }

            if (mp[0] < 0) return false;
        }

        return true; 
    }
};