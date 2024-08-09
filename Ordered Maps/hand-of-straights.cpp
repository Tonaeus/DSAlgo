/* 
    Problem
     - Find out if the cards in the hand can be rearranged into groups of size "groupSize" such that each group contains consecutive numbered cards

    Approaches
     1. Build a group of size "groupSize" starting from the lowest numbered card, discard the cards used in the group, and then repeat until no more groups can be formed

    Data Structures
     - Ordered map
    Algorithms

    Time Complexity
     - O(n•log(n)) -> n = number of cards
    Space Complexity
     - O(n)
*/

#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    bool isNStraightHand(vector<int>& hand, int groupSize) {
        map<int, int> mp;

        for (int i = 0; i < hand.size(); i++) {
            mp[hand[i]]++;
        }

        while (!mp.empty()) {
            int tmp = mp.begin()->first; 

            for (int i = 0; i < groupSize; i++) {
                if (mp.find(tmp) == mp.end()) {
                    return false;
                }
                mp[tmp]--;
                if (mp[tmp] == 0) {
                    mp.erase(mp.begin());
                }
                tmp++;
            }
        }

        return true;
    }
};