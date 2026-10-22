#include<iostream>
using namespace std;

// TC - O(n^2) for worst case and O(n) for best case

void insertionsort(int arr[],int n){
    for(int i = 1; i<n; i++){      
        int temp = arr[i];       // save the current number jisko aapko pahuchana hai at its current right location.
        int j = i-1;             // we've declared it outside because we need it outside the for loop.
        // uske ek pichhle se shuru karo and go till the first element of the array.
        for(; j>=0; j--){
            if(arr[j]>temp){
                // shift the element towards right
                arr[j+1] = arr[j];
            }
            else // ruk jao
            {
                break;
            }
        }
        // we've reached the location where we want to insert it, and that index will be "j+1"
        arr[j+1] = temp;
    }
}  


// Why should we use this algo?

// Adaptable algo - less comparison inside the array with different elements.
// Stable algo 
// useful when used on small sized array and array which is partially sorted.
