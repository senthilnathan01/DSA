/*
You are given n balloons, indexed from 0 to n - 1. 
  Each balloon is painted with a number on it represented by an array nums. You are asked to burst all the balloons.

If you burst the ith balloon, you will get nums[i - 1] * nums[i] * nums[i + 1] coins. 
  If i - 1 or i + 1 goes out of bounds of the array, then treat it as if there is a balloon with a 1 painted on it.

Return the maximum coins you can collect by bursting the balloons wisely.

LINK: https://leetcode.com/problems/burst-balloons/description/
*/

class Solution {
public:
    vector<vector<int>> dp;
    int func(int i, int j, vector<int> &arr){
        if(i>j) return 0;
        if(dp[i][j]!=-1) return dp[i][j];

        int maxi = 0;
        for(int k = i; k <= j; k++){
            maxi = max(maxi, arr[i-1]*arr[k]*arr[j+1] + func(i, k-1, arr) + func(k+1, j, arr));
        }
        return dp[i][j] = maxi;
    }
    int maxCoins(vector<int>& nums) {
        vector<int> arr = {1};
        arr.insert(arr.end(), nums.begin(), nums.end());
        arr.push_back(1);   
        int n = nums.size();

        dp.assign(n+2, vector<int>(n+2, -1));

        return func(1, n, arr);
    }
};

// Tabulation Approach
class Solution {
public:
    int maxCoins(vector<int>& nums) {
        int n = nums.size();
        vector<int> arr;
        arr.push_back(1);
        arr.insert(arr.end(), nums.begin(), nums.end());
        arr.push_back(1);

        vector<vector<int>> dp(n+2, vector<int>(n+2, 0));
        for(int len = 1; len <= n; len++){
            for(int i = 1; i <= n-len+1; i++){
                int j = i + len - 1;
                for(int k = i; k <= j; k++){
                    dp[i][j] = max(dp[i][j], arr[i-1]*arr[k]*arr[j+1] + dp[i][k-1] + dp[k+1][j]);
                }
            }
        }
        return dp[1][n];
    }
};
