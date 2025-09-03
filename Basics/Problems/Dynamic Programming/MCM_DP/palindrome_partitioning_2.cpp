/*
Given a string s, partition s such that every substring of the partition is a palindrome.

Return the minimum cuts needed for a palindrome partitioning of s.

Link: https://leetcode.com/problems/palindrome-partitioning-ii/description/
*/

class Solution {
public:
    vector<int> dp;
    bool checkPalindrome(string &s, int l, int r){
        if(l==r) return true;
        while(l<r){
            if(s[l]!=s[r]) return false;
            l++;
            r--;
        }
        return true;
    }

    int minCutsReq(string &s, int l){
        if(l==s.size()) return -1; // Impossible to cut an empty string
        if(dp[l]!=-1) return dp[l];

        int mini = INT_MAX;
        for(int p = l; p < s.size(); p++){
            if(checkPalindrome(s, l, p)) mini = min(mini, 1 + minCutsReq(s, p+1));
        }

        return dp[l]= mini;
    }

    int minCut(string s) {
        dp.assign(s.length(), -1);

        return minCutsReq(s, 0);
    }
};
