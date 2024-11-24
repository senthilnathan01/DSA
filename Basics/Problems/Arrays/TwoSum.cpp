#include<iostream>
#include<vector>
#include<map>
#include<algorithm>

using namespace std;

/*
Given an array of integers nums and an integer target, return indices of the two numbers such that they add up to target.

You may assume that each input would have exactly one solution, and you may not use the same element twice.

You can return the answer in any order.
*/

// Brute Force Approach:

vector<int> twoSum1(vector<int>& nums, int target) {
    int n = nums.size();
    for(int i = 0; i<n; i++)
    {
        for(int j = i+1; j<n; j++)
        {
            if(nums[i]+nums[j]==target) return {i,j};
        }
    }
    
    return {-1, -1};
}

// Better Solution using Hashing
// TC = O(logn) depending on the map
// SC = O(n)
vector<int> twoSum2(vector<int>& nums, int target){
    map<int, int> mpp;
    int n = nums.size();
    for(int i = 0; i < n; i++)
    {
        int num = nums[i];
        int more = target - num;
        if(mpp.find(more) != mpp.end()) return {mpp[more], i};
        mpp[num] = i;
    }
    return {-1, -1};
}

// Optimal Approach
// Greedy Approach using two pointers
// Optimal to use when we are not required to return the indices of such two numbers

// TC = O(N + NlogN)
// SC = O(1)

string twoSum3(vector<int>& nums, int target){
    // Sort the array
    sort(nums.begin(), nums.end());
    int left = 0; int right = nums.size()-1;
    while(left<right)
    {
        int sum = nums[left] + nums[right];
        if(sum == target) return "yes";
        else if(sum<target) left++;
        else right--;
    }
    return "no";
}

int main()
{
    vector<int> nums = {2,4,6,8,11};
    int target = 14;

    for(int num: twoSum1(nums, target)) cout<<num<<" ";
    cout<<endl;
    for(int num: twoSum2(nums, target)) cout<<num<<" ";
    cout<<endl;
    cout<<twoSum3(nums, target);
}
