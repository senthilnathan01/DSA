/*
Given a collection of candidate numbers (candidates) and a target number (target), find all unique combinations in candidates where the candidate numbers sum to target.

Each number in candidates may only be used once in the combination.

Note: The solution set must not contain duplicate combinations.

LeetCode Link: https://leetcode.com/problems/combination-sum-ii/description/
*/

// This solution derives from the logic seen in the other problem(combination_sum.cpp)
// Here we change the logic a little
// And use set to take care of the duplicates
// But its time complexity increases by n times
// This might lead to TLEs

// Here is this approach
// Followed up with a better approach (better TC) 
class Solution {
public:
    void findCombination(int idx, int target, vector<int> &arr, vector<int> &ds, vector<vector<int>> &ans)
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

        // Recursive Case
        // Picking up
        if(arr[idx] <= target)
        {
            ds.push_back(arr[idx]);
            findCombination(idx + 1, target - arr[idx], arr, ds, ans);
            ds.pop_back();
        }

        // Not picking up
        findCombination(idx + 1, target, arr, ds, ans);        
    }

    vector<vector<int>> combinationSum2(vector<int>& candidates, int target) {
        vector<vector<int>> ans;
        vector<int> ds;
        vector<int> arr = candidates;
        sort(arr.begin(), arr.end());
        findCombination(0, target, arr, ds, ans);
        set<vector<int>> noDupes(ans.begin(), ans.end());
        vector<vector<int>> res(noDupes.begin(), noDupes.end());
        return res;
    }
};

// Approach 2: With better TC
// Using slight logical improvements in the base code
class Solution {
public:
    void findCombination(int idx, int target, vector<int> &arr, vector<int> &ds, vector<vector<int>> &ans)
    {
        // Base Case
        if(target==0)
        {
            ans.push_back(ds);
            return;
        }

        // Recursive Case
        for(int i = idx; i < arr.size(); i++)
        {
            if(i > idx && arr[i]==arr[i-1]) continue;
            if(arr[i] > target) break;
            ds.push_back(arr[i]);
            findCombination(i + 1, target - arr[i], arr, ds, ans);
            ds.pop_back();
        }        
    }

    vector<vector<int>> combinationSum2(vector<int>& candidates, int target) {
        vector<vector<int>> ans;
        vector<int> ds;
        vector<int> arr = candidates;
        sort(arr.begin(), arr.end());
        findCombination(0, target, arr, ds, ans);
        return ans;
    }
};
