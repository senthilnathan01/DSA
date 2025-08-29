/*
You are given two strings s1 and s2. Your task is to print all distinct longest common subsequences in lexicographical order.

Note: A subsequence is derived from another string by deleting some or none of the elements without changing the order of the remaining elements.

Link: https://www.geeksforgeeks.org/problems/print-all-lcs-sequences3413/1
*/

class Solution {
  public:
    vector<vector<int>> dp;
    map<pair<int,int>, set<string>> memo;
    int n = 0, m = 0;
    void fillTable(string &s1, string &s2){
        for(int i = 1; i <= n; i++){
            for(int j =1; j <= m; j++){
                if(s1[i-1]==s2[j-1]) dp[i][j] = 1 + dp[i-1][j-1];
                else dp[i][j] = max(dp[i-1][j], dp[i][j-1]);
            }
        }
    }
    
    set<string> getLCS(string &s1, string &s2, int i, int j){
        if(i==0 || j==0) return {""};
        
        if(memo.count({i,j})) return memo[{i, j}];
        
        set<string> res;
        
        if(s1[i-1]==s2[j-1]){
            set<string> res1 = getLCS(s1, s2, i-1, j-1);
            for(auto s: res1){
                res.insert(s + s1[i-1]);
            }
        }
        else
        {
            if(dp[i-1][j]>=dp[i][j-1]){
                set<string> res2 = getLCS(s1, s2, i-1, j);
                res.insert(res2.begin(), res2.end());
            }
            if(dp[i][j-1]>=dp[i-1][j]){
                set<string> res3 = getLCS(s1, s2, i, j-1);
                res.insert(res3.begin(), res3.end());
            }
        }
        return memo[{i, j}] = res;
        
    }
    
    vector<string> allLCS(string &s1, string &s2) {
        n = s1.size(), m = s2.size();
        
        // Fill the dp table
        dp.assign(n+1, vector<int>(m+1, 0));
        fillTable(s1, s2);
        
        // Get the LCS strings
        set<string> ansSet = getLCS(s1, s2, s1.length(), s2.length());
        
        vector<string> ans(ansSet.begin(), ansSet.end());
        return ans;
    }
};
