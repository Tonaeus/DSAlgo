/* 
    Problem
     - Delete nodes from the binary tree if their value exists in the given array

    Approaches
     1. Traverse the tree in post-order, and if the current node value exists in the set, then add its children to the array and signal its parent to delete it

    Data Structures
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
    vector<TreeNode*> delNodes(TreeNode* root, vector<int>& to_delete) {
        vector<TreeNode*> ans;
        unordered_set<int> set(to_delete.begin(), to_delete.end()); 
        TreeNode* dum = new TreeNode(-1, root, nullptr);
        set.insert(-1);
        dfs(dum, set, ans);
        delete dum;
        return ans;
    }
private: 
    bool dfs(TreeNode* root, unordered_set<int>& set, vector<TreeNode*>& ans) {
        if (!root) return false;

        if (dfs(root->left, set, ans)) {
            delete root->left;
            root->left = nullptr;
        }
        if (dfs(root->right, set, ans)) {
            delete root->right;
            root->right = nullptr;
        }

        if (set.contains(root->val)) {
            if (root->left) {
                ans.push_back(root->left);
            }
            if (root->right) {
                ans.push_back(root->right);
            }
            return true;
        }

        return false;
    }
};