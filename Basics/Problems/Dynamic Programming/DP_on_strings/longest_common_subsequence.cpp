/*
Given two strings text1 and text2, return the length of their longest common subsequence. If there is no common subsequence, return 0.

A subsequence of a string is a new string generated from the original string with some characters (can be none) deleted without changing the relative order of the remaining characters.

For example, "ace" is a subsequence of "abcde".
A common subsequence of two strings is a subsequence that is common to both strings.

Link: https://leetcode.com/problems/longest-common-subsequence/description/
*/

// Recursion
class Solution {
public:
    int func(int i, int j, vector<vector<int>> &dp, string &text1, string &text2){
        if(i<0 || j<0) return 0;

        if(dp[i][j]!=-1) return dp[i][j];

        return text1[i]==text2[j] ? dp[i][j] = func(i-1, j-1, dp, text1, text2) + 1 : dp[i][j] = max(func(i-1, j, dp, text1, text2), func(i, j-1, dp, text1, text2));
    }
    int longestCommonSubsequence(string text1, string text2) {
        // dp[i][j] = dp[i-1][j-1] + 1 if text1[i] == text[j]
        // else dp[i][j] = max(dp[i-1][j], dp[i][j-1]) 
        int n = text1.size(), m = text2.size();

        vector<vector<int>> dp(n, vector<int>(m, -1));
        return func(n-1, m-1, dp, text1, text2);
    }
};

// Tabulation
class Solution {
public:
    int func(int i, int j, vector<vector<int>> &dp, string &text1, string &text2){
        if(i<0 || j<0) return 0;

        if(dp[i][j]!=-1) return dp[i][j];

        return text1[i]==text2[j] ? dp[i][j] = func(i-1, j-1, dp, text1, text2) + 1 : dp[i][j] = max(func(i-1, j, dp, text1, text2), func(i, j-1, dp, text1, text2));
    }
    int longestCommonSubsequence(string text1, string text2) {
        int n = text1.size(), m = text2.size();

        vector<vector<int>> dp(n+1, vector<int>(m+1, -1));
        for(int i = 0; i<=n; i++) dp[i][0] = 0;
        for(int j = 0; j<=m; j++) dp[0][j] = 0;
        for(int i = 1; i<=n; i++){
            for(int j = 1; j <=m; j++){
                if(text1[i-1]==text2[j-1]) dp[i][j] = 1 + dp[i-1][j-1];
                else dp[i][j] = max(dp[i][j-1], dp[i-1][j]);
            }
        }

        return dp[n][m];
    }
};
