/*
Given an integer array nums and an integer k, return the k most frequent elements. You may return the answer in any order.

Leetcode Link: https://leetcode.com/problems/top-k-frequent-elements/description/
*/

// Solution:
// Get the frequency of all the numbers
// Store it in a map
// map is always sorted
// create a vector called buckets and add from map (see code)
// iterate from the end of the vector to get the top k
class Solution {
public:
    vector<int> topKFrequent(vector<int>& nums, int k) {
        unordered_map<int, int> freq;
        for(auto num: nums)
        {
            freq[num]++;
        }

        vector<vector<int>> buckets(nums.size()+1);
        for(auto [num, count]: freq)
        {
            buckets[count].push_back(num);
        }

        vector<int> ans;
        for(int i = nums.size(); i >= 0 && ans.size() < k; i--)
        {
            for(auto num: buckets[i])
            {
                ans.push_back(num);
                if(ans.size()==k) break;
            }
        }
        return ans;
    }
};
