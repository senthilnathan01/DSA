/*
You are given an integer array nums. You are initially positioned at the array's first index, 
and each element in the array represents your maximum jump length at that position.

Return true if you can reach the last index, or false otherwise.

LINK: https://leetcode.com/problems/jump-game/description/
*/
class Solution {
public:
    bool canJump(vector<int>& nums) {
        int n = nums.size();
        int goodPos = n-1;
        for(int i = n-2; i >= 0; i--){
            if(nums[i]+i >= goodPos) goodPos = i;
        }
        return goodPos == 0;
    }
};
