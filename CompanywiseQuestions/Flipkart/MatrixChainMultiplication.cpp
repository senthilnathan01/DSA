/*
Given an array arr[] which represents the dimensions of a sequence of matrices where the ith matrix has the dimensions 
(arr[i-1] x arr[i]) for i>=1, find the most efficient way to multiply these matrices together. The efficient way is the 
one that involves the least number of multiplications.

LINK: https://www.geeksforgeeks.org/problems/matrix-chain-multiplication0303/1
*/

class Solution {
  public:
    vector<vector<int>> dp;
    int solve(int l, int r, int n, vector<int> &arr){
        if(l>=r) return 0;
        
        int mini = INT_MAX;
        if(dp[l][r]!=-1) return dp[l][r];
        for(int k = l; k < r; k++){
            mini = min(mini, arr[l-1]*arr[k]*arr[r] + solve(l, k, n, arr) + solve(k+1, r, n, arr));
        }
        return dp[l][r]=mini;
    }
    int matrixMultiplication(vector<int> &arr) {
        int n = arr.size();
        dp.assign(n, vector<int>(n, -1));
        return solve(1, n-1, n, arr);
    }
};

// DP
