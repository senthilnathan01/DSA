/*
You are given an integer array nums and an integer target.

You want to build an expression out of nums by adding one of the symbols '+' and '-' before each integer in nums and then concatenate all the integers.

For example, if nums = [2, 1], you can add a '+' before 2 and a '-' before 1 and concatenate them to build the expression "+2-1".
Return the number of different expressions that you can build, which evaluates to target.

Link: https://leetcode.com/problems/target-sum/description/
*/

// Very Easy Recursive Solution
class Solution {
public:
    int combos(int i, int currSum, int target, vector<int> &nums)
    {
        if(i==nums.size()) return (currSum == target);

        return combos(i+1, currSum + nums[i], target, nums) + combos(i+1, currSum - nums[i], target, nums);
    }
    int findTargetSumWays(vector<int>& nums, int target) {
        return combos(0, 0, target, nums);
    }
};

// The above one has 2^n time complexity!
// Let's maketh this more efficient
class Solution {
public:
    int findTargetSumWays(vector<int>& nums, int target) {
        long long totSum = accumulate(nums.begin(), nums.end(), 0LL);

        if(target > totSum || target < -1*totSum || (target + totSum)%2!=0) return 0;

        long long subsetSum = (target + totSum)/2;

        vector<int> dp(subsetSum + 1, 0);

        dp[0] = 1;

        for(int num: nums){
            for(int j = subsetSum; j >=num; j--){
                dp[j] = dp[j] + dp[j-num];
            }
        }

        return dp[subsetSum];
    }
};




