/*
You are a professional robber planning to rob houses along a street. Each house has a certain amount of money stashed, 
the only constraint stopping you from robbing each of them is that adjacent houses have security systems connected and 
it will automatically contact the police if two adjacent houses were broken into on the same night.

Given an integer array nums representing the amount of money of each house, return the maximum amount of money you can rob tonight without alerting the police.

LINK: https://leetcode.com/problems/house-robber/description/
*/

class Solution {
public:
    int rob(vector<int>& nums) {
        int n = nums.size();
        if(n==1) return nums[0];

        // dp[i] = max(dp[i-1], nums[i] + dp[i-2])
        // curr = max(prev1, nums[i] + prev2)
        int prev1 = max(nums[0], nums[1]), prev2 = nums[0], curr;
        for(int i =2; i < n; i++){
            curr = max(prev1, nums[i] + prev2);
            prev2 = prev1;
            prev1 = curr;
        }
        return prev1;
    }
};
