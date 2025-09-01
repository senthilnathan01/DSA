/*
Given a set of distinct positive integers nums, return the largest subset answer such 
that every pair (answer[i], answer[j]) of elements in this subset satisfies:

answer[i] % answer[j] == 0, or
answer[j] % answer[i] == 0
If there are multiple solutions, return any of them.

Link: https://leetcode.com/problems/largest-divisible-subset/description/
*/

// Only new thing compare to LIS
// Sorting
// Checking for divisibility instead of strictly increasing condition
class Solution {
public:
    vector<int> largestDivisibleSubset(vector<int>& nums) {
        vector<int> temp = nums;
        sort(temp.begin(), temp.end());

        int n = temp.size();
        vector<int> dp(n, 1);
        vector<int> prevIdx(n);
        int maxIdx = 0;
        for(int i = 0; i < n; i++){
            prevIdx[i] = i;
            for(int prev = 0; prev < i; prev++){
                if(temp[i] % temp[prev] == 0 && dp[i] < 1 + dp[prev]){
                    dp[i] = 1 + dp[prev];
                    prevIdx[i] = prev;
                }
            }
            if(dp[i]>dp[maxIdx]) maxIdx = i;
        }

        vector<int> ans;
        while(prevIdx[maxIdx] != maxIdx){
            ans.push_back(temp[maxIdx]);
            maxIdx = prevIdx[maxIdx];
        }
        ans.push_back(temp[maxIdx]);
        return ans;
    }
};
