/*
Given two strings s1 and s2, return true if s2 contains a permutation of s1, or false otherwise.

In other words, return true if one of s1's permutations is the substring of s2.

A permutation is a rearrangement of all the characters of a string.

Leetcode Link: https://leetcode.com/problems/permutation-in-string/description/
*/

class Solution {
public:
    bool checkInclusion(string s1, string s2) {
        // Check if any of the window has a permutation of s1
        // Brute force solution would seeing all n^2 windows

        // Let's use sliding window approach and reduce the TC

        // Trivial case:
        if(s1.size()>s2.size()) return false;

        // First get the freq from s1
        map<char, int> s1freq;
        for(char c: s1) s1freq[c]++;

        // Initialise sliding window in s2
        map<char, int> s2freq;
        int l = 0, r = 0;

        // The key is that the window's size also has to be equal to s1.length()
        // Initialise the window
        while(r < s1.size())
        {
            s2freq[s2[r]]++;
            r++;
        }

        // Let's check if this window is a permutation
        if(s1freq==s2freq) return true;

        while(r < s2.size())
        {
            // Shift the window
            // Add a char to the right
            s2freq[s2[r]]++;
            r++;

            // Delete a char from left
            s2freq[s2[l]]--;
            // Erase of the char if its freq == 0
            if(s2freq[s2[l]]==0) s2freq.erase(s2[l]);
            l++;

            // Now check again
            if(s2freq==s1freq) return true;
        }
        return false;
    }
};
