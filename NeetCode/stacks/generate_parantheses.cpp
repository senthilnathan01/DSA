/*
Given n pairs of parentheses, write a function to generate all combinations of well-formed parentheses.

 

Example 1:

Input: n = 3
Output: ["((()))","(()())","(())()","()(())","()()()"]
Example 2:

Input: n = 1
Output: ["()"]

Leetcode Link: https://leetcode.com/problems/generate-parentheses/description/
*/
class Solution {
public:
    void backtrack(int openP, int closeP, int n, vector<string> &res, string &stack)
    {   
        // Plan:
        // Only add openP if openP < n
        // likewise for closeP
        // valid IFF openP = closeP = n

        if(openP == closeP && openP == n)
        {
            res.push_back(stack);
            return;
        }

        if(openP < n)
        {
            stack += '(';
            backtrack(openP + 1, closeP, n, res, stack);
            stack.pop_back();
        }

        if(closeP < openP)
        {
            stack += ')';
            backtrack(openP, closeP + 1, n, res, stack);
            stack.pop_back();
        }
    }

    vector<string> generateParenthesis(int n) {
        vector<string> ans;
        string stack;
        backtrack(0, 0, n, ans, stack);
        return ans;  
    }
};
