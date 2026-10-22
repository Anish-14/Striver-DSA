#include<iostream>
using namespace std;

// Count Distinct Substrings
// https://www.geeksforgeeks.org/problems/count-of-distinct-substrings/1

class Node{
public:
    vector<Node*> v;
    // bool terminal;   // we don't need a terminal node here
    
    Node(){
        this->v = vector<Node*>(26, nullptr);
    }
};
class Solution {
  public:
    void insert(Node* root, char ch){
        if(root->v[ch-'a'] == nullptr){
            root->v[ch-'a'] = new Node();
        }
        
        return;
    }
    
    int countSubs(string& s) {
        int n = s.size();
        Node* root = new Node();
        
        // insert all the substr in O(n^2)
        int cnt = 0;
        for(int i = 0; i<n; i++){
            Node* node = root;
            for(int j = i; j<n; j++){
                if(node->v[s[j]-'a'] == nullptr){
                    // every new node is our answer
                    cnt++;
                    insert(node, s[j]);
                }
                
                node = node->v[s[j]-'a'];
            }
        }
        
        return cnt;       // +1 for empty substr if needed
    }
};
