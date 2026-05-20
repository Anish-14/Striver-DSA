#include<iostream>
using namespace std;

// Alien Dictionary
// https://www.geeksforgeeks.org/problems/alien-dictionary/1

class Solution {
  public:
    pair<char,char> dict(string s1, string s2){
        int len = min(s1.length(), s2.length());
            
        int i;
        for(i = 0; i<len; i++){
            if(s1[i] != s2[i]){
                return {s1[i], s2[i]};
            }
        }
        if(s1.length() > s2.length()){
            return {'*', '*'};
        }
        return {'#', '#'};
    }
    string findOrder(vector<string> &words) {
        vector<vector<char>> adj(26, vector<char>());
        vector<int> indegree(26, -1);
        int n = words.size();
        for(auto &word : words){
            for(char ch : word){
                indegree[ch - 'a'] = 0;
            }
        }
        for(int i = 1; i<n; i++){
            pair<char,char> p = dict(words[i-1], words[i]);
            if(p.first == '*')  return "";
            if(p.first == '#'){
                continue;
            }
            adj[p.first-'a'].push_back(p.second);
            indegree[p.first - 'a'] = 0;
            indegree[p.second - 'a'] = 0;
        }
        
        // kahn's algo
        int cnt = 0;
        for(int i = 0; i<26; i++){
            if(indegree[i] != -1)   cnt++;
            for(auto it : adj[i]){
                indegree[it - 'a']++;
            }
        }
        
        queue<char> q;
        for(int i = 0; i<26; i++){
            if(indegree[i] == 0){
                q.push(char(i+'a'));
            }
        }
        
        string ans = "";
        
        while(!q.empty()){
            char top = q.front();
            q.pop();
            ans.push_back(top);
            
            for(auto it : adj[top - 'a']){
                indegree[it - 'a']--;
                if(indegree[it - 'a'] == 0){
                    q.push(it);
                }
            }
        }
        
        
        if(ans.length() != cnt) return "";
        
        return ans;
    }
};

