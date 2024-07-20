/* 
    Problem
     - Find the number of good leaf node pairs in the tree, where a good leaf node pair has the shortest path between them that is less than or equal to a given distance

    Approaches
     1. Calculate the distance between each leaf node pair at their lowest common ancestor, and count the pair if the distance is less than or equal to the given distance
      a. Consider that each node can group its descendant leaf nodes based on their distance from the node

    Data Structures
     - Array
     - Binary tree
    Algorithms
     - Post-order traversal

    Time Complexity
     - O(n)
    Space Complexity
     - O(n)
*/

#include <bits/stdc++.h>
using namespace std;

struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode() : val(0), left(nullptr), right(nullptr) {}
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
    TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
};

class Solution {
public:
    int countPairs(TreeNode* root, int distance) {
        int ans = 0;
        dfs(root, distance, ans);
        return ans;
    }
private: 
    vector<int> dfs(TreeNode* root, int& dis, int& ans) {
        vector<int> mp(dis + 1);
        if (!root) {
            return mp;
        }
        if (!root->left && !root->right) {
            mp[1] = 1;
            return mp;
        }

        vector<int> l = dfs(root->left, dis, ans);
        vector<int> r = dfs(root->right, dis, ans);
        
        for (int i = 1; i < dis; i++) {
            for (int j = 1; j < dis; j++) {
                if (i + j > dis) {
                    break;
                }
                else {
                    ans += l[i] * r[j];
                }
            }
        }

        for (int i = 1; i < dis; i++) {
            mp[i] = l[i - 1] + r[i - 1];
        }

        return mp;
    }
};