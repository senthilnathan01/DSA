/*
You are given n balloons, indexed from 0 to n - 1. Each balloon is painted with a number on it represented 
by an array nums. You are asked to burst all the balloons.

If you burst the ith balloon, you will get nums[i - 1] * nums[i] * nums[i + 1] coins. If i - 1 or i + 1 goes 
out of bounds of the array, then treat it as if there is a balloon with a 1 painted on it.

Return the maximum coins you can collect by bursting the balloons wisely.

LINK: https://leetcode.com/problems/burst-balloons/description/
*/

class Solution {
public:
    vector<vector<int>> dp;
    int func(int i, int j, vector<int> &nums){
        if(i>j) return 0;

        if(dp[i][j]!=-1) return dp[i][j];

        int maxi = 0;
        for(int k = i; k <= j; k++){
            int coin = nums[i-1]*nums[k]*nums[j+1] + func(i, k-1, nums) + func(k+1, j, nums);
            maxi = max(maxi, coin);   
        }
        return dp[i][j] = maxi;
    }

    int maxCoins(vector<int>& nums) {
        int n = nums.size();
        vector<int> arr(n+2, 0);
        arr[0] = 1;
        arr[n+1] = 1;
        for(int i = 0; i < n; i++) arr[i+1] = nums[i];
        dp.assign(n+2, vector<int>(n+2, -1));
        return func(1, n, arr);
    }
};
