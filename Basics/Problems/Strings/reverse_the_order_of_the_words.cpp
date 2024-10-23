#include<iostream>
#include<stack>
#include<string>
#include<sstream>
using namespace std;

/*
Given an input string s, reverse the order of the words.

A word is defined as a sequence of non-space characters. The words in s will be separated by at least one space.

Return a string of the words in reverse order concatenated by a single space.

Note that s may contain leading or trailing spaces or multiple spaces between two words. 
The returned string should only have a single space separating the words. Do not include any extra spaces.
*/

string reverseWords(string s) {
    stack<string> st;
    string temp;
    string word;
    stringstream ss(s);

    while(getline(ss, word, ' '))
    {
        if(!word.empty()) st.push(word);
    }
    while(!st.empty())
    {
        temp += st.top();
        st.pop();
        if(!st.empty()) temp += " ";
    }
    return temp;
}


int main()
{
    string s = "Hello World";
    cout<<reverseWords(s)<<endl;
}