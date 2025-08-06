/*
Given an array nums of distinct integers, return all the possible permutations. You can return the answer in any order.

LeetCode link: https://leetcode.com/problems/permutations/description/
*/

// My first approach
// TC = O(n! * n)
// SC = O(n) [O(n) for ds + O(n) for set]
class Solution {
public:
    void permutations(int idx, set<int> &seen, vector<int> &nums, vector<vector<int>> &ans, vector<int> &ds)
    {
        // Base Case
        if(idx == nums.size())
        {
            ans.push_back(ds);
            return;
        }

        // Recursive Case
        for(int i = 0; i < nums.size(); i++)
        {
            if(seen.find(i)!=seen.end()) continue;

            ds.push_back(nums[i]);
            seen.insert(i);
            permutations(idx + 1, seen, nums, ans, ds);
            seen.erase(i);
            ds.pop_back();
        }
    }

    vector<vector<int>> permute(vector<int>& nums) {
        vector<vector<int>> ans;
        vector<int> ds;
        set<int> seen;
        permutations(0, seen, nums, ans, ds);
        return ans;
    }
};

// How do we optimize this?
// Approach 2
// TC = O(n! * n)
// SC = O(n) [Slightly better as we don't use set]

class Solution {
public:
    void permutate(int idx, vector<int> &nums, vector<vector<int>> &ans)
    {
        // Base Case
        if(idx == nums.size())
        {
            ans.push_back(nums);
            return;
        }

        // Recursive Case
        for(int i = idx; i < nums.size(); i++)
        {
            swap(nums[idx], nums[i]);
            permutate(idx + 1, nums, ans);
            // swap back to original
            swap(nums[idx], nums[i]);
        }
    }

    vector<vector<int>> permute(vector<int>& nums) {
        vector<vector<int>> ans;
        vector<int> ds;
        permutate(0, nums, ans);
        return ans;
    }
};
