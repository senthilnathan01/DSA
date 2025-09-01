/*
Given two strings needle and haystack, return the index of the first occurrence of needle in haystack, or -1 if needle is not part of haystack.

Link: https://leetcode.com/problems/find-the-index-of-the-first-occurrence-in-a-string/description/
*/

class Solution {
public:
    int strStr(string haystack, string needle) {
        int needleSize = needle.length();
        int n = haystack.length();
        for(int i = 0; i <= n - needleSize; i++){
            if(haystack.substr(i, needleSize) == needle) return i;
        }
        return -1;
    }
};
