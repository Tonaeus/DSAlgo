/* 
    Approaches

    Data Structures
    Algorithms

    Time Complexity
    Space Complexity
*/

#include <bits/stdc++.h>
using namespace std;

class TrieNode {
public:
    vector<TrieNode*> children;
    bool isEndOfWord;

    TrieNode() : children(26, nullptr) { isEndOfWord = false; }
};

class Trie {
public:
    Trie() { root = new TrieNode(); }
    
    void insert(string word) {
        TrieNode* curr = root;
        for (char c: word) {
            if (!curr->children[c - 'a']) {
                curr->children[c - 'a'] = new TrieNode();
            }
            curr = curr->children[c - 'a'];
        }
        curr->isEndOfWord = true;
    }
    
    bool search(string word) {
        TrieNode* curr = root;
        for (char c: word) {
            if (!curr->children[c - 'a']) {
                return false;
            }
            curr = curr->children[c - 'a'];
        }
        return curr->isEndOfWord;
    }
    
    bool startsWith(string prefix) {
        TrieNode* curr = root;
        for (char c: prefix) {
            if (!curr->children[c - 'a']) {
                return false;
            }
            curr = curr->children[c - 'a'];
        }
        return true;
    }
private:
    TrieNode* root;
};