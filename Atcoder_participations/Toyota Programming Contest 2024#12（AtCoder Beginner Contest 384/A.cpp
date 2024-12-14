#include<iostream>

using namespace std;

string solve()
{
    int n;
    char c1, c2;
    cin>>n>>c1>>c2;
    string s;
    cin>>s;
    for(int i = 0; i<n; i++)
    {
        if(s[i]!=c1) s[i]=c2;
    }
    return s;
}

int main()
{
    cout<<solve();
}