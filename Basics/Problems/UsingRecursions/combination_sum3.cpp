/*
Find all valid combinations of k numbers that sum up to n such that the following conditions are true:

Only numbers 1 through 9 are used.
Each number is used at most once.
Return a list of all possible valid combinations. The list must not contain the same combination twice, and the combinations may be returned in any order.

LeetCode Link: https://leetcode.com/problems/combination-sum-iii/description/
*/

class Solution {
public:
    void backtrack(int start, int k, int n, vector<int>& ds, vector<vector<int>>& ans) {
        if (ds.size() == k) {
            if (n == 0) ans.push_back(ds);
            return;
        }

        for (int i = start; i <= 9; ++i) {
            if (i > n) break; // early pruning

            ds.push_back(i);
            backtrack(i + 1, k, n - i, ds, ans);  // go to next number
            ds.pop_back();  // backtrack
        }
    }

    vector<vector<int>> combinationSum3(int k, int n) {
        vector<vector<int>> ans;
        vector<int> ds;
        backtrack(1, k, n, ds, ans);
        return ans;
    }
};
