/*
Given an integer array nums, return true if you can partition the array into two subsets 
such that the sum of the elements in both subsets is equal or false otherwise.

LeetCode Link: https://leetcode.com/problems/partition-equal-subset-sum/description/
*/

// Observations:
// 1. Total sum = odd -> return false
// 2. Target sum = total sum / 2
// Now this becomes a subset sum equals k problem, which we just solved, where k = sum/2

class Solution {
public:
    bool isSubset(vector<int> &nums, int target)
    {
        vector<int> dp(target + 1);
        dp[0] = true;
        for(int num: nums)
        {
            for(int j = target; j >= num; j--)
            {
                dp[j] = dp[j] || dp[j -num];
            }
        }
        return dp[target];
    }
    bool canPartition(vector<int>& nums) {
        int sum = 0;
        for(int num: nums) sum += num;
        if(sum&1) return false;

        return isSubset(nums, sum/2);
    }
};

 
