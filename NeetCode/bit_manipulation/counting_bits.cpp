/*
Given an integer n, return an array ans of length n + 1 such that for each i (0 <= i <= n), 
ans[i] is the number of 1's in the binary representation of i.

LINK: https://leetcode.com/problems/counting-bits/description/
*/

class Solution {
public:
    vector<int> countBits(int n) {
        vector<int> ans(n+1);
        ans[0]=0;
        for(int i =1; i <=n; i++){
            if(i&1) ans[i] = 1 + ans[i-1];
            else ans[i] = ans[i/2];
        }
        return ans;
    }
};
