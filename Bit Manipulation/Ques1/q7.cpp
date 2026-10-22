#include<iostream>
using namespace std;

// xor of numbers from 1 to n

// basic method
int calcXOR_BASIC(int n){
    int ans = 0;
    for(int i = 1; i<=n; i++){
        ans = ans^i;
    }

    return ans;
}

// Observing the pattern
int calcXOR(int n){
    if(n%4 == 0)         return n;
    else if(n%4 == 1)    return 1;
    else if(n%4 == 2)    return n+1;
    else                 return 0;
}

// for a range question (L->R)
int rangeXOR(int l, int r){
    int R = calcXOR(r);
    int L = calcXOR(l-1);

    return L^R;
}

