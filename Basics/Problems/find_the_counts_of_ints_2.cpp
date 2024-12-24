// #include<bits/stdc++.h> or alternatively use this 
#include<iostream>
#include<map>

using namespace std;

// Problem:
// Find the number of times the numbers: 1, 4, 2, 3, 12 appear in the
// array: {1, 3, 2, 1, 3}

// Let's solve this using hashing

int main(){
    int arr[5] = {1, 3, 2, 1, 3};
    map<int, int> mpp;
    for(int i=0; i<5; i++){
        mpp[arr[i]]++;
    }

    int find_counts[5]={1, 4, 2, 3, 12};
    for(int i=0; i<5; i++){
        cout<<mpp[find_counts[i]]<<" ";
    }
    return 0;
}

// Output: 2 0 1 2 0
