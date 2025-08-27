/*
Given a rod of length n inches and an array price[], where price[i] denotes the value of a piece of length i. 
Your task is to determine the maximum value obtainable by cutting up the rod and selling the pieces.

Note: n = size of price, and price[] is 1-indexed array.

Link: https://www.geeksforgeeks.org/problems/rod-cutting0840/1
*/
class Solution {
  public:
    int cutRod(vector<int> &price) {
        int n = price.size();
        vector<int> dp(n+1, 0);
        
        for(int len = 1; len <= n; len++){
            for(int j = len; j <= n; j++){
                dp[j] = max(dp[j], dp[j-len] + price[len-1]);
            }
        }
        
        return dp[n];
        
    }
};
