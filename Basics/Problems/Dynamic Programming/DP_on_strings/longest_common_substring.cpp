/*
You are given two strings s1 and s2. Your task is to find the length of the longest common substring among the given strings.

Link: https://www.geeksforgeeks.org/problems/longest-common-substring1452/1
*/

class Solution {
  public:
    int longestCommonSubstr(string& s1, string& s2) {
        int n = s1.size(), m = s2.size();
        
        vector<vector<int>> dp(n+1, vector<int>(m+1, 0));
        int ans = -1;
        for(int i = 1; i <= n; i++){
            for(int j = 1; j <= m; j++){
                if(s1[i-1]==s2[j-1]) dp[i][j] = 1 + dp[i-1][j-1];
                else dp[i][j] = 0;
                ans = max(ans, dp[i][j]);
            }
        }
        
        return ans;
    }
};
