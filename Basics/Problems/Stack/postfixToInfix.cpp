#include<iostream>
#include<stack>
#include<algorithm>

using namespace std;

/*
You are given a string that represents the postfix form of a valid mathematical expression. Convert it to its infix form.
*/

// isalpha and isdigit can also be used instead 
bool isOperand(char c)
{
    if((c >= 'A' && c <= 'Z') ||
    (c >= 'a' && c <= 'z')||
    (c >= '0' && c <= '9'))
    return true;
    return false;
}

string preToInfix(string& s) {
    size_t n = s.length();
    stack<string> st;
    for(size_t i = 0; i<n; i++)
    {
        if(isOperand(s[i]))
        {
            string ans = "";
            ans.push_back(s[i]);
            st.push(ans);
        }
        else
        {
            string top1 = st.top();
            st.pop();
            string top2 = st.top();
            st.pop();
            string ans = "("+top2+s[i]+top1+")";
            st.push(ans);
        }
    }
    return st.top();
}

int main()
{
    string s = "ab*c+";
    cout<<preToInfix(s);
    return 0;
}

// OUTPUT:
// ((a*b)+c)