/*
You are given a boolean expression s containing
    'T' ---> true
    'F' ---> false 
and following operators between symbols
   &   ---> boolean AND
    |   ---> boolean OR
   ^   ---> boolean XOR
Count the number of ways we can parenthesize the expression so that the value of expression evaluates to true.

Note: The answer is guaranteed to fit within a 32-bit integer.

Link: https://www.geeksforgeeks.org/problems/boolean-parenthesization5610/1
*/

// User function Template for C++
class Solution {
  public:
    vector<vector<vector<int>>> dp;
    int func(int i, int j, string &s, bool evaluateForTrue){
        if(i == j) {
            if(evaluateForTrue) return s[i] == 'T'; 
            else return s[i] == 'F';
        }
        
        if(dp[i][j][evaluateForTrue]!=-1) return dp[i][j][evaluateForTrue];
        
        int ans = 0;
        for(int opIdx = i+1; opIdx <= j-1; opIdx+=2){
            int LF = func(i, opIdx -1, s, false);
            int LT = func(i, opIdx -1, s, true);
            int RF = func(opIdx + 1, j, s, false);
            int RT = func(opIdx + 1, j, s, true);
            
            if(s[opIdx]=='|'){
                if(evaluateForTrue) ans += LF*RT + RF*LT + LT*RT;
                else ans += LF*RF;
            }
            else if(s[opIdx]=='&'){
                if(evaluateForTrue) ans += LT*RT;
                else ans += LF*RT + RF*LT + LF*RF;
            }
            else if(s[opIdx]=='^'){
                if(evaluateForTrue) ans += LT*RF + LF*RT;
                else ans += LT*RT + LF*RF;
            }
        }
        return dp[i][j][evaluateForTrue]=ans;
    }
    
    int countWays(string &s) {
        int n = s.size();
        dp.assign(n, vector<vector<int>>(n, vector<int>(2, -1)));
        return func(0, n-1, s, true);
    }
};
