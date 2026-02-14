/*
Given an array of integers nums, find the maximum length of a subarray where the product of all its elements is positive.

A subarray of an array is a consecutive sequence of zero or more values taken out of that array.

Return the maximum length of a subarray with positive product.

LINK: https://leetcode.com/problems/find-good-days-to-rob-the-bank/description/
*/

class Solution {
public:
    vector<int> goodDaysToRobBank(vector<int>& security, int time) {
        // base case
        int n = security.size();
        if(time==0){
            vector<int> ans(n);
            iota(ans.begin(), ans.end(), 0);
            return ans;
        };

        // Brute Force takes O(n*time) (we need to check if every element's left and right for utmost 'time' steps)
        // What if we precompute the checking left and right steps?
        // Just go from left to right and check for no of steps it is non increasing
        // Do similarly right to left
        vector<int> left(n, 0);
        vector<int> right(n, 0);
        for(int i = 1; i < n; i++){
            if(security[i]<=security[i-1]) left[i] = left[i-1]+1;
        }
        for(int i = n-2; i >=0; i--){
            if(security[i]<=security[i+1]) right[i] = right[i+1] + 1;
        }
        vector<int> ans;
        for(int i = 0; i < n; i++){
            if(left[i]>= time && right[i]>=time) ans.push_back(i);
        }
        return ans;
    }
};
