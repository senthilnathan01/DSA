/*
Given an integer array nums, return an array answer such that answer[i] is equal to the product of all the elements of nums except nums[i].

The product of any prefix or suffix of nums is guaranteed to fit in a 32-bit integer.

You must write an algorithm that runs in O(n) time and without using the division operation.
*/

class Solution {
public:
    vector<int> productExceptSelf(vector<int>& nums) {
        uint32_t tot = 1;
        int count = 0;
        for(auto num: nums)
        {
            if(num!=0) tot *= num;
            else count++;
        }
        vector<int> ans;
        if(count>1)
        {
            ans.assign(nums.size(), 0);
        }
        else if(count==1)
        {
            ans.assign(nums.size(), 0);
            for(int i = 0; i < nums.size(); i++)
            {
                if(nums[i]==0) ans[i] = tot;
            }
        }
        else
        {
            ans.assign(nums.size(), tot);
            for(int i = 0; i < nums.size(); i++)
            {
                ans[i] /= nums[i];
            }
        }
        return ans;
    }
};
