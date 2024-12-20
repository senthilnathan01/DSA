#include<iostream>
#include<vector>

using namespace std;

/*
Given a binary array nums and an integer k, return the maximum number of consecutive 1's in the array 
if you can flip at most k 0's.
*/

/*
Alternate formulation:
Finding such a sequence is equivalent to finding the longest sub array with at most k zeroes.
*/

// Brute Force Approch:
// Get all the relevant subarray and get the max length
// TC = O(N^2)

// Better Approach:
// TC > O(N) but TC is not as bad as O(N^2) [inner while loop]
// SC =  O(1)
int maxOnes1(vector<int>& nums, int k)
{
    int l = 0, r = 0, maxLength = 0, n = nums.size(), zeros = 0;
    while(r<n)
    {
        if(nums[r]==0) zeros++;
        while(zeros>k) 
        {
            if(nums[l]==0) zeros--;
            l++;
        }
        if(zeros<=k)
        {
            int length = r-l+1;
            maxLength = max(length, maxLength);
        }
        r++;
    }
    return maxLength;
}

// Best Approach
// TC = O(N)
int maxOnes2(vector<int>& nums, int k)
{
    int l = 0, r = 0, zeros = 0, n = nums.size(), maxLength = 0;
    while(r<n)
    {
        if(nums[r]==0) zeros++;
        if(zeros > k)
        {
            if(nums[l]==0) zeros--;
            l++;
        }
        if(zeros<=k)
        {
            int length = r-l+1;
            maxLength = max(length, maxLength);
        }
        r++;
    }
    return maxLength;
}


int main()
{
    vector<int> nums = {1,1,1,0,0,0,1,1,1,1,0};
    int k = 2;
    cout<<maxOnes1(nums, k)<<endl;
    cout<<maxOnes2(nums, k);
}

// OUTPUT:
// 6
// 6