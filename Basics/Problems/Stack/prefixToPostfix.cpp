#include <iostream>
#include <cctype>
#include<stack>

using namespace std;

/*
You are given a string that represents the prefix form of a valid mathematical expression. 
Convert it to its postfix form.
*/

// isalpha and isdigit can also be used instead 
bool isOperand(char c)
{
    if(isdigit(c)||isalpha(c))  return true;
    return false;
}

string preToPost(string& s) {
    size_t n = s.length();
    stack<string> st;
    for(int i = n-1; i>=0; i--)
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
            string ans = top1+top2+s[i];
            st.push(ans);
        }
    }
    return st.top();
}

int main()
{
    string s = "*-A/BC-/AKL";
    cout<<preToPost(s);
    return 0;
}

// OUTPUT:
// ABC/-AK/L-*