/* 
    Approaches
     1. Calculate the sum of the distances between each student and the closest seat
    
    Data Structures
    Algorithms

    Time Complexity
     - O(n•log(n))
    Space Complexity
     - O(log(n))
*/

#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int minMovesToSeat(vector<int>& seats, vector<int>& students) {
        sort(seats.begin(), seats.end());
        sort(students.begin(), students.end());
        
        int ans = 0;
        for (int i = 0; i < seats.size(); i++) {
            ans += abs(seats[i] - students[i]);
        }

        return ans;
    }
};