#include <iostream>
#include<vector>
using namespace std;

/*
Given a sorted array arr[] of size n without duplicates, and given a value x. 
Floor of x is defined as the largest element k in arr[] such that k is smaller than or equal to x. 
Find the index of k(0-based indexing).
*/

// Finds the floor of a given element in a sorted array.
int find_floor(const vector<long long>& arr, long long n, long long x) {
    int low = 0;
    int high = n - 1;

    // Perform binary search.
    while (low <= high) {
        int mid = low + (high - low) / 2;

        if (arr[mid] <= x) {
            low = mid + 1;
        } else {
            high = mid - 1;
        }
    }

    // The floor element is the last element that is less than or equal to x.
    return high;
}

int main() {
    vector<long long> v = {1,2,4,7,8};
    cout<<find_floor(v, 5, 5)<<endl;
    return 0;
}