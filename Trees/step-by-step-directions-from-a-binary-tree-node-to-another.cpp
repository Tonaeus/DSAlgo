/* 
    Problem
     - Find the shortest path from a source node to a destination node in a binary tree

    Approaches
     1. Traverse from the source node to the lowest common ancestor, and then traverse from the lowest common ancestor to the destination node
      - Consider that the shortest path is the path without repeated paths

    Data Structures
     - Binary tree
    Algorithms
     - Depth-first search

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
    string getDirections(TreeNode* root, int startValue, int destValue) {
        string src, dest;
        dfs(root, startValue, src);
        dfs(root, destValue, dest);
        int i = 0;
        while (i < min(src.length(), dest.length())) {
            if (src[i] != dest[i]) break;
            i++;
        }
        return string(src.length() - i, 'U') + dest.substr(i);
    }
private: 
    bool dfs(TreeNode* root, int& tar, string& res) {
        if (!root) return false;
        if (root->val == tar) {
            return true;
        }

        res.push_back('L');
        if (dfs(root->left, tar, res)) return true;
        res.pop_back();

        res.push_back('R');
        if (dfs(root->right, tar, res)) return true;
        res.pop_back();
    
        return false;
    }
};