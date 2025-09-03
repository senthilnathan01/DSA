#include<bits/stdc++.h>
using namespace std;

void solve()
{
    int n; cin>>n;
    if(n%3==0) cout<<5*(n/3)<<endl;
    else if(n%3==1) cout<<5*(n/3-1) + 8<<endl;
    else cout<<5*(n/3) + 4<<endl;
}

int main()
{
    int t; cin>>t;
    while(t--) solve();
    return 0;
}