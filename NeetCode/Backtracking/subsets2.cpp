/*
Given an integer array nums that may contain duplicates, return all possible subsets (the power set).

The solution set must not contain duplicate subsets. Return the solution in any order.

LINK: https://leetcode.com/problems/subsets-ii/description/
*/

class Solution {
public:
    vector<vector<int>> ans;
    void func(int idx, vector<int> &newVec, vector<int> &nums){
        ans.push_back(newVec);

        if(idx == nums.size()) return;

        for(int i = idx; i < nums.size(); i++){
            if(i > idx && nums[i]==nums[i-1]) continue;

            newVec.push_back(nums[i]);
            func(i+1, newVec, nums);
            newVec.pop_back();
        }
    }
    vector<vector<int>> subsetsWithDup(vector<int>& nums) {
        vector<int> newVec;
        sort(nums.begin(), nums.end());
        func(0, newVec, nums);
        return ans;
    }
};
