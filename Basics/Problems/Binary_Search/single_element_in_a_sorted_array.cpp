#include <iostream>
#include<vector>

using namespace std;

/*
You are given a sorted array consisting of only integers where every element appears exactly twice, 
except for one element which appears exactly once.

Return the single element that appears only once.

Your solution must run in O(log n) time and O(1) space.
*/

// Few Observations and Approach:
// The array has odd number of elements
// The element with single count always falls on odd place or (alternatively, on the even number index)
// We don't know which element has single count, so we can't search for it. 
// So we just have to check whether the mid element (in binary search algo) has a single count
// This element will be different from the element after it and the element before it

int singleNonDuplicate(vector<int>& nums) {
    int size = nums.size();
    // Let's just check a few simple cases before proceeding with the main approach
    // If the array has one element, then the answer is that element
    if(size==1) return nums[0];
    // Check if the first element is different from the element after it
    else if(nums[0]!=nums[1]) return nums[0];
    // Check if the last element is different from the element before it
    else if(nums[size-1]!=nums[size-2]) return nums[size-1];
    // Now let's move to the main approach
    int low = 0;
    int high = size -1;
    while(low<=high)
    {
        int mid = low + (high-low)/2;
        // Check if the mid element is different from the element after it and the element before it
        // Or alternatively, check if the mid element is the single count element
        if(nums[mid]!=nums[mid-1] && nums[mid]!=nums[mid+1]) return nums[mid];
        // Check the end of the code for the intuition behind the logic that follows next
        // Check if the mid is in the left part
        else if(((mid&1)==0 && nums[mid]!=nums[mid+1])||
        ((mid&1) && nums[mid]==nums[mid+1])) high = mid - 1;
        else low = mid + 1; // If not in the left part, it is in the right part
    }
    return -1; //If no such element is found
}

int main() {
    vector<int> arr = {1,1,2,3,3,4,4,5,5};
    cout<<singleNonDuplicate(arr)<<endl;
    return 0;
}

// INPUT:
// Case 1:
// Single count element is in the middle
// {1,1,2,3,3}

// Case 2:
// It is in the left part

// If either of the two cases are true
// Case 1: If the mid element is in the even index position
// And it is different from the element that follows it
// Case 2: If the mid element is in the odd index position
// And it is same as the element that follows it

// Else it is in the right part

// For ex: 
// Case: Mid element in the even index position
// {1,1,2,3,3,4,4,5,5}
//  l       m       h
// Now we check the left part

// {1,1,2,3,3,4,4,5,5}
//  l m   h
// Here the mid element(odd index position) is not same as the element that follows it
// So we move to check the right part

// {1,1,2,  3,3,4,4,5,5}
//      l,m h
// m is different from the elements in front of it and before it
// then single count element is in m 



