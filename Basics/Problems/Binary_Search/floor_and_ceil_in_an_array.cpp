#include <iostream>
#include<vector>
#include<algorithm>

using namespace std;

/*
Given an unsorted array arr[] of integers and an integer x, find the floor and ceiling of x in arr[].
Return an array of integers denoting the [floor, ceil]. 
Return -1 for floor or ceiling if the floor or ceiling is not present.
*/

// Finds the floor and ceiling of a given element in a sorted array.
vector<int> find_floor_and_ceil(int x, vector<int>& arr) {
    vector<int> result(2, -1); // Initialize result with -1 for both floor and ceil

    // Sort the array in ascending order if not already sorted.
    sort(arr.begin(), arr.end());

    // Find the floor of x using binary search.
    int low = 0;
    int high = arr.size() - 1;
    while (low <= high) {
        int mid = low + (high - low) / 2;
        if (arr[mid] <= x) {
            low = mid + 1;
        } else {
            high = mid - 1;
        }
    }
    if (arr[high] <= x) {
        result[0] = arr[high];
    }

    // Find the ceiling of x using binary search.
    low = 0;
    high = arr.size() - 1;
    while (low <= high) {
        int mid = low + (high - low) / 2;
        if (arr[mid] <= x) {
            low = mid + 1;
        } else {
            high = mid - 1;
        }
    }
    if (arr[low] >= x) {
        result[1] = arr[low];
    }

    return result;
}

int main() {
    vector<int> v = {10, 24, 69, 9};
    vector<int> ans = find_floor_and_ceil(7, v);
    for(int num: ans){
        cout<<num<<" ";
    }
    return 0;
}

// OUTPUT:
// -1 9
