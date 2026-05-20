#include<iostream>
#include<vector>
using namespace std;

// Accounts Merge
// https://leetcode.com/problems/accounts-merge/description/

// Good Question 

class Solution {
public:
    vector<int> parent, rank;

    int getParent(int a, vector<int> &parent){
        if(parent[a] == a)  return a;
        return parent[a] = getParent(parent[a], parent);
    }

    void unionByRank(int a, int b, vector<int> &parent, vector<int>&rank){
        int pa = getParent(a, parent);
        int pb = getParent(b, parent);

        if(pa == pb) return ;

        if(rank[pa] < rank[pb]){
            parent[pa] = pb;
        }
        else if(rank[pb] < rank[pa]){
            parent[pb] = pa;
        }
        else{
            parent[pb] = pa;
            rank[pa]++;
        }
    }

    vector<vector<string>> accountsMerge(vector<vector<string>>& accounts) {
        int n = accounts.size();

        parent.resize(n);
        rank.resize(n, 1);
        for(int i = 0; i<n; i++){
            parent[i] = i;
        }

        unordered_map< string, int> mp;     // mail, parentNode

        // lets create are mapping 
        for(int i = 0; i<n; i++){
            for(int j = 1; j<accounts[i].size(); j++){
                string mail = accounts[i][j];
                if(mp.find(mail) == mp.end()){
                    mp[mail] = i;
                }
                else{
                    unionByRank(i, mp[mail], parent, rank);
                }
            }
        }

        // now let's arrange the mail whose ultimate parents are same
        vector<vector<string>> mailPar(n);
        for(auto it : mp){
            string mail = it.first;
            int parIt = getParent(it.second, parent);
            mailPar[parIt].push_back(mail);
        }

        // constructing our answer from it 
        vector<vector<string>> ans;

        for(int i = 0; i<n; i++){
            if(mailPar[i].size() == 0)  continue;
            sort(mailPar[i].begin(), mailPar[i].end());
            vector<string> temp;
            temp.push_back(accounts[i][0]);
            for(auto it : mailPar[i]){
                temp.push_back(it);
            }

            ans.push_back(temp);
        }

        return ans;
    }
};









