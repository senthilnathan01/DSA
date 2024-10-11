#include<iostream>
using namespace std;

// Problem:
// Find the number of times the numbers: 1, 4, 2, 3, 12 appear in the
// array: {1, 3, 2, 1, 3}

// Brute Force Approach:
// We can use a for loop to find the number of times each of the given numbers appear in the array
// But in this approach the time complexity is too huge

// For a much better time complexity, we use hashing

int main(){
    // Since the maximum of among the given query is 12, it is sufficient to store
    // the counts of the number till 12
    int hash[13]={0};
    int arr[5] = {1, 3, 2, 1, 3};

    int findcounts[5] = {1, 4, 2, 3, 12};

    for(int i=0; i<5; i++){
        hash[arr[i]]+=1;
    }
    for(int i=0; i<5; i++){
        cout<<hash[findcounts[i]]<<" ";
    }
    return 0;
}

// Output: 2 0 1 2 0