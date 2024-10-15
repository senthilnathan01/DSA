#include <iostream>
#include<vector>

using namespace std;

/*
Given a sorted array Arr of size N and a number X, you need to find the number of occurrences of X in Arr.
*/

int count(int arr[], int n, int x) {
    int low = 0;
    int high = n-1;
    int startingPosition = -1;
    int endingPosition = -1;
    
    // Find the starting position
    while(low<=high){
        int mid = low + (high-low)/2;
        if(arr[mid]<x) low = mid +1;
        else high = mid -1;
    }
    if(low<n && arr[low]==x) startingPosition = low;
    
    if(startingPosition != -1){
        // Find the ending position if the element is in the array
        low = 0;
        high = n-1;
        while(low<=high){
            int mid = low + (high-low)/2;
            if(arr[mid]<x+1) low = mid +1;
            else high = mid -1;
        }
        endingPosition = low -1; 
        
        // count = (endingPosition - startingPosition)+1 
        return (endingPosition - startingPosition)+1; 
    }
    
    return 0;
}

int main() {
    int v[7] = {1,2,3,5,5,5,6};
    cout<<count(v, 7, 1);

    return 0;
}

// OUTPUT:
// 3