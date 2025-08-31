/*
You are given an array prices where prices[i] is the price of a given stock on the ith day, and an integer fee representing a transaction fee.

Find the maximum profit you can achieve. You may complete as many transactions as you like, but you need to pay the transaction fee for each transaction.

Note:

You may not engage in multiple transactions simultaneously (i.e., you must sell the stock before you buy again).
The transaction fee is only charged once for each stock purchase and sale.

Link: https://leetcode.com/problems/best-time-to-buy-and-sell-stock-with-transaction-fee/description/
*/

// Now the profit is reduced by fee*(no of transactions)
// How do we reduce the number of transactions?
// We hold
// In such a way that the final realised profit is higher than even if u do many transactions 
// (they might be more profitable if there were no transaction fee)

class Solution {
public:
    int maxProfit(vector<int>& prices, int fee) {
        int n = prices.size();
        if(n==1) return 0;
        int hold = -prices[0];
        int tot = 0;

        for(int i = 1; i < n; i++){
            hold = max(hold, tot - prices[i]); // {hold or buy}
            tot = max(tot, hold + prices[i]- fee); //{do nothing or sell}
        }
        return tot;
    }
};
