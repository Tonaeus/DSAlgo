/* 
    Problem
     - Find the minimum and maximum distance between any two distinct critical points

    Approaches
     1. Find the distance between the newest and the first critical points, and between the newest and the previous critical points
      a. Consider that (p < c and n < c) or (p > c and n > c)
                       (p - c < 0 and n - c < 0) or (p - c > 0 and n - c > 0) 
                       (p - c)(n - c) > 0 or (p - c)(n - c) > 0
                       (p - c)(n - c) > 0       
      b. Consider that the minimum distance is between adjacent critical points
      c. Consider that the maximum distance is between the first and last critical points

    Data Structures
     - Linked list
    Algorithms

    Time Complexity
     - O(n)
    Space Complexity
     - O(1)
*/

#include <bits/stdc++.h>
using namespace std;

struct ListNode {
    int val;
    ListNode *next;
    ListNode() : val(0), next(nullptr) {}
    ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode *next) : val(x), next(next) {}
};

class Solution {
public:
    vector<int> nodesBetweenCriticalPoints(ListNode* head) {
        ListNode* prev = head;
        ListNode* curr = head->next;
        int l = -1, r = -1;
        int mn = INT_MAX, mx = INT_MIN;
        int pos = 1;
        
        while (curr->next) {
            if ((long) (prev->val - curr->val) * (curr->next->val - curr->val) > 0) {
                if (l == -1) {
                    l = r = pos;
                }
                else {
                    mn = min(mn, pos - r);
                    mx = max(mx, pos - l);
                    r = pos;
                }
            }
            prev = curr;
            curr = curr->next;
            pos++;
        }

        return l == r ? vector<int>{-1, -1} : vector<int>{mn, mx};
    }
};