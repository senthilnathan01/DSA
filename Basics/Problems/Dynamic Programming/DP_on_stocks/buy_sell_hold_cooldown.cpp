/*
You are given an array prices where prices[i] is the price of a given stock on the ith day.

Find the maximum profit you can achieve. You may complete as many transactions as you like 
(i.e., buy one and sell one share of the stock multiple times) with the following restrictions:

After you sell your stock, you cannot buy stock on the next day (i.e., cooldown one day).
Note: You may not engage in multiple transactions simultaneously (i.e., you must sell the stock before you buy again).

Link: https://leetcode.com/problems/best-time-to-buy-and-sell-stock-with-cooldown/description/
*/

class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int n = prices.size();
        if(n==1) return 0;
        // Think of the actions 
        // Today u either hold or sell or cooldown 
        // Concentrate on three types of profit
        // profit_hold = max(profit_hold, profit_cooldown -prices[i-1])
        // profit_cooldown -> u can buy now -> u buy -> profit_holding = profit_cooldown -prices[i]
        //                                  -> u don't buy -> no change
        // profit_sell = profit_hold + prices[i]
        // also u should cooldown -> profit_cooldown = profit_sell

        // At the last day you would either sold or will be cooling down(or doing nothing)
        // Return max of the two

        // Three states
        int hold = -prices[0];
        int sell = 0;
        int cool = 0;

        for(int i = 1; i < n; i++){
            int prevHold = hold;
            int prevSell = sell;
            int prevCool = cool;

            hold = max(hold, prevCool - prices[i]); // u don't sell
            sell = prevHold + prices[i]; // u definitely sell today 
            cool = max(prevCool, prevSell); //{continuing cooling down / just start cooling}
        }

        return max(sell, cool);
    }
};
