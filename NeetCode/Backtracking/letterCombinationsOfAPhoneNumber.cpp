/*
Given a string containing digits from 2-9 inclusive, return all possible letter combinations that the number could represent. Return the answer in any order.

A mapping of digits to letters (just like on the telephone buttons) is given below. Note that 1 does not map to any letters.

LINK: https://leetcode.com/problems/letter-combinations-of-a-phone-number/description/
*/

class Solution {
public:
    vector<string> ans;
    map<int, string> mpp =
    {
        {2, "abc"},
        {3, "def"},
        {4, "ghi"},
        {5, "jkl"},
        {6, "mno"},
        {7, "pqrs"},
        {8, "tuv"},
        {9, "wxyz"}
    };

    void addLetters(int idx, string &ds, string &digits){
        if(idx==digits.length()){
            ans.push_back(ds);
            return;
        }

        for(char c: mpp[digits[idx]-'0']){
            ds.push_back(c);
            addLetters(idx+1, ds, digits);
            ds.pop_back();
        }
    }

    vector<string> letterCombinations(string digits) {
        if(digits.empty()) return {};
        string ds;

        addLetters(0, ds, digits);
        return ans;
    }
};
