/* 
    Problem
     - Find out whether Alice or Bob wins the game, where the first player unable to make a move on their turn loses, given that Alice has to remove a non-empty substring with an odd number of vowels on her turn and Bob has to remove a non-empty substring with an even number of vowels on his turn
    
    Approaches
     1. Check if the string contains at least 1 vowel
      a. Consider that if there are no vowels, then Bob wins because Alice has no vowels to pick
      b. Consider that if there is an odd number of vowels, then Alice wins because she can pick all of the vowels
      c. Consider that if there is an even number of vowels, then Alice wins because she can pick all but one of the vowels

    Data Structures
    Algorithms

    Time Complexity
     - O(n)
    Space Complexity
     - O(1)
*/

#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    bool doesAliceWin(string s) {
        for (char c : s) {
            if (c == 'a' || c == 'e' || c == 'i' || c == 'o' || c == 'u') {
                return true;
            }
        }
        return false;
    }
};