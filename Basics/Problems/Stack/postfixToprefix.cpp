#include <iostream>
#include <cctype>
#include<stack>

using namespace std;

/*
You are given a string that represents the postfix form of a valid mathematical expression. 
Convert it to its prefix form.
*/

// isalpha and isdigit can also be used instead 
bool isOperand(char c)
{
    if(isdigit(c)||isalpha(c))  return true;
    return false;
}

string postToPre(string& s) {
    size_t n = s.length();
    stack<string> st;
    for(int i = 0; i<n; i++)
    {
        if(isOperand(s[i]))
        {
            string ans = "";
            ans.push_back(s[i]);
            st.push(ans);
        }
        else
        {
            string top1 = st.top(); st.pop();
            string top2 = st.top(); st.pop();
            string ans = s[i]+top2+top1;
            st.push(ans);
        }
    }
    return st.top();
}

int main()
{
    string s = "ABC/-AK/L-*";
    cout<<postToPre(s);
    return 0;
}

// OUTPUT:
// *-A/BC-/AKL