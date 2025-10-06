/*
Given an integer array nums and an integer k, return the kth largest element in the array.

Note that it is the kth largest element in the sorted order, not the kth distinct element.

Can you solve it without sorting?

LINK: https://leetcode.com/problems/kth-largest-element-in-an-array/description/
*/
class Solution {
public:
    priority_queue<int, vector<int>, greater<int>> pq;
    int k;
    int findKthLargest(vector<int>& nums, int k) {
        this->k = k;
        for(int num: nums) add(num);
        return pq.top();
    }
    void add(int num){
        if(pq.size()<k || pq.top()<num){
            pq.push(num);
            if(pq.size()>k)pq.pop();
        }
    }
};
