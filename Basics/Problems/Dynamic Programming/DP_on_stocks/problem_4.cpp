/*
You are given an integer array prices where prices[i] is the price of a given stock on the ith day, and an integer k.

Find the maximum profit you can achieve. You may complete at most k transactions: i.e. you may buy at most k times and sell at most k times.

Note: You may not engage in multiple transactions simultaneously (i.e., you must sell the stock before you buy again).

Link: https://leetcode.com/problems/best-time-to-buy-and-sell-stock-iv/description/
*/

class Solution {
public:
    int maxProfit(int k, vector<int>& prices) {
        vector<int> profit(k+1, 0);
        vector<int> buy(k+1, INT_MAX);
        for(int i = 0; i < prices.size(); i++){
            for(int j = 1; j <= k; j++){
                buy[j] = min(buy[j], prices[i] - profit[j-1]);
                profit[j] = max(profit[j], prices[i]-buy[j]);
            }
        }

        return profit[k];
    }
};
