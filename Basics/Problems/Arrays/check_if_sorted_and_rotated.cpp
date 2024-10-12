#include <iostream>
#include <vector>

using namespace std;

/*
Question:

Given an array nums, return true if the array was originally sorted in non-decreasing order, 
then rotated some number of positions (including zero). Otherwise, return false.

There may be duplicates in the original array.

Note: An array A rotated by x positions results in an array B of the same length such that 
A[i] == B[(i+x) % A.length], where % is the modulo operation.
*/

// Checks if an array is a rotated sorted array.
bool is_rotated_sorted_array(const vector<int>& nums) {
    // Find the index of the minimum element.
    int min_index = 0;
    for (int i = 1; i < nums.size(); i++) {
        if (nums[i] < nums[min_index]) {
            min_index = i;
        }
    }

    // Check if the array is sorted from min_index onwards and before min_index.
    for (int i = min_index + 1; i < nums.size(); i++) {
        if (nums[i] < nums[i - 1]) {
            return false;
        }
    }
    for (int i = 0; i < min_index; i++) {
        if (nums[i] < nums[i - 1]) {
            return false;
        }
    }

    return true;
}

int main() {
    vector<int> nums = {3, 4, 5, 1, 2};

    cout << is_rotated_sorted_array(nums) << endl;

    return 0;
}