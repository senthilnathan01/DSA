#include<bits/stdc++.h>
using namespace std;

void solve()
{
    int n; cin>>n;
    string ans = "";
    string addition = "abc";
    for(int i = 0; i < n/3; i++) ans += addition;

    int rem = n%3;
    if(rem>0)
    {
        ans += addition.substr(0, rem);
    }
    cout<<ans<<"\n";
}

int main()
{
    int t; cin>>t;
    while(t--) solve();
    return 0;
}

