#include<iostream>
using namespace std;

// TC = O(n^2)  in both worst and best case.

void selectionsort(int arr[],int n){
    for(int i = 0; i<n-1; i++){
       int  minindex = i; 

        for(int j = i+1; j<n; j++){
            if(arr[j] < arr[minindex]){
                minindex = j;
            }
        }

       swap(arr[minindex],arr[i]);

    }
}  

// when to use this algo??
// when the size of ther array is quite small you can consider this algo.
