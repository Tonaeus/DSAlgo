/* 
    Problem
     - Find the winner of the game, where the winner is the friend that remains when n friends sit in a circle and every kth friend is eliminated until only 1 friend remains

    Approaches     
     1. Move all the friends to the left of the kth friend to the back, remove the kth friend, and then repeat these steps until only 1 friend remains

    Data Structures
     - Queue
    Algorithms

    Time Complexity
     - O(n)
    Space Complexity
     - O(1)
*/

#include <bits/stdc++.h>
using namespace std;

// Solution 1

class Solution {
public:
    int findTheWinner(int n, int k) {
        queue<int> q;
        for (int i = 0; i < n; i++) {
            q.push(i + 1);
        }
        for (int i = 0; i < n - 1; i++) {
            for (int j = 0; j < k - 1; j++) {
                q.push(q.front());
                q.pop();
            }
            q.pop();
        }
        return q.front();
    }
};

// Solution 1.1

class Solution {
public:
    int findTheWinner(int n, int k) {
        return helper(n, k) + 1;
    }

private:
    int helper(int n, int k) {
        if (n == 1) return 0;
        return (helper(n - 1, k) + k) % n;
    }
};

// Solution 1.1

class Solution {
public:
    int findTheWinner(int n, int k) {
        int ans = 0;

        for (int i = 2; i <= n; i++) {
            ans = (ans + k) % i;
        }

        return ans + 1;
    }
};
