#include<iostream>
#include<vector>

using namespace std;

/*
Given an integer array nums, find the subarray with the largest sum, and return its sum.
*/

// Brute Force Approach:
// TC = O(N^3)

int maxSubArray1(vector<int>& nums) {
    int n = nums.size();
    int maxSum = INT32_MIN;
    for(int i = 0; i < n; i++)
    {
        for(int j = i; j < n; j++)
        {
            int sum = 0;
            for(int k = i; k<=j; k++)
            {
                sum += nums[k];
            }
            maxSum = max(maxSum, sum);
        }
    }
    return maxSum;
}

// Approach 2:
// Small modification in the above approach gives us a better time complexity
// TC = O(N^2)
int maxSubArray2(vector<int>& nums)
{
    int n = nums.size();
    int maxSum = INT32_MIN;
    for(int i = 0; i < n; i++)
    {
        int sum = 0;
        for(int j = i; j < n; j++)
        {
            sum += nums[j];  
            maxSum = max(maxSum, sum);
        }
    }
    return maxSum;
}

// Optimal Approach:
// Using Kadane's Algo
// TC = O(N)
// SC = O(1)
int maxSubArray3(vector<int>& nums)
{
    int maxSum = INT32_MIN;
    int sum = nums[0];
    for(int it: nums)
    {
        sum += it;
        if(sum> maxSum) maxSum = sum;
        if(sum < 0) sum = 0;
    }
    return maxSum;
}

int main()
{
    vector<int> nums = {-2,1,-3,4,-1,2,1,-5,4};
    cout<<maxSubArray1(nums)<<endl;
    cout<<maxSubArray2(nums)<<endl;
    cout<<maxSubArray3(nums)<<endl;
}

// OUTPUT:
// 6
// 6
// 6

