#include<iostream>
#include<vector>

using namespace std;

/*
Problem:
Given a binary array nums and an integer goal, return the number of non-empty subarrays with a sum goal.

A subarray is a contiguous part of the array.
*/

int lessThanEqualTo(vector<int> & nums, int goal)
{
    // Returns number of subarrays with sum less than or equal to goal
    if(goal<0) return 0;

    int l = 0, r = 0, sum = 0, cnt = 0, n = nums.size();
    while(r<n)
    {
        sum += nums[r];
        while(sum>goal)
        {
            sum -= nums[l];
            l++;
        }
        cnt += (r-l+1);
        r++; 
    }
    return cnt;
}

int numSubarraysWithSum(vector<int>& nums, int goal) {
    return (lessThanEqualTo(nums, goal)-lessThanEqualTo(nums, goal -1));
}

int main()
{
    vector<int> nums = {1,0,1,0,1};
    int goal = 2;
    cout<<numSubarraysWithSum(nums, goal);
}
