/*
You are a professional robber planning to rob houses along a street. Each house has a certain amount of money stashed. 
  All houses at this place are arranged in a circle. That means the first house is the neighbor of the last one. 
  Meanwhile, adjacent houses have a security system connected, and it will automatically contact the police if two adjacent houses were broken into on the same night.

Given an integer array nums representing the amount of money of each house, return the maximum amount of money you can rob tonight without alerting the police.

LINK: https://leetcode.com/problems/house-robber-ii/
*/

class Solution {
public:
    int rob1(vector<int> &temp, int l, int r){
        int n = temp.size();

        // dp[i] = max(nums[i] + dp[i-2], dp[i-1])
        int prev1 = 0;
        int prev2 = 0;
        for(int i = l; i <= r; i++){
            int curr = max(temp[i] + prev1, prev2);
            prev1 = prev2;
            prev2 = curr;
        }
        return prev2;
    }

    int rob(vector<int>& nums) {
        int n = nums.size();
        if(n==1) return nums[0];
        return max(rob1(nums, 0, n-2), rob1(nums, 1, n-1));
    }
};
