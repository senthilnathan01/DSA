#include<bits/stdc++.h>
using namespace std;

void solve()
{
    int a, b; cin>>a>>b;
    int max_posi = a;
    max_posi = min(a, b/2);
    cout<<3*max_posi<<'\n';
}

int main()
{
    int t; cin>>t;
    while(t--) solve();
    return 0;
}
