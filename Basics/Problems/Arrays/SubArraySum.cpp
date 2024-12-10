#include<iostream>
#include<vector>
#include<unordered_map>

using namespace std;

/*
Problem:
Given an array of integers nums and an integer k, return the total number of subarrays whose sum equals to k.

A subarray is a contiguous non-empty sequence of elements within an array.
*/

// Brute Force Solution = BFS
// Get all the subarrays and check if their sum is k
// TC = O(N^3)
int subarrayBFS(vector<int> nums, int k)
{
    int n = nums.size();
    int count =0;
    for(int i = 0; i<n ; i++)
    {
        for(int j = i; j<n ; j++)
        {
            int sum = 0;
            for(int k = i; k<=j; k++)
            {
                sum += nums[k]; 
            }
            if(sum==k) count++;
        }
    }
    return count;
}

// Better Solution = BS
// With TC = O(N^2)
int subarrayBS(vector<int> nums, int k)
{
    int count= 0;
    int n = nums.size();
    for(int i=0; i<n; i++)
    {
        int sum = 0;
        for(int j = i; j<n; j++)
        {
            sum += nums[j];
            if(sum==k) count++;
        }
    }
    return count;
}

// Optimal Solution = OS
// Using prefix sum concept and hashmap
// TC = O(N)
int subarrayOS(vector<int> nums, int k)
{
    unordered_map<int, int> mpp;
    int preSum = 0, count = 0;
    mpp[0]=1;
    for(int i = 0; i<nums.size(); i++)
    {
        preSum += nums[i];
        int remove = preSum - k;
        count += mpp[remove];
        mpp[preSum]++;
    }     
    return count;
}

int main()
{
    vector<int> nums = {1,2,1,1,1,3,-3};
    cout<<subarrayBFS(nums, 3)<<endl;
    cout<<subarrayBS(nums, 3)<<endl;
    cout<<subarrayOS(nums, 3);
}

// OUTPUT:
// 5
// 5
// 5