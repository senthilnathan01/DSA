/*
Given an input string (s) and a pattern (p), implement wildcard pattern matching with support for '?' and '*' where:

'?' Matches any single character.
'*' Matches any sequence of characters (including the empty sequence).
The matching should cover the entire input string (not partial).

Link: https://leetcode.com/problems/wildcard-matching/description/
*/

class Solution {
public:
    vector<vector<int>> dp;
    bool func(int i, int j, string &s, string &p){
        if (dp[i][j] != -1) return dp[i][j];

        // Base Case
        if(i==0 && j ==0) return true;
        if(j==0) return false;
        if(i==0)
        {
            for(int k = 1; k <= j; k++) if(p[k-1]!='*') return dp[i][j]=false;
            return dp[i][j]=true;
        }

        if(p[j-1]==s[i-1] || p[j-1] == '?') return dp[i][j]=func(i-1, j-1, s, p);
        
        if(p[j-1] == '*') return dp[i][j]=func(i-1, j, s, p) || func(i, j-1, s, p);
        return dp[i][j]=false;
    }

    bool isMatch(string s, string p) {
        int n = s.length(), m = p.length();
        dp.assign(n+1, vector<int>(m+1, -1));

        return func(n, m, s, p);
    }
};

// Tabulation Approach
class Solution {
public:
    bool isMatch(string s, string p) {
        int n = s.length(), m = p.length();

        // dp[i][j] = true represents that first i chars in s can be matched by first j in p
        // we only current row and previous row

        vector<int> prev(m+1, 0), curr(m+1, 0);
        // represents whether curr[j] (the first j chars in p) can match s[0..i]
        // we go about by checking for i =0 to n-1 of s

        // Setting up the base case
        // Can an empty s be matched?
        // Yes, only empty p or p fully filled with '*'
        prev[0] = 1;
        for(int j = 1; j <= m; j++) if(p[j-1]=='*') prev[j] = prev[j-1];

        for(int i = 1; i <= n; i++){
            // Can a non empty s be matched by empty p? No
            curr[0] = false;
            for(int j = 1; j <= m; j++){
                // Here comes the three rules

                // matched one char
                if(p[j-1]==s[i-1] || p[j-1]=='?') curr[j] = prev[j-1];
                // curr[j-1] for using * for not matching i.e., using it for empty
                // prev[j] for using * for matching one more char from prev
                else if(p[j-1]=='*') curr[j] = curr[j-1] || prev[j];
                // mismatch
                else curr[j] = false;
            }
            prev = curr;
        }
        return prev[m];
    }
};
