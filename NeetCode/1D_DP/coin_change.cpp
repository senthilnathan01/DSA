/*
You are given an integer array coins representing coins of different denominations and an integer amount representing a total amount of money.

Return the fewest number of coins that you need to make up that amount. If that amount of money cannot be made up by any combination of the coins, return -1.

You may assume that you have an infinite number of each kind of coin.

Link: https://leetcode.com/problems/coin-change/description/
*/

class Solution {
public:
    int coinChange(vector<int>& coins, int amount) {
        if(amount == 0) return 0;

        vector<int> dp(amount +1, INT_MAX);
        dp[0] = 0;

        for(int coin: coins){
            for(int j = coin; j <= amount; j++) if(dp[j-coin]!=INT_MAX) dp[j] = min(dp[j], 1 + dp[j-coin]);
        }
        return dp[amount] == INT_MAX ? -1 : dp[amount];
    }
};
