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
    bool canJump(vector<int>& nums) {
        int n = nums.size();
        int goodPos = n-1;
        for(int i = n-2; i >= 0; i--){
            if(nums[i]+i >= goodPos) goodPos = i;
        }
        return goodPos == 0;
    }
};
