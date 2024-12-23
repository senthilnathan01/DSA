#include<iostream>
#include<stack>

using namespace std;

/*
Problem:
Given a string s containing just the characters '(', ')', '{', '}', '[' and ']', determine if the input string is valid.

An input string is valid if:

Open brackets must be closed by the same type of brackets.
Open brackets must be closed in the correct order.
Every close bracket has a corresponding open bracket of the same type.
*/

bool isMatch(char c1, char c2)
{
    if((c1 == '(' && c2 == ')') || (c1 == '{' && c2 == '}') || (c1 == '[' && c2 == ']')) return true;
    else return false;
}

bool isValid(string s) {
    stack<char> st;
    size_t n = s.length();
    if(n%2 == 1) return false;

    for(size_t  i = 0; i<n; i++)
    {
        if(s[i]=='(' || s[i]=='{' || s[i]=='[')
        {
            st.push(s[i]);
        }
        else
        {
            if(st.empty()) return false;
            char ch = st.top();
            st.pop();
            if(isMatch(ch, s[i])) continue;
            else return false;                    
        }
    }
    return st.empty();
}

int main()
{
    cout<<isValid("([]}{)")<<endl;
    cout<<isValid("()]");
}

// OUTPUT:
// 0
// 0

