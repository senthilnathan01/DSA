/*
Given a string s and a dictionary of strings wordDict, return true if s can be segmented into a space-separated sequence of one or more dictionary words.

Note that the same word in the dictionary may be reused multiple times in the segmentation.

LINK: https://leetcode.com/problems/word-break/description/
*/

class Solution {
public:
    vector<int> memo;
    bool backtrack(int idx, int n, string &s, unordered_set<string> &wordSet){
        if(idx==n) return true;
        if(memo[idx]!=-1) return memo[idx];

        for(int len = 1; len <= 20; len++){
            string wordToSearch = s.substr(idx, len);
            if(wordSet.count(wordToSearch) && backtrack(idx+len, n, s, wordSet)) return memo[idx] = 1;
        }
        return memo[idx] = 0;
    }

    bool wordBreak(string s, vector<string>& wordDict) {
        int n = s.length();
        memo.assign(n, -1);
        unordered_set<string> wordSet(wordDict.begin(), wordDict.end());
        return backtrack(0, n, s, wordSet);
    }
};
