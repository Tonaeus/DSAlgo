/* 
    Problem
     - Find the maximum number of customers that can be satisfied, given the operation to make the owner not grumpy for k minutes

    Approaches
     1. Sum the number of satisfied customers and the number of unrealized customers in the best minutes window

    Data Structures
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
    int maxSatisfied(vector<int>& customers, vector<int>& grumpy, int minutes) {
        int ans = 0;
        
        int mxWindow = 0;
        for (int i = 0; i < minutes; i++) {
            if (grumpy[i] == 0) {
                ans += customers[i];
            }
            mxWindow += customers[i] * grumpy[i];
        }

        int window = mxWindow;
        for (int i = minutes; i < customers.size(); i++) {
            if (grumpy[i] == 0) {
                ans += customers[i];
            }
            mxWindow += customers[i] * grumpy[i];
            mxWindow -= customers[i - minutes] * grumpy[i - minutes];
            window = max(window, mxWindow);
        }
        
        return ans + window;
    }
};