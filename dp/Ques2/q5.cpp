#include<iostream>
#include<unordered_set>
#include<numeric>
using namespace std;

// https://leetcode.com/problems/partition-array-into-two-arrays-to-minimize-sum-difference/
// Partition Array Into Two Arrays to Minimize Sum Difference
// do check and understand the binary search approach of this problem

// Recursion 
class Solution {
public: 
    int totalSum = 0;
    int n;
    int solve(int index, vector<int>&nums, int cnt, int sum){
        if(cnt == n/2){
            return abs(totalSum - 2*sum);
        }  
        if(index < 0)   return 1e9;

        // notTake 
        int notTake = solve(index-1, nums, cnt, sum);
        // take
        int take = solve(index-1, nums, cnt+1, sum + nums[index]);
        return min(notTake , take);
    }
    int minimumDifference(vector<int>& nums) {
        n = nums.size();
        for(int i =0; i<n; i++){
            totalSum += nums[i];
        }

        return  solve(n-1, nums, 0, 0);
    }
};


// Memoization 
class Solution {
public: 
    int totalSum = 0;
    int n;
    unordered_map<long long , int> dp;      // long long will store the variation of index, cnt and sum and int will store the difference

    // we made our dp this way because the sum can go upto TotalSum in this case and it is a very large value which is more than the vector
    // length itself so we cannot store there and as almost 95% space will go unused and we only need 5% of the space in that that's why we can 
    // think of using map instead of vectore here. And we are helpless as well as we cannot make a vector in this case
    long long getKey(int index, int cnt, int sum){
        return ((long long)index << 42 | (long long) cnt << 32 | (long long) sum);      // we did this so that these variables don't overlap themselves
    }
    int solve(int index, vector<int>&nums, int cnt, int sum, unordered_map<long long,int> &dp){
        if(cnt == n/2){
            return abs(totalSum - 2*sum);
        }  
        if(index < 0)   return 1e9;

        // this is our dp[index][cnt][sum] != -1 then reuturn the value thing 
        long long key = getKey(index, cnt, sum);    // we hashed these three variables
        auto it = dp.find(key);
        if(it != dp.end()) return it->second;

        // notTake 
        int notTake = solve(index-1, nums, cnt, sum, dp);
        // take
        int take = solve(index-1, nums, cnt+1, sum + nums[index], dp);

        return dp[key] = min(notTake , take);
    }
    int minimumDifference(vector<int>& nums) {
        n = nums.size();
        for(int i =0; i<n; i++){
            totalSum += nums[i];
        }

        dp.clear();
        return  solve(n-1, nums, 0, 0, dp);
    }
};


// Tabulation 
class Solution {
public:
    int minimumDifference(vector<int>& nums) {
        int n = nums.size();
        int half = n / 2;
        int totalSum = 0;
        for (int x : nums) totalSum += x;

        // dp[k] = unordered_set of achievable sums using exactly k elements
        vector<unordered_set<int>> dp(half + 1);
        dp[0].insert(0);

        for (int num : nums) {
            // update counts from high to low to avoid reusing same element
            for (int k = min(half, (int)dp.size() - 1); k >= 1; --k) {
                // we iterate over a snapshot of dp[k-1]
                vector<int> add;
                add.reserve(dp[k-1].size());
                for (int s : dp[k-1]) add.push_back(s + num);
                for (int ns : add) dp[k].insert(ns);
            }
        }

        int ans = INT_MAX;
        for (int s : dp[half]) {
            int diff = abs(totalSum - 2 * s);
            if (diff < ans) ans = diff;
        }
        return ans;
    }
};


// the best solution which will not give tle
// please understand it when you get time as it is important
// https://leetcode.com/problems/partition-array-into-two-arrays-to-minimize-sum-difference/solutions/2721045/best-solution-tabulation-failed-full-exp-y941/

