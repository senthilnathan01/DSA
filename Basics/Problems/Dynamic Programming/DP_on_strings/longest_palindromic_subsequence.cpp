/*
Given a string s, find the longest palindromic subsequence's length in s.

A subsequence is a sequence that can be derived from another sequence by deleting some or no elements without changing the order of the remaining elements.

Link: https://leetcode.com/problems/longest-palindromic-subsequence/description/
*/

class Solution {
public:
    int longestPalindromeSubseq(string s) {
        int n = s.length();

        vector<vector<int>> dp(n+1, vector<int>(n+1, 0));
        for(int i = n; i >= 1; i--){
            for(int j = 1; j <=n; j++){
                if(i>j) dp[i][j] = 0;
                else if(i==j) dp[i][j] = 1;
                else{
                    if(s[i-1] == s[j-1]) dp[i][j] = 2 + dp[i+1][j-1];
                    else dp[i][j] = max(dp[i+1][j], dp[i][j-1]);
                }
            }
        }

        return dp[1][n];
    }
};
