/*
Given a string s, partition s such that every substring of the partition is a palindrome. Return all possible palindrome partitioning of s.

LeetCode Link: https://leetcode.com/problems/palindrome-partitioning/description/
*/

class Solution {
public:
    bool isPalindrome(string &t)
    {
        // Using two pointers
        int l = 0, r = t.size() - 1;
        while(l < r)
        {
            if(t[l]==t[r])
            {
                l++;
                r--;
            }
            else return false;
        }
        return true;
    }

    void getParts(int idx, string &s, vector<vector<string>> &ans, vector<string> &ds)
    {
        // Nothing to divide
        // idx reached the end
        // This gives us the base
        // Base Case
        if(idx == s.size())
        {
            // If we reached the end -> it signals that the collected substrings are palindrome
            // Just add them to ans
            ans.push_back(ds);
            return;
        }

        // We have some more second half that can be divided 
        // Recursive Case
        // start getting substrings of length 1,2,... from index idx
        for(int s_size = 1; s_size <= s.size() - idx; s_size++)
        {
            string s_string = s.substr(idx, s_size);
            if(!isPalindrome(s_string)) continue;

            // If it is a palindrome
            ds.push_back(s_string);
            getParts(idx + s_size, s, ans, ds);
            ds.pop_back();
        }
    }

    vector<vector<string>> partition(string s) {
        vector<vector<string>> ans;
        vector<string> ds;

        getParts(0, s, ans, ds);
        return ans;
    }
};