class Solution {
public:
int minimumDifference(vector<int>& nums) {
    int n = nums.size(),  sum = 0;
    sum = accumulate(nums.begin(), nums.end(),0);  // To find the total sum of the array 
    
    int N = n/2; // Divide it into two equals parts as length is even
    vector<vector<int>> left(N+1), right(N+1); // left array and right array
    
	//All possible sum in left and right part (Generating and storing using BIT-Masking)
    for(int mask = 0; mask<(1<<N); ++mask){  // (1<<n) means 2^n i.e we'll iterate through 0 to 2^n
        int idx = 0, l_sum = 0, r_sum = 0;
        for(int i=0; i<N; ++i){
            if(mask&(1<<i)){  // To check if the bit is set or not 
                idx++;
                l_sum += nums[i];
                r_sum += nums[i+N];
            }
        }
        left[idx].push_back(l_sum);
        right[idx].push_back(r_sum);   // storing
    }

    for(int idx=0; idx<=N; ++idx){
        sort(right[idx].begin(), right[idx].end());   // as we'll perform binary search on right so we have to sort it first
    }

 int res = min(abs(sum-2*left[N][0]), abs(sum-2*right[N][0]));  // To get the minimum answer from the max sum from both array
		//iterating over left part
		for(int idx=1; idx<N; ++idx){ // iterate from 1 so we dont have to include 0 and check for all value except last as we have alr considered it
			for(auto &a : left[idx]){ // check the sum at each number position
				int b = (sum - 2*a)/2; // find the value to be minimized 
				int rightidx = N-idx; // find the number value in right array
				auto &v = right[rightidx]; // store the vector in v at right number position
				auto itr = lower_bound(v.begin(), v.end(),b); //binary search over right part

				if(itr!=v.end()) res = min(res, abs(sum-2*(a+(*itr)))); // if found in vector then only update otherwise continue

				}                
			}
		return res;

	}
};


// The binary search method
class Solution {
public:
    int minimumDifference(vector<int>& nums) {
        int n = nums.size(), sum = 0;
        sum = accumulate(nums.begin(), nums.end(), 0); // To find the total sum of the array 
        
        int N = n / 2; // Divide it into two equals parts as length is even
        vector<vector<int>> left(N + 1), right(N + 1); // left array and right array
        
        // All possible sum in left and right part (Generating and storing using BIT-Masking)
        for (int mask = 0; mask < (1 << N); ++mask) { // (1<<n) means 2^n i.e we'll iterate through 0 to 2^n
            int idx = 0, l_sum = 0, r_sum = 0;
            for (int i = 0; i < N; ++i) {
                if (mask & (1 << i)) { // To check if the bit is set or not 
                    idx++;
                    l_sum += nums[i];
                    r_sum += nums[i + N];
                }
            }
            left[idx].push_back(l_sum);
            right[idx].push_back(r_sum); // storing
        }

        for (int idx = 0; idx <= N; ++idx) {
            sort(right[idx].begin(), right[idx].end()); // as we'll perform binary search on right so we have to sort it first
        }

        int res = min(abs(sum - 2 * left[N][0]), abs(sum - 2 * right[N][0])); // To get the minimum answer from the max sum from both array

        // iterating over left part
        for (int idx = 1; idx < N; ++idx) { // iterate from 1 so we dont have to include 0 and check for all value except last as we have alr considered it
            for (auto &a : left[idx]) { // check the sum at each number position
                int b = (sum - 2 * a) / 2; // find the value to be minimized 
                int rightidx = N - idx; // find the number value in right array
                auto &v = right[rightidx]; // store the vector in v at right number position
                
                auto itr = lower_bound(v.begin(), v.end(), b); // binary search over right part

                // 1. Check the value found by lower_bound (value >= b)
                if (itr != v.end()) {
                    res = min(res, abs(sum - 2 * (a + (*itr))));
                }
                
                // 2. Check the value immediately BEFORE the lower_bound (value < b)
                // We can only look back if itr is not at the very beginning
                if (itr != v.begin()) {
                    auto prev_itr = itr - 1; // Or prev(itr)
                    res = min(res, abs(sum - 2 * (a + (*prev_itr))));
                }
            }                
        }
        return res;
    }
};

