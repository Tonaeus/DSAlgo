/* 
    Problem
     - Find the minimum number of operations needed to return to the main folder after a series of folder change operations, given the operations "../", "./", and "x/"

    Approaches
     1. Count the distance from the main folder
      a. Consider that the "../" operation decreases the distance from the main folder by 1, unless the distance is already 0
      b. Consider that the "./" operation does not change the distance from the main folder
      c. Consider that the "x/" operation increases the distance from the main folder by 1

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
    int minOperations(vector<string>& logs) {
        int ans = 0;
        for (const auto& log : logs) {
            if (log == "../") { 
                if (ans != 0) {
                    ans--;
                }
            }
            else if (log != "./") {
                ans++;
            }
        }
        return ans;
    }
};