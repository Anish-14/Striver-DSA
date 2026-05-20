#include<iostream>
using namespace std;

// word ladder 2
// https://leetcode.com/problems/word-ladder-ii/description/


// MY method
// Using BFS (Not Optimal, will give MLE)
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
    vector<vector<string>> findLadders(string beginWord, string endWord, vector<string>& wordList) {
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
            return {};
        }

        vector<int> vis(n);
        vector<int> dis(n);
        queue<pair<int, vector<int> > > q;
        q.push({0, {0}});
        vis[0] = 1;
        vector<vector<int>> ans;
        int shortest = -1;

        while(!q.empty()){
            int top = q.front().first;
            vector<int> history = q.front().second;
            q.pop();
            
            for(auto it : adj[top]){
                if(dis[it] == 0 || dis[it] == dis[top] + 1){
                    if(it == target){
                        if(shortest == -1){
                            shortest = dis[top] + 1;
                            history.push_back(it);
                            ans.push_back(history);
                            history.pop_back();
                        }
                        else if(dis[top] + 1 == shortest){
                            history.push_back(it);
                            ans.push_back(history);
                            history.pop_back();
                        }
                        continue;
                    }

                    // vis[it] = 1;
                    history.push_back(it);
                    dis[it] = dis[top] + 1;
                    q.push({it, history});
                    history.pop_back();
                }
            }
        }

        vector<vector<string>> res(ans.size());
        for(int i = 0; i<ans.size(); i++){
            for(auto it : ans[i]){
                res[i].push_back(wordList[it]);
            }
        }

        return res;
    }
};



// Striver Method (Not Optimal)
















// Striver Method (Optimal, CP method)


