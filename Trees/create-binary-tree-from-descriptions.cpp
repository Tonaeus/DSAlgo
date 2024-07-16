/* 
    Problem
     - Create a binary tree, given the descriptions of the parent and child nodes

    Approaches
     1. Build the binary tree and return the node that does not have a parent

    Data Structures
     - Binary tree
    Algorithms

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
    TreeNode* createBinaryTree(vector<vector<int>>& descriptions) {
        unordered_map<int, TreeNode*> mp;
        unordered_set<int> s;
        for (const auto& desc : descriptions) {
            int par = desc[0];
            int chd = desc[1];
            if (!mp.contains(par)) {
                mp[par] = new TreeNode(par);
            }
            if (!mp.contains(chd)) {
                mp[chd] = new TreeNode(chd);
            }
            if (desc[2]) {
                mp[par]->left = mp[chd];
            }
            else {
                mp[par]->right = mp[chd];
            }
            s.insert(chd);
        }
        for (const auto& [key, val] : mp) {
            if (!s.contains(key)) {
                return val;
            }
        }
        return nullptr;
    }
};