/*
There is a long table with a line of plates and candles arranged on top of it. You are given a 0-indexed string s consisting of characters '*' and '|' only, where a '*' represents a plate and a '|' represents a candle.

You are also given a 0-indexed 2D integer array queries where queries[i] = [lefti, righti] denotes the substring s[lefti...righti] (inclusive). For each query, you need to find the number of plates between candles that are in the substring. A plate is considered between candles if there is at least one candle to its left and at least one candle to its right in the substring.

For example, s = "||**||**|*", and a query [3, 8] denotes the substring "*||**|". The number of plates between candles in this substring is 2, as each of the two plates has at least one candle in the substring to its left and right.
Return an integer array answer where answer[i] is the answer to the ith query.

LINK: https://leetcode.com/problems/plates-between-candles/description/
*/

class Solution {
public:
    vector<int> platesBetweenCandles(string s, vector<vector<int>>& queries) {
        // Plan:
        // Count plates before and including index i and store it in a 'plates' list 
        // For query check whether the two plates are there and then return plates[right candle] - plates[left candle]
        // To check the location of the left and right candle maintain two list 
        // One list: closest candle to the left 
        // Another: closest candle to the right
        int n = s.size();
        // Gonna follow one based indexing
        vector<int> plates(n+1, 0);
        for(int i = 1; i <= n; i++) plates[i] = (s[i-1] == '*' ? plates[i-1]+1 : plates[i-1]);

        vector<int> closestLeftCandle(n+1);
        int leftCandle = -1;
        for(int i = 1; i <= n; i++){
            if(s[i-1]=='|') leftCandle = i;
            closestLeftCandle[i] = leftCandle;
        }

        vector<int> closestRightCandle(n+1);
        int rightCandle = -1;
        for(int i  = n; i >=1; i--){
            if(s[i-1]=='|') rightCandle = i;
            closestRightCandle[i] = rightCandle;
        }

        vector<int> ans;
        for(auto q: queries){
            // Check for correct position of plates
            // plates should not be -1 (non existent) and rightCandle should be to the right of the leftCandle ofc
            // Because we follow 1 based indexing
            int R = closestLeftCandle[q[1]+1];
            int L = closestRightCandle[q[0]+1];
            if(L == -1 || R ==-1 || R <= L) ans.push_back(0);
            else ans.push_back(plates[R] - plates[L]);
        }
        return ans;
    }
};
