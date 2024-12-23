#include<iostream>
#include<stack>
#include<algorithm>

using namespace std;

/*
Given an infix expression in the form of string s. Convert this infix expression to a postfix expression.

Infix expression: The expression of the form a op b. When an operator is in between every pair of operands.
Postfix expression: The expression of the form a b op. When an operator is followed for every pair of operands.
Note: The order of precedence is: ^ greater than * equals to / greater than + equals to -. Ignore the right associativity of ^.
*/

/*
Approach:
(Use the infixToPostfix)
1. Reverse the given infix
2. Do infixToPostfix (with some modification)
3. Reverse the result 
*/

bool isOperand(char c)
{
    if((c >= 'A' && c <= 'Z') ||
    (c >= 'a' && c <= 'z')||
    (c >= '0' && c <= '9'))
    return true;
    return false;
}

int prec(char c)
{
    if(c=='^') return 3;
    else if(c == '/' || c == '*') return 2;
    else if(c == '+' || c == '-') return 1;
    else return -1;
}

string infixToPostfixModified(string &s)
{
    string ans;
    stack<char> st;

    for(auto it: s)
    {
        if(isOperand(it))
        {
            ans += it;
        }
        else if(it == '(') st.push(it);
        else if(it == ')')
        {
            while(!st.empty() && st.top()!= '(')
            {
                ans += st.top();
                st.pop();
            }
            st.pop(); //removes '('
        }
        else
        {
            if(it == '^')
            {
                while(!st.empty() && prec(it)<= prec(st.top()))
                {
                    ans += st.top();
                    st.pop();
                }
            }
            else
            {
                while(!st.empty() && prec(it)< prec(st.top()))
                {
                    ans += st.top();
                    st.pop();
                }               
            }
            st.push(it);
        }
    }

    // Pop all the remaining elements from the stack
    while(!st.empty())
    {
        ans += st.top();
        st.pop();
    }

    return ans;
}

string infixToPrefix(string& s)
{
    // Reverse the given string
    reverse(s.begin(), s.end());
    for(size_t i = 0; i<s.length(); i++)
    {
        if(s[i]=='(') s[i]=')';
        else if(s[i]==')') s[i]='(';
    }
    string ans = infixToPostfixModified(s);

    reverse(ans.begin(), ans.end());
    for(size_t i = 0; i<ans.length(); i++)
    {
        if(ans[i]=='(') ans[i]=')';
        else if(ans[i]==')') ans[i]='(';
    }
    return ans;
}

int main()
{
    string s = "(p+q)*(c-d)";
    cout<<infixToPrefix(s);
    return 0;
}

// OUTPUT:
// *+pq-cd