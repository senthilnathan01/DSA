/*
Given a set of items, each with a weight and a value, represented by the array wt and val respectively. Also, a knapsack with a weight limit capacity.
The task is to fill the knapsack in such a way that we can get the maximum profit. Return the maximum profit.
Note: Each item can be taken any number of times.

Link: https://www.geeksforgeeks.org/problems/knapsack-with-duplicate-items4201/1
*/

class Solution {
  public:
    int knapSack(vector<int>& val, vector<int>& wt, int capacity) {
        vector<int> dp(capacity + 1, 0);
        int n = val.size();
        
        for(int i = 0; i < n; i++){
            for(int j = 0; j <= capacity - wt[i]; j++){
                dp[j + wt[i]] = max(dp[j + wt[i]], dp[j] + val[i]);
            }
        }
        
        return dp[capacity];
        
    }
};
