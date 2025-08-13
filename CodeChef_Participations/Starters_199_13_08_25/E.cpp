#include<bits/stdc++.h>
using namespace std;

void solve()
{
    long long n; cin>>n;

    long long ans;

    if(n&1) ans = (n+1)/2;
    else ans = n - (n/4);

    cout<<ans<<'\n';
}

int main()
{
    int t; cin>>t;
    while(t--) solve();
    return 0;
}
