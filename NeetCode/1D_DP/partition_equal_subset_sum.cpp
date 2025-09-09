/*
Given an integer array nums, return true if you can partition the array into two subsets such that the sum of the elements in both subsets is equal or false otherwise.

LINK: https://leetcode.com/problems/partition-equal-subset-sum/description/
*/

class Solution {
public:
    bool canPartition(vector<int>& nums) {
        int tot = accumulate(nums.begin(), nums.end(), 0);
        if(tot&1) return false; // odd tot

        // check for subset sum = tot/2
        sort(nums.begin(), nums.end());
        vector<int> dp(tot/2 +1, false);
        dp[0] = true;
        for(int num: nums){
            for(int j = tot/2; j >= num; j--) dp[j]=dp[j]||dp[j-num];
        }
        return dp[tot/2];
    }
};
