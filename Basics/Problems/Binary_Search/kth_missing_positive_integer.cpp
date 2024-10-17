#include <iostream>
#include<vector>

using namespace std;

/*
Given an array arr of positive integers sorted in a strictly increasing order, and an integer k.

Return the kth positive integer that is missing from this array.
*/

// Approach 1:
// TC = O(n)

int findKthPositive1(vector<int>& arr, int k) {
    int i = 1;  // Current positive integer
    int j = 0;  // Index in the array
    int size = arr.size();

    // Iterate through the array and count missing numbers.
    while (k > 0 && j < size) {
        if (i != arr[j]) {
            k--; // Increment the count of missing numbers
        } else {
            j++; // Move to the next element in the array
        }
        i++; // Increment the current positive integer
    }

    // If k is still greater than 0, the missing number is after the last element in the array.
    if (k > 0) {
        return arr[size - 1] + k;
    }

    // Otherwise, the missing number is the last processed integer.
    return i - 1;
}

// Approach 2: Using binary Search
// TC = log(n)

int findKthPositive2(vector<int>& arr, int k){
    if(arr[0]>k) return k;

    int low = 0;
    int size = arr.size();
    int high = size - 1;
    int mid;

    while(low<=high){
        mid = low + (high - low)/2;
        int missing_count = arr[mid] - (mid+1);
        if(missing_count < k) low = mid + 1; // Kth missing element is in the right side
        else high = mid - 1; // Else it is in the left side 
    }
    // After the loop the arr[low] will have atleast k missing elements before it
    // kth missing element = arr[low - 1] + no of missing elements after it
    // = arr[low - 1] + (k - (arr[low-1] - (low-1+1)))
    // = low + k
    return low + k;
}

int main() {
    vector<int> arr = {1,2,3,6};
    cout<<findKthPositive1(arr, 2)<<endl;
    cout<<findKthPositive2(arr, 2)<<endl;
    return 0;
}

// OUTPUT:
// 5
// 5

// Example to explain 2nd Approach:
// k = 3
// {1,2,3,4,8,10}
// l    m     h
// missing_count = 0 < k
// move to the right

// {1,2,3,4,8,10}
//        l m  h
// missing_count=3 = k
// move to the left

// {1,2,3,4, 8,10}
//        lmh
// missing_count = 0 < k
// move to the right

// {1,2,3,4, 8,10}
//        h lm

// answer = low + k = 4 + 3 = 7 

// One more example:
// k = 2
// {1,2,3,4}
//  l m   h
// missing_count = 0 < k
// move to the right

// {1,2,3, 4}
//      lm h
// missing_count = 0 < k
// move to the right

// {1,2,3,4  }
//        lmh
// missing_count = 0 < k
// move to the right

// l = 4 and the loop ends
// Thus answer= low + k = 4 + 2 = 6

// One more example
// k = 2
// {1,2,3,6}
//  l m   h
// missing_count = 0 < k
// move to the right

// {1,2,3, 6}
//      lm h
// missing_count = 0 < k
// move to the right

// {1,2,3,6}
//       lmh

// missing_count = 2 = k
// move to the left


// {1,2,3,6}
//      h lm

// answer = low + k = 3 + 2 = 5


