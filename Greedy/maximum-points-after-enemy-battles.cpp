/* 
    Problem 
     - Find the maximum points, given the operations to gain points and to gain energies

    Approaches
     1. Calculate the total energy that can be obtained without the enemy with the smallest energy, and then calculate the points that can be obtained from that total energy
      a. Consider that the initial energy must be greater than or equal to the smallest energy of any enemy in order to obtain points
      b. Consider that performing the first operation on the enemy with the smallest energy maximizes points
      c. Consider that performing the second operation on the remaining enemies maximizes energies
    
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
    long long maximumPoints(vector<int>& enemyEnergies, int currentEnergy) {
        partial_sort(enemyEnergies.begin(), enemyEnergies.begin() + 1, enemyEnergies.end());
        long long sum = accumulate(enemyEnergies.begin() + 1, enemyEnergies.end(), 0);
        return currentEnergy / enemyEnergies.front() ? (currentEnergy + sum) / enemyEnergies.front() : 0;
    }
};