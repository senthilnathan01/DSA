/*
You are given a 0-indexed array of integers nums of length n. You are initially positioned at index 0.

Each element nums[i] represents the maximum length of a forward jump from index i. In other words, if you are at index i, you can jump to any index (i + j) where:

0 <= j <= nums[i] and
i + j < n
Return the minimum number of jumps to reach index n - 1. The test cases are generated such that you can reach index n - 1.

LINK: https://leetcode.com/problems/jump-game-ii/description/
*/

class Solution {
public:
    int jump(vector<int>& nums) {
        for(int i = 1; i < nums.size(); i++) nums[i] = max(nums[i]+i, nums[i-1]);
        int i = 0;
        int ans = 0;
        while(i <= nums.size()-2){
            ans++;
            i = nums[i];
        }
        return (i>=nums.size()-1) ? ans : -1;
    }
};
