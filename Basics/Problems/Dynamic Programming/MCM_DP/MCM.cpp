/*
Given an array arr[] which represents the dimensions of a sequence of matrices where the ith matrix 
has the dimensions (arr[i-1] x arr[i]) for i>=1, find the most efficient way to multiply these matrices 
together. The efficient way is the one that involves the least number of multiplications.

Link: https://www.geeksforgeeks.org/problems/matrix-chain-multiplication0303/1
*/

class Solution {
  public:
    vector<vector<int>> dp;
    int func(int i, int j, vector<int> &arr){
        if(i==j) return 0;
        if(dp[i][j]!=-1) return dp[i][j];
        
        int mini = INT_MAX;
        for(int k = i; k <j; k++){
            int steps = arr[i-1]*arr[k]*arr[j] + func(i, k, arr) + func(k+1, j, arr);
            if(steps < mini) mini = steps;
        }
        return dp[i][j] = mini;
    }
    
    int matrixMultiplication(vector<int> &arr) {
        
        int n = arr.size();
        dp.assign(n, vector<int>(n, -1));
        return func(1, n-1, arr);
    }
};
