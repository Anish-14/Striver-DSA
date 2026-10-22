#include<iostream>
#include<math.h>
#include<map>
using namespace std;

// Implementing MIN Heap 
// https://www.naukri.com/code360/problems/build-min-heap_1171167?leftPanelTab=0&utm_source=youtube&utm_medium=affiliate&utm_campaign=Lovebabbar

void heapify(vector<int> &arr, int n , int i){     // array, its size ,index jisko shi jagah pahuchana hai
    int smallest = i;
    int left = 2*i;
    int right = 2*i + 1;

    // check karo ki heap hai ya nhi.
    if(left <= n && arr[smallest] > arr[left]){
        if(right <= n && arr[smallest] > arr[right]){
            if(arr[left] < arr[right]){
                smallest = left;
            }
            else{
                smallest = right;
            }
        }
        else{
            smallest = left;
        }
    }
    else if(right <= n && arr[smallest] > arr[right]){
        smallest = right;
    }

    // check ki largest change hua ya nhi, agar change hua hai then we need to update it.
    if(smallest != i){
        swap(arr[smallest],arr[i]);
        heapify(arr,n,smallest);             // jiske saath bhi swap kiya ab apna root node waha pahoch gya hai (left ya right me) so we need to check ki vo right ya left bhi heap ho therefore largest index ko heap bnne bhej diya.
    }
}

// vector<int> buildMinHeap(vector<int> &arr)
// {
//     int n = arr.size() - 1;
//     for(int i = n/2; i>0; i--){
//         heapify(arr,n,i);
//     }

//     return arr;
// }

int main(){
    vector<int> arr;
    arr.push_back(-1);      // for one based indexing
    int a;
    cin>>a;
    while(a != -1){
        arr.push_back(a);
        cin>>a;
    }

    int n = arr.size() - 1;         // because we are ignoring the first index so size is reduced by 1

    for(int i = 1; i<=n; i++){
        cout<<arr[i]<<" ";
    }cout<<endl;

    
    cout<<"value of n: "<<n<<endl;
    for(int i = n/2; i>0; i--){
        heapify(arr,n,i);
    }

    for(int i = 1; i<=n; i++){
        cout<<arr[i]<<" ";
    }cout<<endl;
}