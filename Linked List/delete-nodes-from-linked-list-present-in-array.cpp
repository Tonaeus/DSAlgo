/* 
    Problem
     - Delete nodes from the linked list if their value exists in the given array

    Approaches
     1. Connect the previous node to the next node if the current node value exists in the set

    Data Structures
     - Linked list
     - Hash set
    Algorithms

    Time Complexity
     - O(n)
    Space Complexity
     - O(n)
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
    ListNode* modifiedList(vector<int>& nums, ListNode* head) {
        unordered_set<int> s(nums.begin(), nums.end());
        ListNode* dum = new ListNode(-1, head);
        ListNode* prev = dum;
        ListNode* curr = head;
        while (curr) {
            if (s.contains(curr->val)) {
                prev->next = curr->next;
                delete curr;
            }
            else {
                prev = curr;
            }
            curr = prev->next;
        }
        ListNode* ans = dum->next;
        delete dum;
        return ans;            
    }
};