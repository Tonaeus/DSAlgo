/* 
    Problem
     - Merge nodes between consecutive nodes with a value of 0 into a single node whose value is the sum of all the nodes being merged

    Approaches
     1. Store the sum of the nodes being merged into a single node and then connect these single nodes

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
    ListNode* mergeNodes(ListNode* head) {
        ListNode* sum = head->next;
        ListNode* prev = nullptr;
        ListNode* curr = head->next;
        while (curr) {
            while (curr->val) {
                sum->val += curr->next->val;
                prev = curr;
                curr = curr->next;
                if (prev != sum) {
                    delete prev;
                }
            }
            sum->next = curr->next;
            sum = curr->next;
            delete curr;
            curr = sum;
        }
        ListNode* ans = head->next;
        delete head;
        return ans;
    }
};
