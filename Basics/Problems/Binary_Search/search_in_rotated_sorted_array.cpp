#include <iostream>
#include<vector>
#include<algorithm>

using namespace std;

/*
There is an integer array nums sorted in ascending order (with distinct values).

Prior to being passed to your function, nums is possibly rotated at an unknown pivot index k (1 <= k < nums.length) 
such that the resulting array is [nums[k], nums[k+1], ..., nums[n-1], nums[0], nums[1], ..., nums[k-1]] (0-indexed). 
For example, [0,1,2,4,5,6,7] might be rotated at pivot index 3 and become [4,5,6,7,0,1,2].

Given the array nums after the possible rotation and an integer target, return the index of target if it is in nums, or -1 if it is not in nums.
*/

// 3 Approaches (last approach is the best)

// Approach 1:
// Rotate the array to its original state -> do normal binary search -> get the index in sorted array 
// -> get the index in the unsorted array by doing rotation

// But this is a complicated answer as the linear search will just take O(n) which is similar to the time
// taken when creating the sorted array by rotation

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

// Approach 2:
// Linear search

// Approach 3:
// Just using modified binary search 

int search3(vector<int>& nums, int target){
    int low =0, high = nums.size()-1;
    while(low<=high)
    {
        int mid = low + (high-low)/2;
        if(nums[mid]==target) return mid;
        if(nums[low]<=nums[mid]) // Check if the left half is sorted
        {
            if(nums[low]<= target && target < nums[mid])
            {
                high = mid - 1;
            }
            else
            {
                low = mid + 1;
            }
        }
        else // Right half must be sorted
        {
            if(nums[mid]<target && target <= nums[high])
            {
                low = mid + 1;
            }
            else
            {
                high = mid - 1;
            }
        }
        
    }
    return -1;
}

int main() {
    vector<int> nums = {4,5,6,7,0,1,2};
    int ans = search1(nums, 2); 
    cout<<ans<<endl;
    int ans = search3(nums, 2);
    cout<<ans;
    return 0;
}