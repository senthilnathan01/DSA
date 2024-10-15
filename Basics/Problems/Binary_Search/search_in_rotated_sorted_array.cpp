#include <iostream>
#include<vector>
#include<algorithm>

using namespace std;

/*
Given a sorted array Arr of size N and a number X, you need to find the number of occurrences of X in Arr.
*/

int search1(vector<int>& nums, int target) {
    int size = nums.size();

    // Find the index of the minimum element.
    int min_index = min_element(nums.begin(), nums.end()) - nums.begin();

    // Create a sorted version of the array.
    vector<int> original_nums;
    for (int i = 0; i < size; i++) {
        original_nums.push_back(nums[(size - min_index + i) % size]);
    }

    // Perform binary search on the sorted array.
    int low = 0;
    int high = size - 1;
    while (low <= high) {
        int mid = low + (high - low) / 2;
        if (original_nums[mid] == target) {
            return (size - min_index + mid) % size;
        } else if (original_nums[mid] < target) {
            low = mid + 1;
        } else {
            high = mid - 1;
        }
    }

    return -1;
}


int main() {
    vector<int> nums = {4,5,6,7,0,1,2};
    int ans = search1(nums, 2); 
    cout<<ans;
    return 0;
}