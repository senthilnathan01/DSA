#include <iostream>
#include <vector>

using namespace std;

/*
Given an integer array nums, rotate the array to the right by k steps, where k is non-negative.
*/

// Rotates a vector to the right by k steps.
void rotate(vector<int>& nums, int k) {
    int size = nums.size();
    vector<int> temp;

    // Create a temporary vector to store the rotated elements.
    for (int i = 0; i < size; i++) {
        // Calculate the index of the element to be moved to the new position.
        int m = (i - k) % size;
        if (m < 0) {
            m += size;  // Adjust for negative indices
        }
        temp.push_back(nums[m]);
    }

    // Copy the elements from the temporary vector back to the original vector.
    for (int i = 0; i < size; i++) {
        nums[i] = temp[i];
    }
}

int main() {
    vector<int> nums = {1, 2, 3, 4, 5};

    rotate(nums, 3);

    for (int i = 0; i < 5; i++) {
        cout << nums[i] << " ";
    }

    return 0;
}