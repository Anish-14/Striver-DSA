#include<iostream>
#include<unordered_set> 
using namespace std;

// word ladder 2
// https://leetcode.com/problems/word-ladder-ii/description/

// Very good problem


// MY method with help of gemini
// Using BFS (Not Optimal, will give MLE)
class Solution {
public:
    bool isValid(const string& a, const string& b) {
        int differ = 0;
        for (int i = 0; i < a.length(); i++) {
            if (a[i] != b[i]) {
                if (++differ > 1) return false;
            }
        }
        return differ == 1;
    }

    vector<vector<string>> findLadders(string beginWord, string endWord, vector<string>& wordList) {
        wordList.insert(wordList.begin(), beginWord);

        int n = wordList.size();
        vector<vector<int>> adj(n);
        for (int i = 0; i < n; i++) {
            for (int j = i + 1; j < n; j++) {
                if (isValid(wordList[i], wordList[j])) {
                    adj[i].push_back(j);
                    adj[j].push_back(i);
                }
            }
        }

        int target = -1;
        for (int i = 0; i < n; i++) {
            if (wordList[i] == endWord) {
                target = i;
                break;
            }
        }
        if (target == -1) return {};

        vector<int> dis(n, -1);
        queue<pair<int, vector<int>>> q;

        q.push({0, {0}});
        dis[0] = 0;

        vector<vector<int>> ans;
        int shortest = -1;

        while (!q.empty()) {
            auto [top, history] = q.front();
            q.pop();

            // Stop expanding if we've already exceeded the shortest path found
            if (shortest != -1 && dis[top] >= shortest) break;

            for (int it : adj[top]) {
                // Allow visiting if unvisited OR if discovered at the exact same level
                if (dis[it] == -1 || dis[it] == dis[top] + 1) {
                    dis[it] = dis[top] + 1;

                    history.push_back(it);

                    if (it == target) {
                        if (shortest == -1 || dis[it] == shortest) {
                            shortest = dis[it];
                            ans.push_back(history);
                        }
                    } 
                    else {
                        q.push({it, history});
                    }

                    history.pop_back();
                }
            }
        }

        vector<vector<string>> res;
        for (const auto& path : ans) {
            vector<string> temp;
            temp.reserve(path.size());
            for (int idx : path) temp.push_back(wordList[idx]);
            res.push_back(temp);
        }

        return res;
    }
};



// Striver Method (Not Optimal)
class Solution {
public:
    vector<vector<string>> findLadders(string beginWord, string endWord, vector<string>& wordList) {
        unordered_set<string> st(wordList.begin(), wordList.end());
        queue<vector<string>> q;
        q.push({beginWord});
        vector<string> usedOnLevel;
        usedOnLevel.push_back(beginWord);
        int level = 0;
        vector<vector<string>> ans;

        while(!q.empty()){
            auto vec = q.front();
            q.pop();

            // erase all the words which has been used at previous level
            if(vec.size() > level){
                level++;
                for(auto it : usedOnLevel){
                    st.erase(it);
                }
            }

            // newly added word is always on the back 
            string word = vec.back();

            // store the ans
            if(word == endWord){
                if(ans.size() == 0){
                    ans.push_back(vec);
                }
                else if(ans[0].size() == vec.size()){
                    ans.push_back(vec);
                }
            }


            for(int i = 0; i<word.size(); i++){
                char original = word[i];
                for(int ch = 'a'; ch<='z'; ch++){
                    word[i] = ch; 
                    if(st.count(word) > 0){
                        vec.push_back(word);
                        q.push(vec);
                        // mark that we're taking this word
                        usedOnLevel.push_back(word);
                        vec.pop_back();
                    }
                }
                word[i] = original;
            }
        }

        return ans;
    }
};




// Striver Method (Optimal, CP method)

// we'll assign levels to each word while reaching the endWord because we can't reach endWord in shortest
// path having two levels for a word that is coming in the path
// then we'll traverse from the back to don't explore unnecessary paths and waste our time there
// this way we can find the answer without TLE or MLE


class Solution {
private: 
    unordered_map<string, int> mpp;
    vector<vector<string>> ans;
    string b;

    void dfs(string word, vector<string> &seq){
        // save the answer if you reach to the begin Node
        if(word == b){
            reverse(seq.begin(), seq.end());
            ans.push_back(seq);
            reverse(seq.begin(), seq.end());
            return;
        }

        int steps = mpp[word];
        int sz = word.size();
        for(int i = 0; i<sz; i++){
            char original = word[i];
            for(char ch = 'a'; ch<='z'; ch++){
                word[i] = ch;
                if(mpp.find(word) != mpp.end() && mpp[word] + 1 == steps){
                    seq.push_back(word);
                    dfs(word, seq);
                    seq.pop_back();
                }
            }
            word[i] = original;
        }

    }
public:
    vector<vector<string>> findLadders(string beginWord, string endWord, vector<string>& wordList) {
        unordered_set<string> st(wordList.begin(), wordList.end());
        queue<string> q;
        b = beginWord;
        q.push({beginWord});
        mpp[beginWord] = 1;         // this is storing the level of each word for the shortest path
        int sz = beginWord.size();
        st.erase(beginWord);

        while(!q.empty()){
            string word = q.front();
            int steps = mpp[word];
            q.pop();

            if(word == endWord) break;

            for(int i = 0; i<sz; i++){
                char original = word[i];
                for(char ch = 'a'; ch<='z'; ch++){
                    word[i] = ch;
                    if(st.find(word) != st.end()){
                        q.push(word);
                        st.erase(word);
                        mpp[word] = steps + 1;
                    }
                }
                word[i] = original;
            }
        }

        if(mpp.count(endWord)){
            vector<string> seq;
            seq.push_back(endWord);
            dfs(endWord, seq);
        }

        return ans;
    }
};
