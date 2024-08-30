/* 
    Problem
     - Find the node values of an n-ary tree in post-order traversal

    Approaches
     1. Append each node's value to the array after visiting its children

    Data Structures
     - N-ary tree
    Algorithms
     - Post-order traversal

    Time Complexity
     - O(n)
    Space Complexity
     - O(n)
*/

#include <bits/stdc++.h>
using namespace std;

class Node {
public:
    int val;
    vector<Node*> children;

    Node() {}

    Node(int _val) {
        val = _val;
    }

    Node(int _val, vector<Node*> _children) {
        val = _val;
        children = _children;
    }
};

class Solution {
public:
    vector<int> postorder(Node* root) {
        vector<int> ans;
        dfs(root, ans);
        return ans;
    }

private:
    void dfs(Node* root, vector<int>& ans) {
        if (!root) return;

        for (auto chd : root->children) {
            dfs(chd, ans);
        }
        ans.push_back(root->val);

        return; 
    }
};