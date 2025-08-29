/*
Given two strings str1 and str2, return the shortest string that has both str1 and str2 as subsequences. If there are multiple valid strings, return any of them.

A string s is a subsequence of string t if deleting some number of characters from t (possibly 0) results in the string s.

Link: https://leetcode.com/problems/shortest-common-supersequence/description/
*/

class Solution {
public:
    map<pair<int, int>, string> memo; 
    string shortestCommonSupersequence(string str1, string str2) {
        int n = str1.size(), m = str2.size();

        vector<vector<int>> dp(n+1, vector<int>(m+1));
        
        for(int i = 1; i <= n; i++){
            for(int j = 1; j <= m; j++){
                if(str1[i-1]==str2[j-1]) dp[i][j] = 1 + dp[i-1][j-1]; 
                else dp[i][j] = max(dp[i-1][j], dp[i][j-1]);
            }
        }

        int i = n,j = m;
        string ans;
        while(i>0 && j >0)
        {
            if(str1[i-1]==str2[j-1])
            {
                ans += str1[i-1];
                i--;
                j--;
            }
            else if(dp[i-1][j]>=dp[i][j-1])
            {
                ans += str1[i-1];
                i--;
            }
            else
            {
                ans += str2[j-1];
                j--;
            }
        }

        while(i>0) ans += str1[--i];
        while(j>0) ans += str2[--j];
        reverse(ans.begin(), ans.end());
        return ans;
    }
};
