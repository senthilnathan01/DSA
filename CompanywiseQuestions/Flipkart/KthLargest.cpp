/*
Given an input stream arr[] of n integers. Find the Kth largest element (not Kth largest unique element) after insertion of each element in the stream 
and if the Kth largest element doesn't exist, the answer will be -1 for that insertion.  return a list of size n after all insertions.

LINK: https://www.geeksforgeeks.org/problems/kth-largest-element-in-a-stream2220/1
*/
class Solution {
  public:
    vector<int> kthLargest(int k, int arr[], int n) {
        // code here
        priority_queue<int, vector<int>, greater<int>> pq;
        vector<int> ans(n);
        for(int i = 0; i < n; i++){
            pq.push(arr[i]);
            if(pq.size()>k) pq.pop();
            if(pq.size()==k) ans[i] = pq.top();
            else ans[i] = -1;
        }
        return ans;
    }
};

// Heaps
