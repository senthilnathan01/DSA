/*
Given an array of integers nums, find the maximum length of a subarray where the product of all its elements is positive.

A subarray of an array is a consecutive sequence of zero or more values taken out of that array.

Return the maximum length of a subarray with positive product.

LINK: https://leetcode.com/problems/maximum-length-of-subarray-with-positive-product/description/
*/
class Solution {
public:
    int getMaxLen(vector<int>& nums) {
        // track start and end
        // reset when passed through zero
        // track sign by counting the number of negatives

        int ans = 0;
        int start = 0;
        int n = nums.size();

        while(start < n){
            // skip zeroes
            while(start < n && nums[start]==0) start++;
            
            // reached the end?
            if(start==n) break;

            // ready to start counting?
            int end = start;
            int num_negs = 0;
            int firstNeg = -1;
            int lastNeg = -1;
            while(end < n && nums[end]!=0){
                if(nums[end]<0){
                    num_negs++;
                    if(firstNeg==-1) firstNeg=end;
                    lastNeg = end;
                }
                end++;
            }

            if(num_negs%2==0) ans = max(ans, end-start);
            else{
                // the final number of the subarray is just before end. (notice that we did end++ at the end)
                // so we put (end - 1)
                ans = max(ans, end-1 -firstNeg);
                ans = max(lastNeg-start, ans);
            }
            start = end;
        }
        return ans;
    }
};

// Cleaner DP version
class Solution {
public:
    int getMaxLen(vector<int>& nums) {
        int posLen = 0, negLen = 0, ans = 0;
        int temp;
        for(int num: nums){
            if(num==0){
                posLen = negLen = 0;
            }
            else if(num>0){
                posLen++;
                if(negLen) negLen++;
            }
            else{
                temp = posLen;
                posLen = (negLen > 0 ? negLen + 1: 0);
                negLen = temp + 1;
            }
            ans = max(ans, posLen);
        }
        return ans;
    }
};

