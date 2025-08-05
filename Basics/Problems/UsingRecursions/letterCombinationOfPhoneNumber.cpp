/*
Given a string containing digits from 2-9 inclusive, return all possible letter combinations that the number could represent. Return the answer in any order.

A mapping of digits to letters (just like on the telephone buttons) is given below. Note that 1 does not map to any letters.

LeetCode link: https://leetcode.com/problems/letter-combinations-of-a-phone-number/description/
*/

class Solution {
public:
    map<char, vector<char>> mpp = 
    {
        {'2', {'a', 'b', 'c'}},
        {'3', {'d', 'e', 'f'}},
        {'4', {'g', 'h', 'i'}},
        {'5', {'j', 'k','l'}},
        {'6', {'m', 'n', 'o'}},
        {'7', {'p', 'q', 'r', 's'}},
        {'8', {'t', 'u', 'v'}},
        {'9', {'w', 'x', 'y', 'z'}}
    };

    void getLetters(int idx, int n, vector<vector<char>> &input, vector<string> &ans, string &ds)
    {
        if(idx == n)
        {
            ans.push_back(ds);
            return;
        }

        for(char c: input[idx])
        {
            ds.push_back(c);
            getLetters(idx + 1, n, input, ans, ds);
            ds.pop_back();
        }
    }

    vector<string> letterCombinations(string digits) {
        if(digits.empty()) return {};
        
        vector<vector<char>> input;
        for(char c: digits) input.push_back(mpp[c]);

        int n = input.size();
        vector<string> ans;
        string ds;
        getLetters(0, n, input, ans, ds);
        return ans;
    }
};
