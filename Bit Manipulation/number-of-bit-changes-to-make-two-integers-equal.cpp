/* 
    Problem
     - Find the number of changes needed to make "n" equal to "k", given the operation of changing any bit in the binary representation of "n" from "1" to "0"

    Approaches
     1. Check if all bits of "n" that differ from "k" are equal to "1"
      a. Consider that the XOR operation identifies the positions where the operands have different bits
      b. Consider that the AND operation identifies the positions where the operands have set bits

    Data Structures
    Algorithms

    Time Complexity
     - O(1)
    Space Complexity
     - O(1)
*/

#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int minChanges(int n, int k) {
        k ^= n;
        int diffCnt = popcount(static_cast<unsigned int>(k));
        k &= n;
        int onesCnt = popcount(static_cast<unsigned int>(k));
        return diffCnt == onesCnt ? diffCnt : -1;
    }
};