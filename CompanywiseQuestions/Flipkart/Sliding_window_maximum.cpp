/*
Given an array arr[] of positive integers and an integer k. You have to find the maximum value for each contiguous subarray of size k. 
Return an array of maximum values corresponding to each contiguous subarray.

LINK: https://www.geeksforgeeks.org/problems/maximum-of-all-subarrays-of-size-k3101/1
*/
class Solution {
  public:
    vector<int> maxOfSubarrays(vector<int>& arr, int k) {
        priority_queue<pair<int, int>> pq;
        for(int i =0; i < k; i++){
            pq.push({arr[i], i});
        }
        
        vector<int> ans;
        ans.push_back(pq.top().first);
        for(int i = k; i < arr.size(); i++){
            pq.push({arr[i], i});
            while(pq.top().second <= i-k) pq.pop();
            ans.push_back(pq.top().first);
        }
        return ans;
        
        
    }
};
