#include<iostream>
using namespace std;

void merge(int arr[],int s,int e){
    int mid = (s+e)/2;

    int len1 = mid-s+1;
    int len2 = e - mid;

    int first[len1];
    int second[len2];

    //copy values
    int mainarrayindex = s;
    for(int i = 0; i<len1; i++){
        first[i] = arr[mainarrayindex++];
    }

    mainarrayindex = mid+1;
    for(int i = 0; i<len2; i++){
        second[i] = arr[mainarrayindex++] ;
    }

    //merge two sorted arrays.
    int index1 = 0;
    int index2 = 0;
    mainarrayindex = s;

    while(index1<len1 && index2<len2)
    {
        if(first[index1] < second[index2])
            arr[mainarrayindex++] = first[index1++]; 

        else
            arr[mainarrayindex++] = second[index2++];
    }

    while(index1<len1)
    {
        arr[mainarrayindex++] = first[index1++]; 
    }

    while(index1<len2)
    {
        arr[mainarrayindex++] = second[index2++]; 
    }
}

void mergesort(int arr[],int s,int e){
    if(s >= e){
        return ;
    }

    cout<<"recursion is called"<<endl;

    int mid = (s+e)/2;

    mergesort(arr,s,mid); // left wala sort karo

    mergesort(arr,mid+1,e); // right wala sort karo

    merge(arr,s,e);
}



int main(){
    int arr[9] = {3,7,2,89,56,76,43,32,3};
    mergesort(arr,0,8);

    for(int i = 0; i<9; i++)
    {
        cout<<arr[i]<<" ";
    }

}