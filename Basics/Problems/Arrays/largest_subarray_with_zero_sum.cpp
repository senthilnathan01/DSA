/*
Given an array arr[] containing both positive and negative integers, the task is to find the length of the longest subarray with a sum equals to 0.

Note: A subarray is a contiguous part of an array, formed by selecting one or more consecutive elements while maintaining their original order.

LINK: https://www.geeksforgeeks.org/problems/largest-subarray-with-0-sum/1
*/
class Solution {
  public:
    int maxLength(vector<int>& arr) {
        // code here
        unordered_map<int,int> firstIndex;
        int prefSum = 0;
        int ans = 0;
        
        for(int i = 0; i < arr.size(); i++){
            prefSum += arr[i];
            if(prefSum==0) ans = i+1;
            
            if(firstIndex.find(prefSum)!=firstIndex.end()) ans = max(ans, i-firstIndex[prefSum]);
            else firstIndex[prefSum] = i;
        }
        return ans;
    }
};
