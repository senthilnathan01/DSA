/*
Given a string s containing just the characters '(', ')', '{', '}', '[' and ']', determine if the input string is valid.

An input string is valid if:

Open brackets must be closed by the same type of brackets.
Open brackets must be closed in the correct order.
Every close bracket has a corresponding open bracket of the same type.

Leetcode Link: https://leetcode.com/problems/valid-parentheses/description/
*/
class Solution {
public:
    bool isValid(string s) {
        int n = s.size();
        // Odd number? Nah
        if(n%2 != 0) return false;

        stack<char> st;

        int i = 0;

        while(i<n)
        {
            if(s[i]==')'||s[i]=='}'||s[i]==']')
            {
                if(st.empty()) return false;
                else
                {
                    char c = st.top();
                    if((s[i]==')'&& c=='(') || (s[i]=='}' && c=='{') || (s[i]==']' && c=='['))
                    {
                        st.pop();
                        i++;
                    }
                    else return false;
                }
            }
            else
            {
                st.push(s[i]);
                i++;
            }
            
        }
        if(!st.empty()) return false;
        return true;
    }
};
