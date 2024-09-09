/* 
    Problem 
     - Find the player who first wins k consecutive games in a queue of n players, where each game is played by the first two players in the queue and is won by the player with the higher skill level, and the winner staying at the front while the loser moves to the end
    
    Approaches
     1. Compare the first two value and push the loser to the back

    Data Structures
     - Queue
    Algorithms

    Time Complexity
     - O(n)
    Space Complexity
     - O(n)
*/

#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int findWinningPlayer(vector<int>& skills, int k) {
        queue<int> q;
        int count = 0;
        
        for (int i = 0; i < skills.size(); i++) {
            q.push(i);
        }
        
        int winner = q.front();
        q.pop();
        
        while (1) {
            int challenger = q.front();
            q.pop();

            if (skills[winner] > skills[challenger]) {
                q.push(challenger);
            }
            else {
                count = 0;
                q.push(winner);
                winner = challenger;
            }
            count++;
            
            if (count == k || count >= skills.size() - 1) {
                return winner;
            }
        }

        return -1;
    }   
};