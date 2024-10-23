#include<iostream>

using namespace std;

/*
You are given a string num, representing a large integer. 
Return the largest-valued odd integer (as a string) that is a non-empty substring of num, or an empty string "" if no odd integer exists.

A substring is a contiguous sequence of characters within a string.
*/
string largestOddNumber(string num) {
    int i = num.size()-1;
    while(i>=0 && ((num[i]-'0')&1)==0) i--;
    return num.substr(0, i+1);
}

int main()
{
    string s = "52";
    cout<<largestOddNumber(s)<<endl;
}