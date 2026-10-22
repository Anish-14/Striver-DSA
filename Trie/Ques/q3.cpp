 #include<iostream>
using namespace std;

// Complete String
// https://www.naukri.com/code360/problems/complete-string_2687860?leftPanelTabValue=PROBLEM


class TrieNode{
public:
    vector<TrieNode*> v;
    bool terminal;

    TrieNode(){
        this->v = vector<TrieNode*> (26, nullptr);
        this->terminal = 0;
    }
};

void insert(TrieNode* root, string &word){
    int n = word.size();
    TrieNode* node = root;
    for(int i = 0; i<n; i++){
        if(node->v[word[i]-'a'] == nullptr){
            node->v[word[i] - 'a'] = new TrieNode();
        }
        node = node->v[word[i]-'a'];
    }

    node->terminal = 1;
}

string findAns(TrieNode* root){
    string ans = "";
    for(int i = 0; i<26; i++){
        string temp = "";
        if(root->v[i] != nullptr && root->v[i]->terminal){
            temp.push_back((char)('a' + i));
            temp += findAns(root->v[i]);
        }
        if(temp.size() > ans.size()){
            ans = temp;
        }
    }

    return ans;
}

string completeString(int n, vector<string> &a){
    TrieNode* root = new TrieNode();
    for(int i = 0; i<a.size(); i++){
        insert(root, a[i]);
    }

    string ans = findAns(root);

    if(ans == ""){
        return "None";
    }
    return ans;
}
