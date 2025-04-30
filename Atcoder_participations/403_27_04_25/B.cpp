#include<bits/stdc++.h>

using namespace std;

bool checkStrings(string &a, string &b, int s_length)
{
    for(int index = 0; index < s_length; index++)
    {
        if(b[index] != a[index] && a[index]!='?') return false;
    }
    return true;
}   

bool solve(string t, string s, int s_length)
{
    int len = t.size() - s_length;
    for(int i = 0; i <= len; i++)
    {
        string a = t.substr(i, s_length);
        if(checkStrings(a, s, s_length)) return true;
    }
    return false;
}

int main()
{
    string t; cin>>t;
    string s; cin>>s;
    if(solve(t,s, s.size())) cout<<"Yes";
    else cout<<"No";
    return 0;
}
