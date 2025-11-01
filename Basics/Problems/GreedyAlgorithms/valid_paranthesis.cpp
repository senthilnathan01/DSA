/*
Given a string s containing only three types of characters: '(', ')' and '*', return true if s is valid.

The following rules define a valid string:

Any left parenthesis '(' must have a corresponding right parenthesis ')'.
Any right parenthesis ')' must have a corresponding left parenthesis '('.
Left parenthesis '(' must go before the corresponding right parenthesis ')'.
'*' could be treated as a single right parenthesis ')' or a single left parenthesis '(' or an empty string "".

LINK: https://leetcode.com/problems/valid-parenthesis-string/description/
*/
class Solution {
public:
    bool checkValidString(string s) {
        stack<int> open;
        stack<int> asterisk;
        for(int i =0; i < s.length(); i++){
            if(s[i]=='(') open.push(i);
            else if(s[i]=='*') asterisk.push(i);
            else{
                if(!open.empty()) open.pop();
                else if(!asterisk.empty()) asterisk.pop();
                else return false;
            }
        }

        while(!open.empty() && !asterisk.empty()){
            if(open.top()>asterisk.top()) return false;
            open.pop();
            asterisk.pop();
        }
        return open.empty();
        
    }
};
