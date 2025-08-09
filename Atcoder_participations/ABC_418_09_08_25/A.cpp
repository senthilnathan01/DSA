#include<bits/stdc++.h>
using namespace std;
#define ll long long

int main()
{
    int n; cin>>n;
    string s; cin>>s;
    if(n<3)
    {
        cout<<"No";
    }
    else
    {
        if(s.substr(n-3, 3) == "tea")
        {
            cout<<"Yes";
        }
        else
        {
            cout<<"No";
        }
    }
    return 0;
}
