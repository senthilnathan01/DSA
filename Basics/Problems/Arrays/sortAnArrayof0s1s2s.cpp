#include<iostream>
#include<vector>

using namespace std;

/*
Given an array nums with n objects colored red, white, or blue, sort them in-place so that objects of the same color are adjacent, with the colors in the order red, white, and blue.

We will use the integers 0, 1, and 2 to represent the color red, white, and blue, respectively.

You must solve this problem without using the library's sort function.
*/

// Approach 1:
// Count the number of 0s, 1s, 2s
// TC = O(N+N) = O(N)
void sortColors1(vector<int>& nums)
{
    int count0 = 0, count1 = 0, count2 = 0;
    for(int num: nums) 
    {
        if(num == 0) count0++;
        else if(num == 1) count1++;
    }

    for(int i =0; i<count0 ; i++) nums[i] = 0;
    for(int i = count0; i<count0+count1; i++) nums[i] = 1;
    for(int i = count0 + count1; i<nums.size(); i++) nums[i] = 2;
}

// Optimal Approach
// Using Dutch National Flag Algo
// TC = O(N)
// SC = O(1)
void sortColors2(vector<int>& nums) {
    int low = 0, mid = 0, high = nums.size()-1;
    while(mid<=high)
    {
        if(nums[mid]==0)
        {
            swap(nums[low], nums[mid]);
            low++;
            mid++;
        }
        else if(nums[mid]==1)
        {
            mid++;
        }
        else
        {   
            swap(nums[mid], nums[high]);
            high--;
        }
    }
}

int main()
{
    vector<int> nums = {2,0,2,1,1,0, 2};
    sortColors1(nums);
    for(int num: nums) cout<<num<<" ";
    nums = {2,0,2,1,1,0, 2};
    sortColors2(nums);
    cout<<endl;
    for(int num: nums) cout<<num<<" ";
}

// OUTPUT:
// 0 0 1 1 2 2 2 
// 0 0 1 1 2 2 2 