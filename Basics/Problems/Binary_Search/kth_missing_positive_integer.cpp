#include <iostream>
#include<vector>
#include<algorithm>

using namespace std;

/*
Given an array arr of positive integers sorted in a strictly increasing order, and an integer k.

Return the kth positive integer that is missing from this array.
*/
int findKthPositive(vector<int>& arr, int k) {
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

int main() {
    vector<int> arr = {1,2,3,4};
    cout<<findKthPositive(arr, 2)<<endl;
    return 0;
}

// OUTPUT:
// 6
