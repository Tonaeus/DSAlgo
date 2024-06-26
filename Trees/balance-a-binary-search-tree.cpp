/* 
    Approaches
     1. Find the nodes of the original binary search tree in sorted order and create a new tree with paritioning from the middle recursively
      a. Consider that in-order traversal of a binary search tree gives the nodes in sorted order

    Data Structures
     - Binary search tree
    Algorithms
     - In-order traversal
     - Pre-order traversal

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
    TreeNode* balanceBST(TreeNode* root) {
        vector<int> nodes;
        helper(root, nodes);
        return dfs(nodes, 0, nodes.size() - 1);
    }
private: 
    void helper(TreeNode* root, vector<int>& nodes) {
        if (!root) return;
        helper(root->left, nodes);
        nodes.push_back(root->val);
        helper(root->right, nodes);
        return;
    }
    TreeNode* dfs(vector<int> nodes, int lo, int hi) {
        if (lo > hi) {
            return nullptr;
        } 
        int mid = lo + (hi - lo) / 2;
        TreeNode* node = new TreeNode(nodes[mid]);
        node->left = dfs(nodes, lo, mid - 1);
        node->right = dfs(nodes, mid + 1, hi);
        return node;
    }
};