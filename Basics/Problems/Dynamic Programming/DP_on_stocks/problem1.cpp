/*
You are given an array prices where prices[i] is the price of a given stock on the ith day.

You want to maximize your profit by choosing a single day to buy one stock and choosing a different day in the future to sell that stock.

Return the maximum profit you can achieve from this transaction. If you cannot achieve any profit, return 0.

Link: https://leetcode.com/problems/best-time-to-buy-and-sell-stock/description/
*/

class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int n = prices.size();
        if(n==1) return 0;
        int l = 0, r = 1;
        int maxP = 0;
        while(r < n){
            if(prices[l] < prices[r]) maxP = max(maxP, prices[r]- prices[l]);
            else l = r;
            r++;
        }
        return maxP;
    }
};

// Let's think of a DP approach to solve this

// These can be the states
// hold[i] = max profit on day i if we are holding a stock (bought today or before)
// notHold[i] = max profit on day if we are not holding a stock(sold today or before)

// Transition
// hold[i] = max(hold[i-1], -prices[i])
// notHold[i] = max(notHold[i-1], hold[i] + prices[i])

// Answer: notHold[n-1]
class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int n = prices.size();
        if(n==1) return 0;

        vector<int> hold(n, INT_MIN), notHold(n, INT_MIN);

        hold[0] = -prices[0];
        notHold[0] = 0;

        for(int i = 1; i < n; i++){
            hold[i] = max(hold[i-1], -prices[i]);
            notHold[i] = max(notHold[i-1], hold[i]+prices[i]);
        }
        return notHold[n-1];
    }
};
