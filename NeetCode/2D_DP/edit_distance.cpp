/*
Given two strings word1 and word2, return the minimum number of operations required to convert word1 to word2.

You have the following three operations permitted on a word:

Insert a character
Delete a character
Replace a character

LINK: https://leetcode.com/problems/edit-distance/description/
*/

class Solution {
public:
    int minDistance(string word1, string word2) {
        int m = word1.length(), n = word2.length();
        vector<vector<int>> dp(m+1, vector<int>(n+1, 0));
        for(int i = 0; i <= m; i++) dp[i][0] = i;
        for(int j = 0; j <= n; j++) dp[0][j] = j;
        for(int i = 1; i <=m; i++){
            for(int j = 1; j <= n; j++){
                // if they match u do nothing
                if(word1[i-1]==word2[j-1]) dp[i][j] = dp[i-1][j-1];
                // if they don't u take min and add 1 (cuz we do the op to try and match)
                else dp[i][j] = 1 + min({dp[i-1][j], dp[i][j-1], dp[i-1][j-1]});
            }
        }
        return dp[m][n];
    }
};

// Some space optimisation as dp[i] only depends on dp[i-1] and dp[i]
class Solution {
public:
    int minDistance(string word1, string word2) {
        int m = word1.length(), n = word2.length();

        // Ensure word2 is the shorter one (to minimize memory usage)
        if (n > m) return minDistance(word2, word1);

        vector<int> prev(n+1), curr(n+1);
      
        for (int j = 0; j <= n; j++) prev[j] = j;

        for (int i = 1; i <= m; i++) {
            curr[0] = i; // dp[i][0] = i (delete all from word1)
            for (int j = 1; j <= n; j++) {
                if (word1[i-1] == word2[j-1]) curr[j] = prev[j-1]; 
                // delete, insert, replace
                else curr[j] = 1 + min({prev[j], curr[j-1], prev[j-1]});
            }
            prev = curr;
        }
        return prev[n];
    }
};
