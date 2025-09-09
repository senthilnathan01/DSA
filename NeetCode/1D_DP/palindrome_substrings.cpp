/*
Given a string s, return the number of palindromic substrings in it.

A string is a palindrome when it reads the same backward as forward.

A substring is a contiguous sequence of characters within the string.

LINK: https://leetcode.com/problems/palindromic-substrings/description/
*/

class Solution {
public:
    int countSubstrings(string s) {
        int ans = 0;

        for(int i = 0; i<s.length(); i++){
            ans += cntPalindrome(s, i, i);
            ans += cntPalindrome(s, i, i+1);
        }
        return ans;
    }
private:
    int cntPalindrome(string s, int l, int r){
        int cnt = 0;
        while(l>=0 && r <s.length() && s[l]==s[r]){
            cnt++;
            l--;
            r++;
        }
        return cnt;
    }
};
