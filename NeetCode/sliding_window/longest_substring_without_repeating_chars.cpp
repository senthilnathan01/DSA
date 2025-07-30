/*
Given a string s, find the length of the longest substring without duplicate characters.

A substring is a contiguous non-empty sequence of characters within a string.

Leetcode Link: https://leetcode.com/problems/longest-substring-without-repeating-characters/description/
*/

// Most Optimal
class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        int n = s.size();
        if(n<2) return n;

        int l = 0;

        unordered_map<char, int> mpp;
        int ans = 0;
        for(int r = 0; r < n; r++)
        {
            if(mpp.find(s[r]) != mpp.end()) l = max(mpp[s[r]]+1, l);
            mpp[s[r]] = r;
            ans = max(ans, r - l + 1);
        }
        return ans;
    }
};
