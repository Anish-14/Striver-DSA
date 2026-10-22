#include<iostream>
using namespace std;

// Allocate Minimum Pages
// https://www.geeksforgeeks.org/problems/allocate-minimum-number-of-pages0937/1

// This solution is quite confusing, please refer to the solution pasted below
class Solution {
  public:
    bool isPossible(vector<int> &arr, int k, long long maxPage){
        int n = arr.size();
        int stu = 1;
        long long currCnt = 0;
        for(int i = 0; i<n; i++){
            if(currCnt + arr[i] <= maxPage){
                currCnt = currCnt + arr[i];
            }
            else{
                stu++;
                currCnt = arr[i];
            }
            
            if(stu > k) return true;
        }
        
        return false;
    }
    int findPages(vector<int> &arr, int k) {
        int n = arr.size();
        
        if(k > n)   return -1;
        
        long long maxi = 0; 
        long long sum = 0;
        for(int i = 0; i<n; i++){
            maxi = max(maxi, (long long)arr[i]);
            sum += arr[i];
        }
        
        long long low = maxi, high = sum;
        while(low <= high){
            long long mid = low + (high-low)/2;
            // cout<<"low and high "<<low<<" "<<high<<endl;
            // cout<<"mid is "<<mid<<endl;
            if(isPossible(arr, k, mid)){
                // mid is too low here
                low = mid+1;
            }
            else{
                high = mid-1; 
            }
        }
        
        return low;
    }
};




// Same solution with better variable names
class Solution {
  private:
    int countStudents(const vector<int> &arr, long long maxPage) {
        int students = 1;
        long long currentPages = 0;

        for (int pages : arr) {
            if (currentPages + pages <= maxPage) {
                currentPages += pages;
            } else {
                students++;
                currentPages = pages;
            }
        }

        return students;
    }

  public:
    int findPages(vector<int> &arr, int k) {
        int n = arr.size();

        if (k > n) return -1;

        long long low = 0;
        long long high = 0;

        for (int pages : arr) {
            low = max(low, (long long)pages);
            high += pages;
        }

        while (low <= high) {
            long long mid = low + (high - low) / 2;

            if (countStudents(arr, mid) <= k) {
                // Feasible: shrink search space to left
                high = mid - 1;
            } else {
                // Infeasible: expand capacity to right
                low = mid + 1;
            }
        }

        // 'low' will point to the minimum valid capacity
        return low;
    }
};