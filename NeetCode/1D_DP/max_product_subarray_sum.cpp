/*
Given an integer array nums, find a subarray that has the largest product, and return the product.

The test cases are generated so that the answer will fit in a 32-bit integer.

LINK: https://leetcode.com/problems/maximum-product-subarray/description/
*/

class Solution {
public:
    int maxProduct(vector<int>& nums) {
        int n = nums.size();

        int ans = INT_MIN;
        int curr_min = 1;
        int curr_max = 1;

        for(int i = 0; i < n; i++){
            if(nums[i]<0) swap(curr_min, curr_max);
            
            curr_min = min(nums[i], curr_min*nums[i]);
            curr_max = max(nums[i], curr_max*nums[i]);
            ans = max(ans,curr_max);
        }
        return ans;
    }
};
