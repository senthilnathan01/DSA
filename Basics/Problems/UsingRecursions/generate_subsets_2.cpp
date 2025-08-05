/*
Given an integer array nums that may contain duplicates, return all possible subsets (the power set).

The solution set must not contain duplicate subsets. Return the solution in any order.

Leetcode Link: https://leetcode.com/problems/subsets-ii/description/
*/

class Solution {
public:
    void getSubsets(int idx, vector<int> &arr, vector<vector<int>> &ans, vector<int> &ds)
    {
        ans.push_back(ds);
        
        // Base Case
        if(idx == arr.size()) return;

        // Recursive Case
        for(int i = idx; i < arr.size(); i++)
        {
            if(i > idx && arr[i]==arr[i-1]) continue;

            ds.push_back(arr[i]);
            getSubsets(i+1, arr, ans, ds);
            ds.pop_back();
        }
    }

    vector<vector<int>> subsetsWithDup(vector<int>& nums) {
        vector<int> arr = nums;
        sort(arr.begin(), arr.end());
        vector<vector<int>> ans;
        vector<int> ds;
        getSubsets(0, arr, ans, ds);
        return ans;
    }
};
