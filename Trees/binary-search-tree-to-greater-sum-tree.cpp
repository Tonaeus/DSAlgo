/* 
    Approaches
     1. Traverse the tree in reverse in-order, add the sum of visited nodes to the current node, and then update the sum of visited nodes

    Data Structures
    Algorithms
     - In-order traversal 

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
    TreeNode* bstToGst(TreeNode* root) {
        int sum = 0;
        dfs(root, sum);
        return root;
    }
private:
    void dfs(TreeNode* root, int& sum) {
        if (!root) return;
        dfs(root->right, sum);
        root->val += sum;
        sum = root->val;
        dfs(root->left, sum);
        return;
    }
};