/* 
    Approaches
     1. Choose the most profitable project based on the available capital each time

    Data Structures
    Algorithms
     - Heap

    Time Complexity
     - O(n•log(n)+k•log(n))
    Space Complexity
     - O(n)
*/

#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int findMaximizedCapital(int k, int w, vector<int>& profits, vector<int>& capital) {
        priority_queue<pair<int, int>, vector<pair<int, int>>, greater<>> minHeap;
        priority_queue<int> maxHeap;

        for (int i = 0; i < profits.size(); i++) {
            minHeap.push({capital[i], profits[i]});
        }

        for (int i = 0; i < k; i++) {
            while (!minHeap.empty() && minHeap.top().first <= w) {
                maxHeap.push(minHeap.top().second);
                minHeap.pop();
            }

            if (maxHeap.empty()) {
                return w;
            }

            w += maxHeap.top();
            maxHeap.pop();
        }

        return w;
    }
};