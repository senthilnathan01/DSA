/*
You are given an array prices where prices[i] is the price of a given stock on the ith day.

Find the maximum profit you can achieve. You may complete at most two transactions.

Note: You may not engage in multiple transactions simultaneously (i.e., you must sell the stock before you buy again).

Link: https://leetcode.com/problems/best-time-to-buy-and-sell-stock-iii/description/
*/

// Approach 1
class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int n = prices.size();
        if(n==1) return 0;
        
        vector<int> profit1(n, 0);
        int mini = prices[0];
        int profit = 0;
        for(int i = 1; i <n; i++){
            mini = min(mini, prices[i]);
            profit = max(profit, prices[i]-mini);
            profit1[i] = profit;
        }

        vector<int> profit2(n, 0);
        int maxi = prices[n-1];
        profit = 0;
        for(int i = n-2; i >=0; i--){
            maxi = max(maxi, prices[i]);
            profit = max(profit, maxi - prices[i]);
            profit2[i] = profit;
        }

        profit = 0;
        for(int i = 0; i < n-1; i++){
            profit = max(profit, profit2[i] + profit1[i]);
        }

        profit = max(profit, max(profit2[0], profit1[n-1]));
        return profit;
    }
};

// Approach 2
class Solution {
public:
    int maxProfit(vector<int>& prices) {
        // profit1 -> prices[i] - buy1
        // here minimize buy1 and maximise profit1
        // profit2 -> prices[i] - buy2
        // here minimize buy2 and maximise profit2
        // buy2 happens after profit1
        // buy2 -> prices[i]-profit1
        int n = prices.size();
        int profit1 = 0;
        int buy1 = INT_MAX;
        int profit2 = 0;
        int buy2 = INT_MAX;
        for(int i = 0; i < n; i++){
            buy1 = min(buy1, prices[i]);
            profit1 = max(profit1, prices[i]-buy1);
            buy2 = min(buy2, prices[i]-profit1);
            profit2 = max(profit2, prices[i]-buy2);
        }
        return profit2;
    }
};
