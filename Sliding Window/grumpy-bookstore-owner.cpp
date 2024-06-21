/* 
    Approaches
     1. Sum together the realized satisfied customers and the best conseccutive minutes unrealized customers

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
        
        int windowSum = 0;
        for (int i = 0; i < minutes; i++) {
            ans += grumpy[i] == 0 ? customers[i] : 0;

            windowSum += customers[i] * grumpy[i];
        }

        int maxSum = windowSum;
        for (int i = minutes; i < customers.size(); i++) {
            ans += grumpy[i] == 0 ? customers[i] : 0;
     
            windowSum += customers[i] * grumpy[i];
            windowSum -= customers[i - minutes] * grumpy[i - minutes];
            maxSum = max(maxSum, windowSum);
        }
        
        return ans + maxSum;
    }
};