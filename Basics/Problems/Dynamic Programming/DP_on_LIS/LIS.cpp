/*
Given an integer array nums, return the length of the longest strictly increasing subsequence.

Link: https://leetcode.com/problems/longest-increasing-subsequence/description/
*/

class Solution {
public:
    vector<vector<int>> dp;
    int func(int i, int prev, int n, vector<int> &nums){
        if(i==n) return 0;

        if(dp[i][prev+1]!=-1) return dp[i][prev+1];

        int len = func(i+1, prev, n, nums);
        if(prev == -1 || nums[i] > nums[prev]) len = max(len, 1 + func(i+1, i, n, nums));
        return dp[i][prev+1] = len;
    }
    int lengthOfLIS(vector<int>& nums) {
        int n = nums.size();

        dp.assign(n, vector<int>(n+1, -1));
        return func(0, -1, n, nums);
    }
};
