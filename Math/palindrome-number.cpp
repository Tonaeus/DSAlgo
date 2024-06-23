/* 
    Approaches
     1. Check if the reverse matches the original 
      a. Consider interger overflow
     2. Check if the reversed half matches the other half

    Data Structures
    Algorithms

    Time Complexity
     - O(log(n)) 
    Space Complexity
     - O(1)
*/

#include <bits/stdc++.h>
using namespace std;

// Solution 1

class Solution {
public:
    bool isPalindrome(int x) {
        if (x < 0) { return false; }

        int tmp = x;
        long sum = 0;

        while (tmp != 0) {
            sum *= 10;
            sum += tmp % 10; 
            tmp /= 10; 
        }

        return x == sum; 
    }
};

// Solution 2

class Solution {
public:
    bool isPalindrome(int x) {
        if (x < 0 || (x != 0 && x % 10 == 0)) { return false; }
        
        int reverse = 0;

        while (x > reverse) {
            reverse *= 10;
            reverse += x % 10; 
            x /= 10; 
        }

        return x == reverse || x == reverse / 10; 
    }
};

