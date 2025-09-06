/*
Given a string s, partition s such that every substring of the partition is a palindrome. Return all possible palindrome partitioning of s.

LINK: https://leetcode.com/problems/palindrome-partitioning/description/
*/

class Solution {
public:
    vector<vector<string>> ans;
    bool isPalindrome(int i, int j, string &s){
        int l = i, r = j;
        while(l<r){
            if(s[l]!=s[r]) return false;
            l++;
            r--;
        }
        return true;
    }
    void dfs(int p, string &s, vector<string> &newVec){
        if(p==s.size()){
            ans.push_back(newVec);
            return;
        }
        for(int i = p; i < s.size(); i++){
            if(isPalindrome(p, i, s)){
                newVec.push_back(s.substr(p, i-p+1));
                dfs(i+1, s, newVec);
                newVec.pop_back();
            }
        }

    }
    vector<vector<string>> partition(string s) {
        vector<string> newVec;
        dfs(0, s, newVec);
        return ans;
    }
};
