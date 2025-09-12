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

// Let's step up this more?
// Key change: Only one vector instead of two
// Iterating backwards
// If u see curr[j] only depends on prev[j] (which is what curr was previously)
// we don't even need this
// But we can't directly replace prev with curr
// We can if we iterate backwards as the values wouldn't have changed

class Solution {
public:
    int numDistinct(string s, string t) {
        int m = s.length(), n = t.length();
        // a non empty/empty s can match empty t as it has empty string
        vector<uint64_t> curr(n+1, 0);
        curr[0] = 1;

        for(int i = 1; i <= m; i++){
            for(int j = n; j >= 1; j--){
                // only one case
                // if pointer at s matches the pointer at t
                if(s[i-1]==t[j-1]) curr[j] += curr[j-1];
            }
        }
        return (int)curr[n];
    }
};
