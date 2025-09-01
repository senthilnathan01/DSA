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

// Tabulation Approach
class Solution {
public:
    int lengthOfLIS(vector<int>& nums) {
        int n = nums.size();

        // We allocate (n+1) x (n+1) so that the row i = n exists (no elements left → LIS length = 0)
        // The vector is initialized with zeros, so dp[n][*] = 0 is already set
        vector<vector<int>> dp(n+1, vector<int>(n+1, 0));

        for(int i = n-1; i >= 0; i--){
            for(int prev = i-1; prev >=-1; prev--){
                // At (i, prev) you have two choices: Skip i, Take i
                
                // Skip i
                // Keep prev as-is and move on:
                int len = dp[i+1][prev+1];
                // Also, The +1 shift lets us store prev = -1 at column 0

                // Take i (only if it keeps the sequence increasing)
                if(prev == -1 || nums[i] > nums[prev]){
                    // You gain 1 by taking nums[i]
                    // The new prev becomes i, so you look up dp[i+1][i+1]
                    len = max(len, 1 + dp[i+1][i+1]);
                }
                
                // dp[i][prev+1] = length of the LIS if we are currently at index i and the last index we took is prev
                dp[i][prev + 1] = len; // best of skip/take
            }
        }

        return dp[0][0];
    }
};

// Another simple approach
class Solution {
public:
    int lengthOfLIS(vector<int>& nums) {
        int n = nums.size();

        vector<int> dp(n, 1);

        int maxi = 1;
        for(int i = 0; i < n; i++){
            for(int prev = 0; prev < i; prev++){
                if(nums[i]>nums[prev]) dp[i] = max(dp[i], 1 + dp[prev]);
            }
            maxi = max(maxi, dp[i]);
        }

        return maxi;
    }
};
