/*
Given a string s and an array of strings words, return the number of words[i] that is a subsequence of s.

A subsequence of a string is a new string generated from the original string with some characters (can be none) deleted without changing the relative order of the remaining characters.

For example, "ace" is a subsequence of "abcde".

LINK: https://leetcode.com/problems/number-of-matching-subsequences/description/
*/
class Solution {
public:
    int numMatchingSubseq(string s, vector<string>& words) {
        vector<vector<int>> letter_pos(26);
        for(int i = 0; i < s.size(); i++) letter_pos[s[i]-'a'].push_back(i);
        int cnt = 0;

        for(const auto& word: words){
            int curr_pos = -1;
            bool found=true;

            for(char c: word){
                auto it = upper_bound(letter_pos[c-'a'].begin(), letter_pos[c-'a'].end(), curr_pos);
                if(it==letter_pos[c-'a'].end()){
                    found = false;
                    break;
                }
                else curr_pos = *it;
            }
            if(found) cnt++;
        }

        return cnt;
    }
};
