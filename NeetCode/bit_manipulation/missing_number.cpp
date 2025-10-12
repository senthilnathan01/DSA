/*
Given an array nums containing n distinct numbers in the range [0, n], return the only number in the range that is missing from the array.

LINK: https://leetcode.com/problems/missing-number/description/
*/

class Solution {
public:
    int missingNumber(vector<int>& nums) {
        int n = nums.size();
        int res;
        if(n%4==0) res = n;
        else if(n%4==1) res = 1;
        else if(n%4==2) res = n+1;
        else res = 0;

        res^=0;
        for(int num: nums) res^=num;
        return res;
    }
};
