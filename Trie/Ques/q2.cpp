#include<iostream>
using namespace std;

// Implement Trie 2
// https://www.naukri.com/code360/problems/implement-trie_1387095


// root -> A -> P -> P 
// root is not to be deleted or to increase its count, the next pointer which the root pointing to
// has to do it

class TrieNode{
public:
    vector<TrieNode*> v;
    int cnt;
    int terminal;

    TrieNode(){
        this->v = vector<TrieNode*> (26, nullptr);
        this->cnt = 0;
        this->terminal = 0;
    }
};
class Trie{

    public:
    TrieNode* root;
    Trie(){
        root = new TrieNode();
    }

    void insert(string &word){
        int n = word.size();
        TrieNode* node = root;
        for(int i = 0; i<n; i++){
            if(node->v[word[i]-'a'] == nullptr){
                node->v[word[i] - 'a'] = new TrieNode();
            }
            node = node->v[word[i] - 'a'];
            node->cnt++;
        }

        node->terminal++;
    }

    int countWordsEqualTo(string &word){
        int n = word.size();
        TrieNode* node = root;
        for(int i = 0; i<n; i++){
            if(node->v[word[i]-'a'] == nullptr) return 0;
            node = node->v[word[i]-'a'];
        }

        return node->terminal;
    }

    int countWordsStartingWith(string &word){
        int n = word.size();
        TrieNode* node = root;
        for(int i = 0; i<n; i++){
            if(node->v[word[i]-'a'] == nullptr) return 0;
            node = node->v[word[i]-'a'];
        }

        return node->cnt;
    }

    void eraseNode(TrieNode* node, TrieNode* parent, string &word, int i){
        // base case
        if(i == (int)word.size()){
            // we are at the last node
            node->terminal--;
            node->cnt--;
            if(node->cnt == 0){
                parent->v[word[i-1] - 'a'] = nullptr;
                delete node;
            }

            return;
        }

        eraseNode(node->v[word[i] - 'a'], node, word, i+1);

        // now I'll delete this one
        node->cnt--;
        if(node->cnt == 0){
            parent->v[word[i-1] - 'a'] = nullptr;
            delete node;
        }
    }
    void erase(string &word){
        int n = word.size();
        TrieNode* node = root;
        eraseNode(node->v[word[0] - 'a'], node, word, 1);
    }
};
