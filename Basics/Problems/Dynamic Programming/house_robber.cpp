/*
You are a professional robber planning to rob houses along a street. Each house has a certain amount of money stashed, the only constraint stopping you from robbing each of them is that adjacent houses have security systems connected and it will automatically contact the police if two adjacent houses were broken into on the same night.

Given an integer array nums representing the amount of money of each house, return the maximum amount of money you can rob tonight without alerting the police.

LeetCode Link: https://leetcode.com/problems/house-robber/description/
*/

class Solution {
public:
    int rob(vector<int>& nums) {
        int n = nums.size();
        if(n==1) return nums[0];
        if(n==2) return max(nums[0], nums[1]);

        vector<int> maxAns(n, -1);
        maxAns[0] = nums[0];
        maxAns[1] = nums[1];

        for(int i = 2; i < n; i++)
        {
            int ans = -1;
            if(i>=2)
            {
                ans = max(ans, maxAns[i-2]);
            }
            if(i>=3)
            {
                ans = max(ans, maxAns[i-3]);
            }
            maxAns[i] = ans + nums[i];
        }

        return max(maxAns[n-1], maxAns[n-2]);
    }
};
