class Solution {
public:
    int longestCommonSubsequence(string text1, string text2) {
        int t1s = text1.size(), t2s = text2.size();
        vector<vector<int>> dp(t1s+1, vector<int>(t2s+1, 0));
        for(int i = 1; i <= t1s; i++){
            for(int j = 1; j <= t2s; j++){
                if(text1[i-1]==text2[j-1]) dp[i][j] = 1 + dp[i-1][j-1];
                else dp[i][j] = max(dp[i-1][j], dp[i][j-1]);
            }
        }
        return dp[t1s][t2s];
    }
};
