/* 
    Approaches
     1. Get the two heaviest stones and compare them each turn

    Data Structures
     - Heap
    Algorithms

    Time Complexity
     - O(n•log(n))
    Space Complexity
     - O(n)
*/

#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int lastStoneWeight(vector<int>& stones) {
        priority_queue<int> maxHeap(stones.begin(), stones.end());

        int stone1 = maxHeap.top();
        maxHeap.pop();

        while (!maxHeap.empty()) {
            int stone2 = maxHeap.top();
            maxHeap.pop();

            maxHeap.push(stone1 - stone2);

            stone1 = maxHeap.top();
            maxHeap.pop();
        }

        return stone1; 
    }
};