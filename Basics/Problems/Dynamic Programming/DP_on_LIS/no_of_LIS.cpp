/*
Given an integer array nums, return the number of longest increasing subsequences.

Notice that the sequence has to be strictly increasing.

Link: https://leetcode.com/problems/number-of-longest-increasing-subsequence/description/
*/

class Solution {
public:
    int findNumberOfLIS(vector<int>& nums) {
        int n = nums.size();
        if(n==1) return 1;

        vector<int> len(n, 1);
        vector<int> cnt(n, 1);

        int maxL = 1;
        for(int i = 0; i < n; i++){
            for(int j = 0; j < i; j++){
                if(nums[i]>nums[j]){
                    if(len[j]+1>len[i]){
                        len[i] = len[j] + 1;
                        cnt[i] = cnt[j];
                    }
                    else if(len[j]+1 == len[i]){
                        cnt[i] += cnt[j];
                    }
                }
            }
            maxL = max(maxL, len[i]);
        }
        int ans = 0;
        for(int i = 0; i < n; i++){
            if(len[i]==maxL) ans += cnt[i];
        } 
        return ans;
    }
};
