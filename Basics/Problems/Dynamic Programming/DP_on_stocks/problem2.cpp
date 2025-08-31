/*
You are given an integer array prices where prices[i] is the price of a given stock on the ith day.

On each day, you may decide to buy and/or sell the stock. You can only hold at most one share of the stock at any time. However, you can buy it then immediately sell it on the same day.

Find and return the maximum profit you can achieve.

Link: https://leetcode.com/problems/best-time-to-buy-and-sell-stock-ii/description/
*/

// Unnecessary DP style
class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int n = prices.size();
        if(n==1) return 0;

        vector<int> dp(n+1, 0);

        dp[0] = 0; //cumulative profit when starting = 0
        int low = prices[0];
        for(int i = 1; i <= n; i++){
            int profit=0;
            if(prices[i-1]>low){
                profit = prices[i-1] - low;
            }
            low = prices[i-1];
            dp[i] = profit + dp[i-1];
        }
        return dp[n];
    }
};

// Better Simple Code
class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int n = prices.size();
        if(n==1) return 0;

        int ans = 0;
        for(int i = 1; i < n; i++){
            if(prices[i]>prices[i-1]){
                ans += prices[i] - prices[i-1];
            }
        }
        return ans;
    }
};
