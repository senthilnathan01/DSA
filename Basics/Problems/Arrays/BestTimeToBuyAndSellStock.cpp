#include<iostream>
#include<vector>

using namespace std;

/*
You are given an array prices where prices[i] is the price of a given stock on the ith day.

You want to maximize your profit by choosing a single day to buy one stock and choosing a different day in the future to sell that stock.

Return the maximum profit you can achieve from this transaction. If you cannot achieve any profit, return 0.
*/
// Optimal Approach using Kadane's Algo
// TC = O(N)
// SC = O(1)
int maxProfit(vector<int>& prices) {
    int minPrice = prices[0];
    int profit = 0;
    int n = prices.size();
    for(int i = 1; i < n; i++)
    {
        int diff = prices[i]-minPrice;
        profit = max(profit, diff);
        minPrice = min(minPrice, prices[i]);
    }
    return profit;
}

int main()
{
    vector<int> prices = {7,1,5,3,6,4};
    cout<<maxProfit(prices);
}

// OUTPUT:
// 5
