/*
Given an integer array arr, partition the array into (contiguous) subarrays of length at most k. 
After partitioning, each subarray has their values changed to become the maximum value of that subarray.

Return the largest sum of the given array after partitioning. Test cases are generated so that the answer fits in a 32-bit integer.

LINK: https://leetcode.com/problems/partition-array-for-maximum-sum/description/
*/

class Solution {
public:
    vector<int> dp;
    
    int func(int i, int k, vector<int> &arr){
        if(i == arr.size()) return 0;
        if(dp[i] != -1) return dp[i];

        int maxi = INT_MIN;
        int currMax = INT_MIN;

        // Try all possible lengths (up to k)
        for(int len = 1; len <= k && i + len <= arr.size(); len++){
            currMax = max(currMax, arr[i + len - 1]); // max in current subarray
            int ans = currMax * len + func(i + len, k, arr);
            maxi = max(maxi, ans);
        }
        return dp[i] = maxi;
    }

    int maxSumAfterPartitioning(vector<int>& arr, int k) {
        dp.assign(arr.size(), -1);
        return func(0, k, arr);
    }
};
