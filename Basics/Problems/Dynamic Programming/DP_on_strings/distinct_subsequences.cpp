/*
Given two strings s and t, return the number of distinct subsequences of s which equals t.

The test cases are generated so that the answer fits on a 32-bit signed integer.

Link: https://leetcode.com/problems/distinct-subsequences/description/
*/

class Solution {
public:
    int numDistinct(string s, string t) {
        int n = s.size(), m = t.size();
        
        vector<vector<uint64_t>> dp(n+1, vector<uint64_t>(m+1, 0));

        for(int i = 0; i <= n; i++) dp[i][0] = 1;

        for(int i = 1; i <= n; i++){
            for(int j = 1; j <= m; j++){
                if(s[i-1]==t[j-1]) dp[i][j] = dp[i-1][j-1] + dp[i-1][j];
                else dp[i][j] = dp[i-1][j];
            }
        }

        return (int)dp[n][m];
    }
};

// Optimized further
class Solution {
public:
    int numDistinct(string s, string t) {
        int n = s.size(), m = t.size();

        vector<uint64_t> prev(m+1, 0), curr(m+1, 0);
        prev[0] = 1;

        for(int i = 1; i <= n; i++){
            curr[0] = 1;
            for(int j = 1; j <= m; j++){
                if(s[i-1]==t[j-1]) curr[j] = prev[j-1] + prev[j];
                else curr[j] = prev[j];
            }
            prev.swap(curr);
        }

        return (int)prev[m];
    }
};
