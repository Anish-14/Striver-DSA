#include<iostream>
#include<stack>
using namespace std;

// Merge two Binary max heap

class Solution{
    public:
    
    // heapify for 0 based indexing.
    void heapify(vector<int> &arr, int n , int i){                // array, its size ,index jisko shi jagah pahuchana hai
        int largest = i;
        int left = 2*i + 1;     // 0 based indexing
        int right = 2*i + 2;

        // check karo ki heap hai ya nhi.
        if(left < n && arr[largest] < arr[left]){

            if(right < n && arr[largest] < arr[right]){
                if(arr[left] > arr[right]){
                    largest = left;
                }
                else{;
                    largest = right;
                }
            }
            else{
                largest = left;
            }
        }
        else if(right < n && arr[largest] < arr[right]){
            largest = right;
        }

        // check ki largest change hua ya nhi, agar change hua hai then we need to update it.
        if(largest != i){
            swap(arr[largest],arr[i]);
            heapify(arr,n,largest);             // jiske saath bhi swap kiya ab apna root node waha pahoch gya hai (left ya right me) so we need to check ki vo right ya left bhi heap ho therefore largest index ko heap bnne bhej diya.
        }
    }

    vector<int> mergeHeaps(vector<int> &a, vector<int> &b, int n, int m) {
        
        // step 1: merge both arrays
        // step 2: make a heap from that array.
        
        vector<int> ans;
        
        for(int i = 0; i<n; i++){
            ans.push_back(a[i]);
        }
        for(int i = 0; i<m; i++){
            ans.push_back(b[i]);
        }
        
        for(int i = (n+m)/2 - 1; i >= 0; i--){          // 0 based indexing therefore, we started with (n+m)/2 - 1 otherwise we start with (n+m)/2  
            heapify(ans, n+m ,i);
        }
        
        return ans;
    }
};





// have a look at this approach
// from comments.

// In Question 3, Merge 2 binary max heaps, the following code is one another easy method.
// First make one vector c and push -1 inside it to make it one based indexing heap and then push all vector a elements inside it. After that put vector b elements in vector c using for loop, then this new element is transferred into its valid position according to heap using while loop.
// Time comlexity is O( (m+n)*log(n+m) ) and space complexity is O(m+n). because we are erasing one element
// if we make our solution with 0 based indexing from start then TC : O(m*log(n+m))
class Solution{
    public:
    vector<int> mergeHeaps(vector<int> &a, vector<int> &b, int n, int m) {
        vector<int>c;
        c.push_back(-1); 

        for(int i=0; i<n; i++){
            c.push_back(a[i]);
        }

        for(int i=0; i<m; i++){
            c.push_back(b[i]);
            int index = c.size()-1;
            int parent = index/2 ;
            while(index > 1 && c[parent] < c[index]){
                swap(c[parent],c[index]);
                index = parent; 
                parent = index/2;
            }
        }
      
        c.erase(c.begin());         // first element hata diya, TC : O(m+n) for this as every element has to shift one position left
        return c;
    }
};




