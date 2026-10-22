#include<iostream>
using namespace std;

int partition(int arr[],int s, int e){
    int pivot = arr[s];             // select the pivoting element which you want to move to its original position.

    int count = 0;

    for(int i = s+1; i<=e; i++)     // count numbers which are less than pivot.
    {
        if(arr[i]<pivot)
        {
            count++;
        }
    }

    int pivotIndex = s + count;     // select the pivotIndex to move the pivot element there.
    swap(arr[pivotIndex],arr[s]);   // swap it

    int i = s ,j = e;

    while(i<pivotIndex && j>pivotIndex)         // make sure that on the left side of pivot element
    {                                           // all elements are less than pivot
        while(arr[i]<=pivot)                    // and on right side  of the element all element are    
        {                                       // greater than pivot
            i++;
        }

        while(arr[j]>pivot){
            j--;
        }

        if(i<pivotIndex && j>pivotIndex){
            swap(arr[i],arr[j]);
        }  
    }
    return pivotIndex;
}

void quicksort(int arr[], int s, int e)
{
    // base case
    if(s>=e){
        return;
    }

    // partition karenge
    int p = partition(arr,s,e);

    // left part ko sort karo
    quicksort(arr,s,p-1);

    // right wala part sort karo
    quicksort(arr,p+1,e);
}

int main()
{
    int arr[9] = {5,3,97,88,2,2,2,2,2};
    int n = 9;

    quicksort(arr,0,n-1);

    for(int i = 0; i<n; i++)
    {
        cout<<arr[i]<<" ";
    }
    cout<<endl;

}