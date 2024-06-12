/* 
    Approaches
     1. Check every groupSize consecutive cards starting from the lowest number

    Data Structures
     - Binary search tree
    Algorithms

    Time Complexity
     - O(n•log(n)) -> n = size of hand
    Space Complexity
     - O(n)
*/

#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    bool isNStraightHand(vector<int>& hand, int groupSize) {
        map<int, int> bst;

        for (int i = 0; i < hand.size(); i++) {
            bst[hand[i]]++;
        }

        while (!bst.empty()) {
            int tmp = bst.begin()->first; 

            for (int i = 0; i < groupSize; i++) {
                if (bst.find(tmp) == bst.end()) {
                    return false;
                }
                bst[tmp]--;
                if (bst[tmp] == 0) {
                    bst.erase(bst.begin());
                }
                tmp++;
            }
        }

        return true;
    }
};