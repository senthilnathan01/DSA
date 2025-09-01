/*
Given an array of positive integers. Find the maximum length of Bitonic subsequence. 
A subsequence of array is called Bitonic if it is first strictly increasing, then strictly decreasing. Return the maximum length of bitonic subsequence.
 
Note : A strictly increasing or a strictly decreasing sequence should not be considered as a bitonic sequence

Link: https://www.geeksforgeeks.org/problems/longest-bitonic-subsequence0824/1
*/


class Solution {
  public:
    int LongestBitonicSequence(int n, vector<int> &nums) {
        vector<int> inc(n, 1);
        vector<int> dec(n, 1);
        int maxi = 0;
        for(int i = 0; i < n; i++){
            for(int j = 0; j < i; j++){
                if(nums[i]>nums[j] && inc[i] < 1 + inc[j]) inc[i] = 1 + inc[j];
            }
        }
        
        for(int i = n-1; i>=0; i--){
            for(int j = n-1; j > i; j--){
                if(nums[i]>nums[j] && dec[i] < 1 + dec[j]) dec[i] = 1 + dec[j];
            }
            if(inc[i]>1 && dec[i]>1) maxi = max(maxi, inc[i]+dec[i]-1);
        }
        
        return maxi;
    }
};
