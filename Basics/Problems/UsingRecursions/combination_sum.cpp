/*
Given an array of distinct integers candidates and a target integer target, return a list of all unique combinations of candidates where the chosen numbers sum to target. You may return the combinations in any order.

The same number may be chosen from candidates an unlimited number of times. Two combinations are unique if the frequency of at least one of the chosen numbers is different.

The test cases are generated such that the number of unique combinations that sum up to target is less than 150 combinations for the given input.

LeetCode Link: https://leetcode.com/problems/combination-sum/description/
*/

class Solution {
public:
    void findCombination(int idx, int target, vector<int> &arr, vector<vector<int>> &ans, vector<int> &ds)
    {
        // Base Case
        if(idx == arr.size())
        {
            if(target==0)
            {
                ans.push_back(ds);
            }
            return;
        }

        // Picking up the element
        if(arr[idx] <= target)
        {
            ds.push_back(arr[idx]);
            findCombination(idx, target - arr[idx], arr, ans, ds);
            ds.pop_back();
        }

        // Not picking up
        findCombination(idx + 1, target, arr, ans, ds);
    }

    vector<vector<int>> combinationSum(vector<int>& candidates, int target) {
        vector<vector<int>> ans;
        vector<int> ds;
        findCombination(0, target, candidates, ans, ds);
        return ans;
    }
};
