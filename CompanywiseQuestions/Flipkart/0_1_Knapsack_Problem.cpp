/*
Given two arrays, val[] and wt[], where each element represents the value and weight of an item respectively, and an integer W representing the maximum capacity of the knapsack (the total weight it can hold).

The task is to put the items into the knapsack such that the total value obtained is maximum without exceeding the capacity W.

Note: You can either include an item completely or exclude it entirely — fractional selection of items is not allowed. Each item is available only once.

LINK: https://www.geeksforgeeks.org/problems/0-1-knapsack-problem0945/1
*/

class Solution {
  public:
    vector<vector<int>> dp;
    int func(int i, int n, int W, vector<int> &val, vector<int> &wt){
        if(i==n) return 0;
        
        if(dp[W][i]!=-1) return dp[W][i];
        // take
        int maxi = 0;
        if(W - wt[i] >= 0) maxi = val[i] + func(i+1, n, W-wt[i], val, wt);
        
        // not take
        maxi = max(maxi, func(i+1, n, W, val, wt));
        return dp[W][i] = maxi;
    }
    int knapsack(int W, vector<int> &val, vector<int> &wt) {
        int n = val.size();
        dp.assign(W+1, vector<int>(n, -1));
        return func(0, n, W, val, wt);
    }
};
