#include<iostream>
using namespace std;

// Binary number conversion
vector<int> binary(int num){
    vector<int> ans;
    while(num){
        ans.push_back(num%2);
        num = num/2;
    }

    reverse(ans.begin(), ans.end());
    return ans;
}

// left shift and right shift
// x>>k --> x/(2^k) && x << k --> x*(2^k)
// 1's compliment --> flip the bits (~)
// 2's compliment --> flitp the bits and then add 1 (~ + 1)
// -i is stored as 2's compliment of i in the bit internally
// NOT operator(!) of a number --> Flip it --> Positive ? keep as it is : take 2's compliment leaving the 32nd bit


// Swap two numbers --> 
void swap(int &a, int &b){
    a = a^b;
    b = a^b;
    a = a^b;
}

// check if ith bit is set or not
bool check(int num, int i){
    // using left shift;
    return (num & (1<<i));

    // using right shift
    if((num>>i)&1){
        return false;
    }
    else{
        return true;
    }
}

// set the ith bit
void setBit(int &num, int i){
    num = num | (1 << i); 
}

// clear the ith bit
void clearBit(int &num, int i){
    num = num & (~(1<<i));
}

// Toggle the ith bit --> 1->0 && 0->1
void toggle(int &num, int i){
    num = num ^ (1<<i);
}

// Remove the last(right) set bit
void removeLastSetBit(int num, int i){
    num = num & (num-1);
}

// check if a number is power of 2
bool isPower2(int num){
    // it'll only have 1 set bit if it is a power of 2
    if(num & (num-1) == 0)  return true;
    return false;
}

// count number of set bits
int cntSetBits(unsigned int num){
    int cnt = 0;
    while(num){
        cnt += num&1;
        num = num>>1;
    }

    return cnt;
}

// faster method because we're removing 1 set bit at a time instead of checking every bit
int cntSetBits(unsigned int num) {
    int cnt = 0;
    while (num) {
        num = num & (num - 1); // Clears the lowest set bit
        cnt++;
    }
    return cnt;
}