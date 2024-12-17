#include<iostream>
#define CODE ios::sync_with_stdio(false); cin.tie(0);
#define ll long long int
#include<algorithm>
using namespace std;

void solve()
{
    string s;
    cin>>s;
    int n = s.size();
    for(int i = 0; i<n; i++)
    {
        if(s[i]=='p') s[i]= 'q';
        else if(s[i]=='q') s[i]='p';
    }
    reverse(s.begin(), s.end());
    cout<<s<<endl;
}

int main()
{
    CODE
    int testCases;
    cin>>testCases;
    while(testCases--)
    {
        solve();
    }
}