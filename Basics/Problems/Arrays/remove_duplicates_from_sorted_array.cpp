#include <iostream>
#include <vector>

using namespace std;

/*
Questions:

Given an integer array nums sorted in non-decreasing order, remove the duplicates in-place 
such that each unique element appears only once. The relative order of the elements should 
be kept the same. Then return the number of unique elements in nums.
*/

// Removes duplicates from a sorted array in-place.
int remove_duplicates(vector<int>& nums) {
    int unique_count = 1;  // Start with 1 as the first element is always unique

    for (int i = 1; i < nums.size(); i++) {
        if (nums[i] != nums[unique_count - 1]) {
            nums[unique_count] = nums[i];
            unique_count++;
        }
    }

    return unique_count;
}

int main() {
    vector<int> nums = {1, 2, 3, 4, 4, 4, 5};

    int unique_count = remove_duplicates(nums);

    cout << "Number of unique elements: " << unique_count << endl;
    cout << "Array after removing duplicates:"<<endl;
    for (int i = 0; i < unique_count; i++) {
        cout << nums[i] << " ";
    }
    cout << endl;

    return 0;
}