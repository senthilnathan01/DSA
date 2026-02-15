/*
Given an array of strings words and an integer k, return the k most frequent strings.

Return the answer sorted by the frequency from highest to lowest. Sort the words with the same frequency by their lexicographical order.

LINK: https://leetcode.com/problems/top-k-frequent-words/description/
*/
class Solution {
public:
    vector<string> topKFrequent(vector<string>& words, int k) {
        unordered_map<string, int> mp;
        for(string word: words) mp[word]++;
        vector<pair<int, string>> vec;
        for(auto p: mp) vec.push_back({p.second, p.first});
        sort(vec.begin(), vec.end(), [](const pair<int, string> &a, const pair<int, string> &b){
            if(a.first==b.first) return a.second < b.second;
            return a.first > b.first;
        });
        vector<string> ans;
        for(int i =0; i < k; i++) ans.push_back(vec[i].second);
        return ans;
    }
};
