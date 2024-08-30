/* 
    Problem
     - Create a class to efficiently store and retrieve keys, where each key is a sequence of characters representing a word

    Approaches
     1. Build a tree where each node represents a character, and each sequence of nodes ending at a node that marks the end of a key represents a key

    Data Structures
     - Trie
    Algorithms

    Time Complexity
     - Constructor: O(1) -> w = number of words, l = average length of the words
     - `insert`: O(l)
     - `search`: O(l)
     - `startsWith`: O(l)
    Space Complexity
     - O(w•l)
*/

#include <bits/stdc++.h>
using namespace std;

class TrieNode {
public:
    vector<TrieNode*> children;
    bool isEndOfWord;

    TrieNode() : children(26, nullptr) { 
        isEndOfWord = false;
    }
};

class Trie {
public:
    Trie() { 
        root = new TrieNode(); 
    }
    
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