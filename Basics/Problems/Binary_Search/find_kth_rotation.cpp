#include <iostream>
#include<vector>
#include<algorithm>

using namespace std;

/*
Given an increasing sorted rotated array arr of distinct integers. The array is right-rotated k times. Find the value of k.
Let's suppose we have an array arr = [2, 4, 6, 9], so if we rotate it by 2 times so that it will look like this:
After 1st Rotation : [9, 2, 4, 6]
After 2nd Rotation : [6, 9, 2, 4]
*/
// Approach 1: Linear Search
// TC = O(n)

int findKRotation1(vector<int> &arr) {
    // Iterate through the array to find the first element that is smaller than the previous element.
    for(int i=0; i<arr.size()-1; i++){
        if(arr[i]>arr[i+1]) return i+1;
    }
    // If the array is already sorted in ascending order, the rotation count is 0.
    return 0;
}

// Approach 2: Binary Search
// TC = O(logn)

int findKRotation2(vector<int> &arr){
    // We need to find the index of the smallest element in the array to get K
    // Using binary search we can do that conveniently as the array is has distinct integers only 
    int low = 0;
    int size = arr.size()-1;
    int high = size-1;

    while(low<=high){
        int mid = low + (high - low)/2;
        // Check for reversal or alternatively
        // Check for the minimum element
        if(mid<size-1 && arr[mid]>arr[mid+1]) return mid+1;
        else if(mid>0 && arr[mid-1]>arr[mid]) return mid;
        else if(arr[low]<=arr[mid]) //Smallest integer is in the right part
        {
            low = mid + 1;
        }
        else //Smallest integer is in the left part
        {
            high = mid - 1;
        }
    }   
    // Only possible answer if the smallest integer is not found in the above process is 0
    return 0;
}

int main() {
    vector<int> arr = {5, 1, 2, 3, 4};
    cout<<findKRotation1(arr)<<endl;
    cout<<findKRotation2(arr)<<endl;
    return 0;
}

// OUTPUT:
// 1

// INPUT:
// 3,4,5,1,2
// 5

// low = 1
// mid = 1
