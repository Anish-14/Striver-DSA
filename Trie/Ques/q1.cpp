#include<iostream>
using namespace std;

// Implement Trie (Prefix Tree)
// https://leetcode.com/problems/implement-trie-prefix-tree/description/

class TrieNode {
public:
    vector<TrieNode*> v;
    bool isTerminal;

    TrieNode() : v(26, nullptr), isTerminal(false) {}
};

class Trie {
    TrieNode* root;
public:
    Trie() {
        root = new TrieNode();
    }
    
    void insert(string word) {
        int n = word.size();
        TrieNode* node = root;
        for(int i = 0; i<n; i++){
            if(node->v[word[i] - 'a'] == nullptr){
                node->v[word[i] - 'a'] = new TrieNode();
            }
            node = node->v[word[i] - 'a'];
        }
        node->isTerminal = true;
    }
    
    bool search(string word) {
        int n = word.size();
        TrieNode* node = root;
        for(int i = 0; i<n; i++){
            if(node->v[word[i] - 'a'] == nullptr)   return false;
            node = node->v[word[i] - 'a'];
        }

        return node->isTerminal;
    }
    
    bool startsWith(string prefix) {
        int n = prefix.size();
        TrieNode* node = root;
        for(int i = 0; i<n; i++){
            if(node->v[prefix[i] - 'a'] == nullptr)     return false;
            node = node->v[prefix[i] - 'a'];
        }

        return true;
    }
};

/**
 * Your Trie object will be instantiated and called as such:
 * Trie* obj = new Trie();
 * obj->insert(word);
 * bool param_2 = obj->search(word);
 * bool param_3 = obj->startsWith(prefix);
 */

