#include<iostream>
#include<algorithm>
#include<queue>
using namespace std;

// find kth largest sum subarray.
// https://www.naukri.com/code360/problems/k-th-largest-sum-contiguous-subarray_920398?leftPanelTab=0&utm_source=youtube&utm_medium=affiliate&utm_campaign=Lovebabbar&leftPanelTabValue=PROBLEM


// Approach 1: basic brute force
// O(n^2 * log(n^2)) && O(n^2)			 quite bad solution

int getKthLargest(vector<int> &arr, int k)
{
	vector<int> sumStore;   // made a vector to store all sum of subarrays.

	for(int i = 0; i< arr.size(); i++){
		int sum = 0;

		for (int j = i; j< arr.size(); j++){
			sum += arr[j];
			sumStore.push_back(sum);
		}
	}

	sort(sumStore.begin(), sumStore.end());        // sorting the vector. contains n^2 elements
	return sumStore[sumStore.size() - k];           // returning the kth largest element.
}


// Approach 2:
// min heap k elements ki bnao and agar sum min heap ke top se bada hua to minHeap.pop() kar dena and sum ko push.
// aisa karte karte puri array traverse kar lo last me largest "k" elements will be in the heap, return the top 
// element as it is the smallest one and hence the kth largest one.

// O(n^2 * logk) && O(logk)
int getKthLargest(vector<int> &arr, int k)
{
	// min heap approach
	priority_queue< int , vector<int> , greater<int> > pq;
	int n = arr.size();
	int count = 0; 

	for(int i = 0; i < n; i++ ){
		int sum = 0; 

		for(int j = i; j < n; j++){ 

			sum += arr[j];

            // shuru ke "k" elements daal do .
			if(count < k){
				pq.push(sum);
				count++;
			}
			else{
                // sum bada ho to pq me sum ko daal do top ko pop karke.
				if(sum > pq.top()){
					pq.pop();
					pq.push(sum);
				}
			}
		}
	}
	
	return pq.top();
}
