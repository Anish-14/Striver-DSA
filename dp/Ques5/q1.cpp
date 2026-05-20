#include<iostream>
using namespace std;

// Printing the longest increasing subsequence
// https://www.geeksforgeeks.org/problems/printing-longest-increasing-subsequence/1
// striver lecture 42

// this way we can also get the length of the LIS (Obviously)
class Solution {
  public:
    vector<int> getLIS(vector<int>& arr) {
        // Code here
        int n = arr.size();
        vector<int> length(n , 1), index(n);        // this length is kind of a dp vector
        int maxi = 1;       // will store the maximum length
        int maxIndex = 0;   // index of that number where the maximum LIS ends
        for(int i = 0; i<arr.size(); i++){
            index[i] = i;
            for(int j = 0; j<i; j++){       // we'll ask everyone before us that hey! are you smaller than me, if you are then I can make a LIS with you
                if(arr[i] > arr[j] && 1 + length[j] > length[i]){   // if smaller ask the smaller one what's the length you can make and then say that I can get added to you and make it one more.
                    length[i] = 1 + length[j];
                    index[i] = j;                               // we are storing the index of the previous index with which we are making LIS so that when time comes we can print it by backtracking the indices.
                }
            }
            
            if(length[i] > maxi){
                maxi = length[i];
                maxIndex = i;
            }
        }
        
        // now we will save our answer
        vector<int> ans;
        ans.push_back(arr[maxIndex]);   
        
        while(index[maxIndex] != maxIndex){
            maxIndex = index[maxIndex];
            ans.push_back(arr[maxIndex]);
        }
        // we stored the numbers in reverse order therefore we need to reverse it before submitting it.
        reverse(ans.begin(), ans.end());
        
        return ans;
    }
};

