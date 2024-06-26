/* 
    Approaches
     1. Count the consecutive passes ending with and moving in the same direction as the final pass

    Data Structures
    Algorithms

    Time Complexity
     - O(1)
    Space Complexity
     - O(1)
*/

#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int numberOfChild(int n, int k) {
        int lastChild = n - 1;
        int period = 2 * n - 2; 
        int pass = k % period;

        return pass > lastChild ? period - pass : pass; 
    }
};