/*
Given strings s1, s2, and s3, find whether s3 is formed by an interleaving of s1 and s2.

An interleaving of two strings s and t is a configuration where s and t are divided into n and m substrings respectively, such that:

s = s1 + s2 + ... + sn
t = t1 + t2 + ... + tm
|n - m| <= 1
The interleaving is s1 + t1 + s2 + t2 + s3 + t3 + ... or t1 + s1 + t2 + s2 + t3 + s3 + ...
Note: a + b is the concatenation of strings a and b.

LINK: https://leetcode.com/problems/interleaving-string/description/
*/

// Using 2D
class Solution {
public: 
    bool isInterleave(string s1, string s2, string s3) {
        int a = s1.length(), b = s2.length(), c = s3.length();

        if(a+b!=c) return false;

        vector<vector<bool>> dp(a+1, vector<bool>(b+1, 0));
        dp[0][0] = true;
        for(int i = 1; i <= a; i++) if(dp[i-1][0] && s1[i-1]==s3[i-1]) dp[i][0] = true;
        for(int j = 1; j <= b; j++) if(dp[0][j-1] && s2[j-1]==s3[j-1]) dp[0][j] = true;

        for(int i = 1; i <= a; i++){
            for(int j = 1; j <= b; j++){
                if((dp[i-1][j] && s1[i-1] == s3[i+j-1]) ||
                (dp[i][j-1] && s2[j-1]==s3[i+j-1])) dp[i][j] = true;
            }
        }

        return dp[a][b];
    }
};


