/* 
    Problem
     - Find the node values of a binary tree in post-order traversal

    Approaches
     1. Append each node's value to the array after visiting its left and right children

    Data Structures
     - Binary tree
    Algorithms
     - Post-order travesal

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
    vector<int> postorderTraversal(TreeNode* root) {
        vector<int> ans;
        dfs(root, ans);
        return ans;
    }

private:
    void dfs(TreeNode* root, vector<int>& ans) {
        if (!root) return;

        dfs(root->left, ans);
        dfs(root->right, ans);
        ans.push_back(root->val);

        return;
    }
};