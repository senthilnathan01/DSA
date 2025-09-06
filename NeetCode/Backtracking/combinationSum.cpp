/*
Given an array of distinct integers candidates and a target integer target, return a list of all unique combinations of candidates where the chosen numbers sum to target. You may return the combinations in any order.

The same number may be chosen from candidates an unlimited number of times. Two combinations are unique if the frequency of at least one of the chosen numbers is different.

The test cases are generated such that the number of unique combinations that sum up to target is less than 150 combinations for the given input.

LINK: https://leetcode.com/problems/combination-sum/description/
*/

class Solution {
public:
    vector<vector<int>> ans;
    void func(int i, int n, vector<int> &newVec, vector<int> &temp, int target){
        if(target==0){
            ans.push_back(newVec);
            return;
        }
        if(i==n || target<0) return;

        newVec.push_back(temp[i]);
        func(i, n, newVec, temp, target-temp[i]);
        newVec.pop_back();
        func(i+1, n, newVec, temp, target);
    }
    vector<vector<int>> combinationSum(vector<int>& candidates, int target) {
        vector<int> temp = candidates;
        sort(temp.begin(), temp.end());
        vector<int> newVec;
        func(0, temp.size(), newVec, temp, target);
        return ans;
    }
};
