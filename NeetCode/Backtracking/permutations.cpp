/*
Given an array nums of distinct integers, return all the possible permutations. You can return the answer in any order.

LINK: https://leetcode.com/problems/permutations/description/
*/

class Solution {
public:
    vector<vector<int>> ans;
    void func(int idx, vector<int> &nums){
        if(idx==nums.size()){
            ans.push_back(nums);
            return;
        }

        for(int i = idx; i < nums.size(); i++){
            swap(nums[idx], nums[i]);
            func(idx+1, nums);
            swap(nums[idx], nums[i]);
        }
    }
    vector<vector<int>> permute(vector<int>& nums) {
        func(0, nums);
        return ans;
    }
};
