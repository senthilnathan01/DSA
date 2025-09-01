/*
You are given an array of integers arr[], return the Longest Increasing Subsequence (LIS) of the given array.
LIS is the longest subsequence where each element is strictly greater than the previous one.
Note: If multiple LIS of the same maximum length exist, return the one that appears first based on the 
lexicographical order of their indices (i.e., the earliest combination of positions from the original sequence).

Link: https://www.geeksforgeeks.org/problems/printing-longest-increasing-subsequence/1
*/

class Solution {
  public:
    vector<int> getLIS(vector<int>& arr) {
        int n = arr.size();

        vector<int> dp(n, 1);
        vector<int> prevIdx(n);

        int maxIdx = 0;
        for(int i = 0; i < n; i++){
            prevIdx[i] = i;
            for(int prev = 0; prev < i; prev++){
                if(arr[i]>arr[prev] && 1 + dp[prev]> dp[i]){
                    prevIdx[i] = prev;
                    dp[i] = 1 + dp[prev];
                }
            }
            if(dp[maxIdx] < dp[i]) maxIdx = i;
        }
        vector<int> ans;
        while(prevIdx[maxIdx]!=maxIdx){
            ans.push_back(arr[maxIdx]);
            maxIdx = prevIdx[maxIdx];
        }
        ans.push_back(arr[maxIdx]);
        
        reverse(ans.begin(), ans.end());
        return ans;
        
    }
};
