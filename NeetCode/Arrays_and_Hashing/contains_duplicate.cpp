/*
Given an integer array nums, return true if any value appears at least twice in the array, and return false if every element is distinct.

Problem Link: 
https://leetcode.com/problems/contains-duplicate/description/
*/

class Solution {
public:
    bool containsDuplicate(vector<int>& nums) {
        map<int, int> mpp;
        for(auto num: nums) mpp[num]++;
        for(auto num: mpp) if(num.second>1) return true;
        return false;
    }
};
