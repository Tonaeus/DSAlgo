/* 
    Problem 
     - Find and replace all derivatives in a sentence with their shortest root from a given dictionary

    Approaches
     1. Check each word's substring starting from the first character to find a root match
     2. Check if the word is in the trie to find a root match

    Data Structures
     - Hash set
     - Trie
    Algorithms

    Time Complexity
     - O(d•l+s•l) -> d = number of words in the dictionary, s = number of words in the sentence, l = average length of each word
    Space Complexity
     - O(d•l+s•l)
 */

#include <bits/stdc++.h>
using namespace std;

// Solution 1

class Solution {
public:
    string replaceWords(vector<string>& dictionary, string sentence) {
        unordered_set<string> dictSet(dictionary.begin(), dictionary.end());
        
        string word; 
        stringstream ss(sentence); 

        string ans = "";
        while(getline(ss, word, ' ')){
            ans += helper(dictSet, word) + " ";
        }

        ans.pop_back();
        return ans;
    }
private:
    string helper(unordered_set<string> dictSet, string word) {
        for (int i = 1; i < word.length(); i++) {
            string root = word.substr(0, i);
            if (dictSet.contains(root)) {
                return root;
            }
        }
        return word;
    }
};

// Solution 2

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
    
    string shortestRoot(string word) {
        TrieNode* curr = root;
        for (int i = 0; i < word.length(); i++) {
            if (!curr->children[word[i] - 'a']) {
                return word;
            }
            curr = curr->children[word[i] - 'a'];
            if (curr->isEndOfWord) {
                return word.substr(0, i + 1);
            }
        }
        return word;
    }
    
private:
    TrieNode* root;
};

class Solution {
public:
    string replaceWords(vector<string>& dictionary, string sentence) {
        Trie dictTrie = Trie();
        for (string root: dictionary) {
            dictTrie.insert(root);
        }

        string word; 
        stringstream ss(sentence); 

        string ans = "";
        while(getline(ss, word, ' ')){
            ans += dictTrie.shortestRoot(word) + " ";
        }

        ans.pop_back();
        return ans;
    }
};