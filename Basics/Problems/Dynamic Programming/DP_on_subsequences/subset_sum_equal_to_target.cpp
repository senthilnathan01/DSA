/*
Given an array arr of n integers and an integer target, determine if there is a subset of the given array with a sum equal to the given target.

GFG Link: https://www.geeksforgeeks.org/problems/subset-sum-problem-1611555638/1
*/

// Recursion
class Solution {
  public:
    bool f(int ind, int target, vector<int> &arr, vector<vector<int>> &dp)
    {
        if(target==0) return true;
        if(ind == 0) return (arr[0]==target);
        
        if(dp[ind][target]!=-1) return dp[ind][target];
        
        bool notTake = f(ind-1, target, arr, dp);
        bool take = false;
        if(arr[ind] <= target) take = f(ind-1, target-arr[ind], arr, dp);
        return dp[ind][target] = take || notTake;
    }
    
    bool isSubsetSum(vector<int>& arr, int sum) {
        int n = arr.size();
        vector<vector<int>> dp(n, vector<int>(sum+1, -1));
        return f(n-1, sum, arr, dp);
    }   
};

// Tabulation
class Solution {
  public:
    bool isSubsetSum(vector<int>& arr, int sum) {
        int n = arr.size();
        vector<vector<bool>> dp(n, vector<bool>(sum+1, 0));
        
        for(int i = 0; i < n; i++) dp[i][0] = true;
        dp[0][arr[0]] = true;
        
        for(int idx = 1; idx < n; idx++)
        {
            for(int target = 1; target <= sum; target++)
            {
                bool notTake = dp[idx-1][target];
                bool take = false;
                if(arr[idx] <= target) take = dp[idx-1][target-arr[idx]];
                dp[idx][target] = take || notTake;
            }
        }
        return dp[n-1][sum];
    }   
};

// We gotta space optimise
