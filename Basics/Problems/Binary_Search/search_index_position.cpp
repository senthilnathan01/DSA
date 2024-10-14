#include <iostream>
#include<vector>
#include<algorithm>

using namespace std;

/*
Given a sorted array of distinct integers and a target value, return the index if the target is found. 
If not, return the index where it would be if it were inserted in order.

You must write an algorithm with O(log n) runtime complexity.
*/

int searchInsert(vector<int>& nums, int target) {
    int index = -1;
    int low = 0;
    int size = nums.size();
    int high = size - 1;
    int mid;

    // Perform binary search
    while(low<=high){
        mid = low + (high - low)/2;
        if(nums[mid]==target) return mid; // target is found
        else if(nums[mid]<target) low = mid +1;
        else high = mid -1;
    }

    // target is not found
    return mid; 
}

int main() {
    vector<int> v = {1,3,5,6};
    int ans = searchInsert(v, 4);
    cout<<ans;
    return 0;
}

// OUTPUT:
// 2