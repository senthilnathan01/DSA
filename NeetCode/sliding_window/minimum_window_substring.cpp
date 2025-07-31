/*
Given two strings s and t of lengths m and n respectively, return the minimum window substring 
of s such that every character in t (including duplicates) is included in the window. 
If there is no such substring, return the empty string "".

The testcases will be generated such that the answer is unique.

Leetcode Link: https://leetcode.com/problems/minimum-window-substring/description/
*/

class Solution {
public:
    string minWindow(string s, string t) {
        // Trivial case 
        // Not necessary (check the constraints in LeetCode)

        unordered_map<char, int> required, window;
        for(char c: t) required[c]++;

        int need = required.size(), have = 0;

        int ansL = -1; // l of valid substr
        int ansLen = INT_MAX;
        int l = 0; 

        for(int r = 0; r < s.size(); r++)
        {
            char c = s[r];
            window[c]++;

            if(required.count(c) && window[c]==required[c]) have++;

            while(have==need)
            {
                if((r-l+1)<ansLen)
                {
                    ansLen = r - l + 1;
                    ansL = l;
                }

                window[s[l]]--;
                if(required.count(s[l]) && window[s[l]]<required[s[l]]) have--;
                l++;
            }
        }

        return ansLen == INT_MAX ? "" : s.substr(ansL, ansLen);
    }
};
