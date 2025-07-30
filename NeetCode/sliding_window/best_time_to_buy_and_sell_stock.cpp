/*
You are given an array prices where prices[i] is the price of a given stock on the ith day.

You want to maximize your profit by choosing a single day to buy one stock and choosing a different day in the future to sell that stock.

Return the maximum profit you can achieve from this transaction. If you cannot achieve any profit, return 0.

Leetcode Link: https://leetcode.com/problems/best-time-to-buy-and-sell-stock/description/
*/

class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int n = prices.size();
        if(n==1) return 0;

        int l = 0, r=1;
        int maxP = 0;
        
        while(r<n)
        {
            if(prices[l] < prices[r])
            {
                // we have profit
                maxP = max(maxP, prices[r]-prices[l]);
            }
            else l = r;
            r++;
        }
        return maxP;

    }
};
