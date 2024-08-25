/* 
    Problem
     - Create a class that maintains and returns the kth highest score after each new score submission, given an integer "k" and a stream of test scores

    Approaches
     1. Track only the "k" greatest scores, with the smallest score at the front, to maintain the kth highest score

    Data Structures
     - Heap
    Algorithms

    Time Complexity
     - Constructor: O(n•log(k))
     - `add`: O(log(k))
    Space Complexity
     - O(k)
*/

#include <bits/stdc++.h>
using namespace std;

class KthLargest {
public:
    KthLargest(int k, vector<int>& nums) : k(k) {
        for (int num : nums) {
            add(num);
        }
    }
    
    int add(int val) {
        if (mnh.size() < k) {
            mnh.push(val);
        } 
        else if (val > mnh.top()) {
            mnh.pop();
            mnh.push(val);
        }
        
        return mnh.top();
    }

private:
    int k;
    priority_queue<int, vector<int>, greater<>> mnh; 
};