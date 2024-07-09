/* 
    Problem 
     - Find the maximum height of a triangle formed by two groups of coloured balls, given that each row is the same colour and each adjacent row is a different colour
    
    Approaches
     1. Alternative between the two colours to build each row of the triangle
      a. Consider that the triangle can start with either a red or blue ball

    Data Structures
    Algorithms

    Time Complexity
     - O(sqrt(n)) -> n = total number of balls
    Space Complexity
     - O(1)
*/

#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int maxHeightOfTriangle(int red, int blue) {
        return max(helper(red, blue), helper(blue, red));
    }
private: 
    int helper(int odd, int even) {
        int ans = 0;
        int count = 1;
        while (1) {
            if (count % 2 != 0) {
                if ((odd -= count) >= 0) ans++;
                else break;
            }
            else {
                if ((even -= count) >= 0) ans++;
                else break;
            }
            count++;
        }
        return ans;
    }
};
