/*
Given a string s. In one step you can insert any character at any index of the string.

Return the minimum number of steps to make s palindrome.

A Palindrome String is one that reads the same backward as well as forward.

Link: https://leetcode.com/problems/minimum-insertion-steps-to-make-a-string-palindrome/description/
*/

class Solution {
public:
    int minInsertions(string s) {
        int n = s.length();

        vector<vector<int>> dp(n+1, vector<int>(n+1));
        for(int i = n; i >= 1; i--){
            for(int j = i; j <= n; j++){
                if(i==j) dp[i][j] = 1;
                else{
                    if(s[i-1]==s[j-1]) dp[i][j] = 2 + dp[i+1][j-1];
                    else dp[i][j] = max(dp[i+1][j], dp[i][j-1]);
                }
            }
        }

        return n -dp[1][n];
    }
};
