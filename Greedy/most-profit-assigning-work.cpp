/* 
    Approaches
     1. Iterate from the worker with the lowest ability and update the pointer that keeps track of the job with the highest profit and difficulty less than or equal to that of the worker being assigned a job
    
    Data Structures
     - Heap
     - Array
    Algorithms

    Time Complexity
     - O(n•log(n)+m•log(m)) -> n = number of jobs, m = number of workers
    Space Complexity
     - O(n)
*/

#include <bits/stdc++.h>
using namespace std;

// Solution 1

class Solution {
public:
    int maxProfitAssignment(vector<int>& difficulty, vector<int>& profit, vector<int>& worker) {
        priority_queue<int, vector<int>, greater<int>> pq(worker.begin(), worker.end());
        priority_queue<pair<int, int>, vector<pair<int, int>>, greater<>> minHeap;
        priority_queue<int> maxHeap;

        for (int i = 0; i < difficulty.size(); i++) {
            minHeap.push({difficulty[i], profit[i]});
        }

        int ans = 0;

        while (!pq.empty()) {
            int tmp = pq.top();
            pq.pop();

            while (!minHeap.empty() && minHeap.top().first <= tmp) {
                maxHeap.push(minHeap.top().second);
                minHeap.pop();
            }

            ans += !maxHeap.empty() ? maxHeap.top() : 0;
        }

        return ans;
    }
};

// Solution 1.1

class Solution {
public:
    int maxProfitAssignment(vector<int>& difficulty, vector<int>& profit, vector<int>& worker) {
        vector<pair<int, int>> jobs;

        for (int i = 0; i < difficulty.size(); i++) {
            jobs.push_back({difficulty[i], profit[i]});
        }

        sort(jobs.begin(), jobs.end());
        sort(worker.begin(), worker.end());

        int maxProfit = 0;
        int ans = 0;

        for (int i = 0, j = 0; i < worker.size(); i++) {
            while (j < jobs.size() && jobs[j].first <= worker[i]) {
                maxProfit = max(maxProfit, jobs[j].second);
                j++;
            }

            ans += maxProfit;
        }

        return ans;
    }
};

