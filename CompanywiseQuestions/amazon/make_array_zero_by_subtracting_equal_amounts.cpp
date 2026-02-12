/*
You are given a non-negative integer array nums. In one operation, you must:

Choose a positive integer x such that x is less than or equal to the smallest non-zero element in nums.
Subtract x from every positive element in nums.
Return the minimum number of operations to make every element in nums equal to 0.

LINK: https://leetcode.com/problems/make-array-zero-by-subtracting-equal-amounts/?envType=problem-list-v2&envId=7p5x763
*/

class Solution {
public:
    int minimumOperations(vector<int>& nums) {
        int jumps = 0;
        int mini = 0;
        sort(nums.begin(), nums.end());
        for(int i = 0; i < nums.size(); i++){
            if(mini<nums[i]){
                mini = nums[i];
                jumps++;
            }
        }
        return jumps;
    }
};
