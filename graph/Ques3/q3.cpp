#include<iostream>
using namespace std;

// Word Ladder
// https://leetcode.com/problems/word-ladder/description/


class Solution {
public:
    bool isValid(string a, string b){
        int differ = 0;
        for(int i = 0; i<a.length(); i++){
            if(a[i] != b[i]){
                if(differ == 1) return false;
                differ++;
            }
        }
        return true;
    }

    int ladderLength(string beginWord, string endWord, vector<string>& wordList) {
        wordList.insert(wordList.begin(), beginWord);

        int n = wordList.size();
        vector<vector<int>> adj(n, vector<int>());
        for(int i = 0; i<n; i++){
            for(int j = i+1; j<n; j++){
                if(isValid(wordList[i], wordList[j])){
                    adj[i].push_back(j);
                    adj[j].push_back(i);
                }
            }
        }

        // scr --> 0, target --> n-1  
        int target = -1;
        for(int i = 0; i<n; i++){
            if(wordList[i] == endWord){
                target = i;
            }
        }
        if(target == -1){
            return 0;
        }

        vector<int> vis(n);
        vector<int> dis(n);
        queue<int> q;
        q.push(0);
        vis[0] = 1;

        while(!q.empty()){
            int top = q.front();
            q.pop();

            for(auto it : adj[top]){
                if(!vis[it]){
                    vis[it] = 1;
                    if(it == target){
                        return dis[top] + 1 + 1;
                    }
                    q.push(it);
                    dis[it] = dis[top] + 1;
                }
            }
        }

        return 0;
    }
};


