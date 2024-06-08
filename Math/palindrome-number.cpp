/* 
    Approaches
     1. Check if reverse matches original 
     2. Check if reversed half matches other half

    Data Structures
    Algorithms

    Time Complexity
     - O(log(n)) 
    Space Complexity
     - O(1)
 */

#include <bits/stdc++.h>
using namespace std;

class Solution_1 {
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

class Solution_2 {
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

