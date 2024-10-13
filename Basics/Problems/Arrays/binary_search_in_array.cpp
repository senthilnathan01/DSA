#include <iostream>
using namespace std;

/*
Given an array arr[] sorted in ascending order of size N and an integer K. 
Check if K is present in the array or not.
*/

// We use binary search to do this task.
// Time complexity = O(logn)

// Whereas if you use linear search the time complexity will O(n)

int binary_search(int arr[], int low, int high, int K){
    if(low<=high){
        int mid = low + (high-low)/2;
        if(K==arr[mid]){
            return 1;
        }
        else if(K<arr[mid]){
            return binary_search(arr, 0, mid-1, K);
        }
        else{
            return binary_search(arr, mid+1, high, K);
        }
    }
    return -1;
}

int main() {
    int nums[8] = {1, 2, 0, 3, 0, 4, 0, 5};
    return binary_search(nums, 0, 8, 3);
}