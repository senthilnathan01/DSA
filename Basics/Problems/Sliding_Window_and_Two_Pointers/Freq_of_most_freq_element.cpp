/*
The frequency of an element is the number of times it occurs in an array.

You are given an integer array nums and an integer k. In one operation, you can choose an index of nums and increment the element at that index by 1.

Return the maximum possible frequency of an element after performing at most k operations.

LINK: https://leetcode.com/problems/frequency-of-the-most-frequent-element/description/ 
*/

class Solution {
public:
    int maxFrequency(vector<int>& nums, int k) {
        sort(nums.begin(), nums.end());
        long long sum = 0;
        int l = 0, ans = 1;

        for(int r = 0; r < nums.size(); r++){
            sum += nums[r];
            while((long long)nums[r]*(r-l+1)-sum>k){
                sum-=nums[l];
                l++;
            }

            ans = max(ans, r-l+1);
        }
        return ans;
    }
};
