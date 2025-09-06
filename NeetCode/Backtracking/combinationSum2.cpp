/*
Given a collection of candidate numbers (candidates) and a target number (target), 
find all unique combinations in candidates where the candidate numbers sum to target.

Each number in candidates may only be used once in the combination.

Note: The solution set must not contain duplicate combinations.

LINK: https://leetcode.com/problems/combination-sum-ii/description/
*/

class Solution {
public:
    vector<vector<int>> ans;
    void func(int idx, int n, vector<int> &newVec, vector<int> &nums, int target){
        if(target==0){
            ans.push_back(newVec);
            return;
        }

        for(int i = idx; i < nums.size(); i++){
            if(i>idx && nums[i]==nums[i-1]) continue;

            newVec.push_back(nums[i]);
            func(i+1, n, newVec, nums, target-nums[i]);
            newVec.pop_back();
        }
    }
    vector<vector<int>> combinationSum2(vector<int>& candidates, int target) {
        vector<int> nums = candidates;
        sort(nums.begin(), nums.end());
        vector<int> newVec;
        func(0, nums.size(), newVec, nums, target);
        return ans;
    }
};
