/*
Given a string s and a dictionary of strings wordDict, return true if s can be segmented into a space-separated sequence of one or more dictionary words.

Note that the same word in the dictionary may be reused multiple times in the segmentation.

LeetCode Link: https://leetcode.com/problems/word-break/description/
*/

// Used memoisation for optimisation: 
// Without storing failed positions, you may recompute a lot and time out on big cases.

class Solution {
public:
    bool backtrack(int idx, string &s, unordered_set<string> &wordSet, int n, vector<int> &memo) {
        if (idx == n) return true;
        if (memo[idx] != -1) return memo[idx];

        for (int len = 1; len <= 20; len++) { // 20 should be n - idx (but used the given constraint)
            string substring = s.substr(idx, len);
            if (wordSet.count(substring) && backtrack(idx + len, s, wordSet, n, memo)) {
                return memo[idx] = 1; // found a valid break
            }
        }

        return memo[idx] = 0; // no valid break from here
    }

    bool wordBreak(string s, vector<string>& wordDict) {
        unordered_set<string> wordSet(wordDict.begin(), wordDict.end());
        int n = s.size();
        vector<int> memo(n, -1); // -1 means "not computed"
        return backtrack(0, s, wordSet, n, memo);
    }
};
