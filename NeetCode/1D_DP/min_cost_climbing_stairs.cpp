/*
You are given an integer array cost where cost[i] is the cost of ith step on a staircase. Once you pay the cost, you can either climb one or two steps.

You can either start from the step with index 0, or the step with index 1.

Return the minimum cost to reach the top of the floor.

LINK: https://leetcode.com/problems/min-cost-climbing-stairs/description/
*/

class Solution {
public:
    int minCostClimbingStairs(vector<int>& cost) {
        int n = cost.size();
        if(n==2) return min(cost[0], cost[1]);

        int prev1 = cost[0], prev2 = cost[1], curr;
        for(int i = 2; i < n; i++){
            curr = cost[i] + min(prev1, prev2);
            prev1 = prev2;
            prev2 = curr;
        }
        return min(prev1, prev2);
    }   
};
