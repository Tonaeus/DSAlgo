/* 
    Problem
     - Find all combinations of numbers from a given array that sum to a specified target number, where each number in the array can be used only once per combination
    
    Approaches
     1. Choose whether to add or not add a number 
      a. Valid choice: Combination is unique and number - target > 0 
      b. Valid solution: Target = 0
      c. State: Numbers, combination, and target 

    Data Structures
    Algorithms

    Time Complexity
     - O(n•2^n)
    Space Complexity
     - O(n•2^n)
*/

#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    vector<vector<int>> combinationSum2(vector<int>& candidates, int target) {
        sort(candidates.begin(), candidates.end());

        vector<vector<int>> ans;
        vector<int> comb;
        dfs(0, candidates, target, ans, comb);

        return ans;
    }

private:
    void dfs(int i, vector<int>& candidates, int target, vector<vector<int>>& ans, vector<int>& comb) {
        if (target == 0) {
            ans.push_back(comb);
            return;
        }

        for (int j = i; j < candidates.size(); j++) {
            if (j > i && candidates[j] == candidates[j - 1]) continue;
            if (candidates[j] > target) break;

            comb.push_back(candidates[j]);
            dfs(j + 1, candidates, target - candidates[j], ans, comb);
            comb.pop_back();
        }

        return;
    }
};