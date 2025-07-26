/*
You are given an array of strings tokens that represents an arithmetic expression in a Reverse Polish Notation.

Evaluate the expression. Return an integer that represents the value of the expression.

Note that:

The valid operators are '+', '-', '*', and '/'.
Each operand may be an integer or another expression.
The division between two integers always truncates toward zero.
There will not be any division by zero.
The input represents a valid arithmetic expression in a reverse polish notation.
The answer and all the intermediate calculations can be represented in a 32-bit integer.

Leetcode Link: https://leetcode.com/problems/evaluate-reverse-polish-notation/description/
*/

// Solution 1:
// Using Stacks
class Solution {
public:
    int32_t operate(int32_t num1, int32_t num2, char operation)
    {
        switch(operation)
        {
            case '+':
                return num2 + num1;
                break;
            case '-':
                return num2 - num1;
                break;
            case '*':
                return num2*num1;
                break;
            case '/':
                return num2/num1;
                break;
        }
        return 0;
    }

    int evalRPN(vector<string>& tokens) {
        set<char> operations;
        stack<int32_t> st;
        for(string word: tokens)
        {
            if (word == "+" || word == "-" || word == "*" || word == "/")
            {
                int32_t num1 = st.top();
                st.pop();
                int32_t num2 = st.top();
                st.pop();
                int32_t result = operate(num1, num2, word[0]);
                st.push(result);
            }
            else st.push(stoi(word));
        }
        return (int)st.top();
    }
};

// TODO: Solutions with other methods
