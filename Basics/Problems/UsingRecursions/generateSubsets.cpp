/*
Given an integer array nums of unique elements, return all possible subsets (the power set).

The solution set must not contain duplicate subsets. Return the solution in any order.

LeetCode Link: https://leetcode.com/problems/subsets/description/
*/

// TC = O(2^n * n)
// SC = O(N) -> For the recursion Tree
class Solution {
public:
    vector<vector<int>> subsets(vector<int>& nums) {
        vector<vector<int>> ans;
        vector<int> newVec;
        func(0, ans, newVec, nums);
        return ans;
    }

    void func(int idx, vector<vector<int>> &ans, vector<int> &newVec, vector<int>& nums)
    {
        if(idx==nums.size())
        {
            ans.push_back(newVec);
            return;
        }

        // Include current element
        newVec.push_back(nums[idx]);
        func(idx +1, ans, newVec, nums);
        newVec.pop_back();

        // Exclude current element
        func(idx + 1, ans, newVec, nums);
    }
};
