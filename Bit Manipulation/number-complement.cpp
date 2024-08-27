/* 
    Problem
     - Find the complement of a given integer "num", where the complement of an integer is an integer with inverted bits

    Approaches
     1. Create a bitmask with set bits from the LSB to the MSB of "num", and then XOR "num" with the bitmask
      a. Consider that the position of the MSB of "num" can be found
      b. Consider that XORing a bit with a set bit will invert the bit's value
      
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
    int findComplement(int num) {
        int msbPos = log2(num);
        unsigned int bitmask = (1u << (msbPos + 1)) - 1;
        return num ^ bitmask;
    }
};