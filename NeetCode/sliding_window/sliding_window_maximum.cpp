/*
You are given an array of integers nums, there is a sliding window of size k which is 
moving from the very left of the array to the very right. You can only see the k numbers 
in the window. Each time the sliding window moves right by one position.

Return the max sliding window.

Description is bad. Check the problem link.

Leetcode Link: https://leetcode.com/problems/sliding-window-maximum/description/
*/

// More of a Max Heap Solution
// Yes, sliding window is used
class Solution {
public:
    vector<int> maxSlidingWindow(vector<int>& nums, int k) {
        priority_queue<pair<int, int>> pq;

        int n = nums.size();
        vector<int> ans(n-k+1);
        for(int i = 0; i < n; i++)
        {
            pq.push({nums[i], i});

            if(i >= k-1)
            {
                while(pq.top().second <= i - k) pq.pop();
                ans[i-k+1] = pq.top().first;
            }
        }
        return ans;
    }
};
