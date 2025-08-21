#include <bits/stdc++.h>
using namespace std;
#define fast ios_base::sync_with_stdio(false); cin.tie(NULL);
#define ll long long

void solve() 
{
    ll n; cin>>n;
    vector<ll> ans;
    ll p = 10;
    for(int k = 1; k <= 18; k++)
    {
        ll d = p + 1;
        if(d>n) break;
        if(n%d==0) ans.push_back(n/d);
        if(p>LLONG_MAX/10) break;
        p*=10;
    }
    if(ans.empty()) cout<<0<<'\n';
    else
    {
        sort(ans.begin(), ans.end());
        cout<<ans.size()<<'\n';
        for(ll num: ans) cout<<num<<" ";
        cout<<'\n';
    }
}

int main() {
    fast
    int t; cin>>t;
    while (t--) solve();
    return 0;
}
