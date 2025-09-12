/*
You are given an integer array nums and an integer target.

You want to build an expression out of nums by adding one of the symbols '+' and '-' before each integer in nums and then concatenate all the integers.

For example, if nums = [2, 1], you can add a '+' before 2 and a '-' before 1 and concatenate them to build the expression "+2-1".
Return the number of different expressions that you can build, which evaluates to target.

LINK: https://leetcode.com/problems/target-sum/description/
*/

class Solution {
public:
    unordered_map<string, int> dp;
    int func(int idx, int n, vector<int> &nums, int target){
        if(idx==n) return target==0 ? 1 : 0;
        string key = to_string(idx) + ',' + to_string(target);
        if(dp.find(key)!=dp.end()) return dp[key];
        return dp[key] = func(idx+1, n, nums, target+nums[idx]) + func(idx+1, n, nums, target-nums[idx]);
    }
    int findTargetSumWays(vector<int>& nums, int target) {
        return func(0, nums.size(), nums, target);
    }
};

// Better memoization instead of string concatenation
class Solution {
public:
    int dp[21][2001];
    vector<int> suff;

    int func(int idx, int n, vector<int> &nums, int target){
        if(idx==n) return target==0 ? 1 : 0;

        if (abs(target) > suff[idx]) return 0;
        
        int offset = target + 1000;
        if(dp[idx][offset]!=-1) return dp[idx][offset];

        return dp[idx][offset] = func(idx+1, n, nums, target+nums[idx]) + func(idx+1, n, nums, target-nums[idx]);
    }
    int findTargetSumWays(vector<int>& nums, int target) {
        memset(dp, -1, sizeof(dp));
        int n = nums.size();
        suff.assign(n+1, 0);
        for(int i = n-1; i >= 0; i--) suff[i] = suff[i+1] + nums[i];
        return func(0, n, nums, target);
    }
};
