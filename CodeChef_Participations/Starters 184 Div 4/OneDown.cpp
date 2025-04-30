#include<bits/stdc++.h>

using namespace std;

bool solve()
{
    int n; cin>>n;
    string s, p; cin>>s>>p;
    int yes_convert = 0;
    for(int i = 0; i < n; i++)
    {
        if(s[i]-'0'==0 && p[i]-'0'==1) return false;
        if(s[i]-'0'==1 && p[i]-'0'==0) yes_convert++;
    }
    if(yes_convert%2==0) return true;
    else return false;
}

int main()
{
    int t; cin>>t;
    while(t--)
    {
        if(solve()) cout<<"Yes"<<endl;
        else cout<<"No"<<endl;
    }
    return 0;
}