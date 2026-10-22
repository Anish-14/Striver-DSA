#include<iostream>
using namespace std;

// TC O(n^2) in worst case and O(n) for best case
// in this method hum sabse bade waale ko last me leke jaate hai
// stable algo

void bubblesort(int arr[],int n){
    for(int i = 1; i<n; i++){
       //for round 1 to n-1
       bool swapped = false;

       for(int j = 0; j<n-i; j++){
            //process element till n-i th index.
            if(arr[j] > arr[j+1]){
                swap(arr[j],arr[j+1]);
                swapped = true;
            }
       }

       if(swapped == false){
            // already sorted
            break;
       }
    }
}  

int main(){
    int arr[5] = {1,5,3,4,2};
    bubblesort(arr, 5);

    for(int i =0; i<5; i++){
        cout<<arr[i]<<" ";
    }
}