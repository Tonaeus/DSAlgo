/* 
    Problem
     - Find the placement of each athlete, given their score in a competition

    Approaches
     1. Map the scores to placements and then map the athletes to placements
     2. Map the scores to athletes and then map the scores to placements

    Data Structures
     - Heap
     - Array
    Algorithms

    Time Complexity
     - O(n+m) -> n = athletes, m = highest score
    Space Complexity
     - O(m) 
*/

#include <bits/stdc++.h>
using namespace std;

// Solution 1

class Solution {
public:
    vector<string> findRelativeRanks(vector<int>& score) {
        priority_queue<int> maxHeap(score.begin(), score.end()); 
        vector<string> medals = {"Gold Medal", "Silver Medal", "Bronze Medal"};
        unordered_map<int, string> mp;
        vector<string> ans(score.size());

        int c = 0;
        while (!maxHeap.empty() && c < 3) {
            mp[maxHeap.top()] = medals[c++];
            maxHeap.pop();
        }

        c++;
        while (!maxHeap.empty()) {
            mp[maxHeap.top()] = to_string(c++);
            maxHeap.pop();
        }

        for (int i = 0; i < score.size(); i++) {
            ans[i] = mp[score[i]];
        }

        return ans;
    }
};

// Solution 2

class Solution {
public:
    vector<string> findRelativeRanks(vector<int>& score) {
        int max = *max_element(score.begin(), score.end());
        
        vector<int> idices(max + 1);
        for (int i = 0; i < score.size(); i++) {
            idices[score[i]] = i + 1;
        }

        vector<string> medals = {"Gold Medal", "Silver Medal", "Bronze Medal"};
        vector<string> ans(score.size());

        int c = 1;
        for (int i = max; i >= 0; i--) {
            int orgIdx = idices[i] - 1;
            if (idices[i] != 0) {
                if (c < 4) {
                    ans[orgIdx] = medals[c - 1];
                }
                else {
                    ans[orgIdx] = to_string(c);
                }
                c++;
            }
        }

        return ans;
    }
};



