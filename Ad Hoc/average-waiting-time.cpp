/* 
    Problem
     - Find the average waiting time of all customers, given the arrival and prepare time for each customer

    Approaches
     1. Calculate the sum of each customer's individual wait time and then divide that sum by the total number of customers
      a. Consider that if the chef is not busy, then the customer's preparation starts immediately
      b. Consider that if the chef is busy, then the customer's preparation starts after the previous customers' preparation

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
    double averageWaitingTime(vector<vector<int>>& customers) {
        double ans = 0; 
        double t = 0;
        for (const auto& customer : customers) {
            t = max(t, static_cast<double>(customer[0])) + customer[1];
            ans += t - customer[0];
        }
        return ans / customers.size();
    }
};