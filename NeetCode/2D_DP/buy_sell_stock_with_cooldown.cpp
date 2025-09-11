/*
You are given an array prices where prices[i] is the price of a given stock on the ith day.

Find the maximum profit you can achieve. You may complete as many transactions as you like (i.e., buy one and sell one share of the stock multiple times) with the following restrictions:

After you sell your stock, you cannot buy stock on the next day (i.e., cooldown one day).
Note: You may not engage in multiple transactions simultaneously (i.e., you must sell the stock before you buy again).

LINK: https://leetcode.com/problems/best-time-to-buy-and-sell-stock-with-cooldown/description/
*/

class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int n = prices.size();

        // actions: 
        // hold = currently holding a stock (bought today or earlier)
        // sell = sold a stock today (note: next day has to be cooling down)
        // cool = cooling down (after selling yesterday or earlier) (note: we don't own a stock here)
        // for day 1
        int hold = -prices[0];
        int sell = 0;
        int cool = 0;

        for(int i = 1; i< n; i++){
            int pHold = hold;

            hold = max(hold, cool-prices[i]);
            cool = max(sell, cool);
            sell = pHold + prices[i];
        }   
        return max(sell, cool);
    }
};
