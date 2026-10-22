#include<iostream>
using namespace std;

// Minimize Max Distance of Adjacent Gas Stations
// https://www.geeksforgeeks.org/problems/minimize-max-distance-to-gas-station/1

// Three Aproaches --> 

// 1. 
// Select which is the largest partition and decide to put something there - will give you TLE though
class Solution {
  public:
    double minMaxDist(vector<int> &arr, int k) {
        int n = arr.size();
        if(n == 1)  return 0.0;
        
        vector<int> howMany(n-1, 0);
        
        // we're trying to figure out how much gas stations between
        // a particular partition should we put
        for(int gasStation = 1; gasStation <= k; gasStation++){
            long double maxSection = -1;
            int maxInd = -1;
            for(int i = 0; i<n-1; i++){
                long double diff = arr[i+1]-arr[i];
                long double sectionLen = diff/(howMany[i]+1);
                if(sectionLen > maxSection){
                    maxSection = sectionLen;
                    maxInd = i;
                }
            }
            howMany[maxInd]++;
        }
        
        // calculate the ans
        long double maxAns = -1;
        for(int i = 0; i<n-1; i++){
            long double diff = (arr[i+1]-arr[i]);
            long double sectionLen = diff/(howMany[i]+1);
            
            maxAns = max(maxAns, sectionLen);
        }
        
        return maxAns;
    }
};


// 2. 
// Same approach just using heap to optimise the inner loop in the above approach
// TC : O(NlogN + KlogN) this is acceptable
class Solution {
  public:
    double minMaxDist(vector<int> &arr, int k) {
        int n = arr.size();
        if(n == 1)  return 0.0;
        
        vector<int> howMany(n-1, 0);
        
        priority_queue<pair<long double,int>> pq;
        
        for(int i = 0; i<n-1; i++){
            pq.push({arr[i+1] - arr[i], i});
        }
    
        for(int gasStation = 1; gasStation <= k; gasStation++){
            auto tp = pq.top();
            pq.pop();
            
            int secInd = tp.second;
            howMany[secInd]++;
            
            long double iniDiff = arr[secInd+1] - arr[secInd];
            long double newSecLen = iniDiff/(howMany[secInd]+1);
            
            pq.push({newSecLen, secInd});
        }
        
        return pq.top().first;
    }
};

// 3. 
// Binary Search Approach
// from the above one we're optimising on the extra space, we're not using any space here
class Solution {
  public:
    int numberOfGasStationsRequired(long double dist, vector<int> &arr) {
        int cnt = 0;
        for (int i = 1; i < arr.size(); i++) {
            int numberInBetween = ((arr[i] - arr[i - 1]) / dist);
            // pure division check
            if ((arr[i] - arr[i - 1]) == numberInBetween * dist) {
                numberInBetween--;
            }
            cnt += numberInBetween;
        }
        return cnt;
    }

    double minMaxDist(vector<int> &arr, int k) {
        int n = arr.size();
        long double low = 0;
        long double high = 0;

        for (int i = 0; i < n - 1; i++) {
            high = max(high, (long double)(arr[i + 1] - arr[i]));
        }

        long double diff = 1e-6;
        while (high - low > diff) {
            long double mid = (low + high) / (2.0);
            int cnt = numberOfGasStationsRequired(mid, arr);
            if (cnt > k) {
                low = mid;
            } 
            else {
                high = mid;
            }
        }

        return high;
    }
};