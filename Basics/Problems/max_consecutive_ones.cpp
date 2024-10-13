#include <iostream>
#include<vector>
using namespace std;

/*
Given a binary array nums, return the maximum number of consecutive 1's in the array.
*/

// Finds the maximum number of consecutive 1s in a binary array.
int find_max_consecutive_ones(const vector<int>& nums) {
    int max_count = 0;
    int current_count = 0;

    // Iterate through the array.
    for (int num : nums) {
        // If the current element is 1, increment the current count.
        if (num == 1) {
            current_count++;
        } else {
            // If the current element is 0, update the maximum count if necessary and reset the current count.
            max_count = max(max_count, current_count);
            current_count = 0;
        }
    }

    // Check if the last element is 1 and update the maximum count if necessary.
    max_count = max(max_count, current_count);

    return max_count;
}

int main() {
    vector<int> nums = {1, 1, 0, 1, 1, 1};

    cout << find_max_consecutive_ones(nums) << endl;

    return 0;
}