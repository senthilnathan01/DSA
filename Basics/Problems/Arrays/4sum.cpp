/*
Given an array nums of n integers, return an array of all the unique quadruplets [nums[a], nums[b], nums[c], nums[d]] such that:

0 <= a, b, c, d < n
a, b, c, and d are distinct.
nums[a] + nums[b] + nums[c] + nums[d] == target
You may return the answer in any order.

LINK: https://leetcode.com/problems/4sum/description/
*/  

using ll = long long;
class Solution {
public:
    vector<vector<int>> fourSum(vector<int>& nums, int target) {
        sort(nums.begin(), nums.end());
        vector<vector<int>> ans;
        int n = nums.size();
        for(int i = 0; i < n-3; i++){
            if(i>0 && nums[i]==nums[i-1]) continue;
            for(int j = i+1; j < n-2; j++){
                if(j>i+1 && nums[j]==nums[j-1]) continue;
                int l = j+1;
                int r = n-1;

                while(l<r){
                    ll sum = (ll)nums[i]+nums[j]+nums[l]+nums[r];
                    if(sum==target){
                        ans.push_back({nums[i], nums[j], nums[l], nums[r]});
                        while(l<r && nums[l]==nums[l+1]) l++;
                        while(l<r && nums[r]==nums[r-1]) r--;
                        l++;
                        r--;
                    }
                    else if(sum<target) l++;
                    else r--;
                }
            }
        }
        return ans;
    }
};
