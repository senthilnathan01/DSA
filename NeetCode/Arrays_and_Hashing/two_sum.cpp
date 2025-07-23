/*
Given an array of integers nums and an integer target, return indices of the two numbers such that they add up to target.

You may assume that each input would have exactly one solution, and you may not use the same element twice.

You can return the answer in any order.

Leetcode Link: https://leetcode.com/problems/two-sum/description/
*/

// Solution 1:
class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        map<int, int> index;
        size_t n = nums.size();
        int i = 0;
        for(; i< n; i++)
        {
            index[nums[i]] = i;
        }
        for(i = 0; i < n; i++)
        {
            if(index.count(target-nums[i]) && i!=index[target-nums[i]]) return {index[target-nums[i]], i};
        }
        return {-1, -1};
    }
};

// Solution 2:
// We need not even add all the numbers to map initially. We check as we add and return the answer (if found) and stop the process.
// Also let's use unordered_map
class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        unordered_map<int, int> mpp;
        size_t n = nums.size();
        int i =0;
        for(; i < n; i++)
        {
            if(mpp.find(target-nums[i])!=mpp.end()) return {i, mpp[target-nums[i]]};
            else mpp[nums[i]] = i;
        }
        return {};
    }
};
