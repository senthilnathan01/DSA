/*
You are climbing a staircase. It takes n steps to reach the top.

Each time you can either climb 1 or 2 steps. In how many distinct ways can you climb to the top?

LeetCode Link: https://leetcode.com/problems/climbing-stairs/description/
*/

class Solution {
public:
    int climbStairs(int n) {
        int prev2 = 1;
        int prev = 2;
        
        if(n == 1) return prev2;
        if(n == 2) return prev;

        for(int i = 3; i <= n; i++)
        {
            int curr = prev2 + prev;
            prev2 = prev;
            prev = curr;
        }

        return prev;
    }
};
