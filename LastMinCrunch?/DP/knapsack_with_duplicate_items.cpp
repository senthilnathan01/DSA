/*
Given a set of items, each with a weight and a value, represented by the array wt[] and val[] respectively. Also, a knapsack with a weight limit capacity.
Your task is to fill the knapsack in such a way that we can get the maximum profit. Return the maximum profit.

Note: Each item can be taken any number of times.

LINK: https://www.geeksforgeeks.org/problems/knapsack-with-duplicate-items4201/1
COMPANIES: Amazon
*/

// Just Recursion
class Solution {
  public:
    int func(int i, int capa, int n, vector<int> &val, vector<int> &wt){
        if(i==n) return 0;
        
        int take = 0;
        if(wt[i]<=capa) take = val[i] + func(i, capa - wt[i], n, val, wt);
        
        int noTake = func(i+1, capa, n, val, wt);
        return max(take, noTake);
    }
    int knapSack(vector<int>& val, vector<int>& wt, int capacity) {
        // code here
        int n = wt.size();
        return func(0, capacity, n, val, wt);
    }
};

// With Memoization - Top Down
class Solution {
  public:
    vector<vector<int>> memo;
    int func(int i, int capa, int n, vector<int> &val, vector<int> &wt){
        if(i==n) return 0;
        if(memo[i][capa]!=-1) return memo[i][capa];
        
        int take = 0;
        if(wt[i]<=capa) take = val[i] + func(i, capa - wt[i], n, val, wt);
        
        int noTake = func(i+1, capa, n, val, wt);
        return memo[i][capa] = max(take, noTake);
    }
    int knapSack(vector<int>& val, vector<int>& wt, int capacity) {
        // code here
        int n = wt.size();
        memo.assign(n, vector<int>(capacity+1, -1));
        return func(0, capacity, n, val, wt);
    }
};

