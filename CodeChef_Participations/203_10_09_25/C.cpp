#include<bits/stdc++.h>
using namespace std;

using ll = long long;

void solve()
{
    ll n; cin>>n;
    ll m = n*(n-1)/2;
    vector<ll> wts(m);
    for(int i =0; i < m; i++) cin>>wts[i];

    sort(wts.begin(), wts.end());
    ll ans = 0;
    ll cnt = 0;
    ll nodes = 1;
    ll available = 0;

    for(int i = 0; i < m; i++){
        if(cnt==n-1) break;
        if(available>0) available--;
        else{
            ans += wts[i];
            cnt++;
            nodes++;
            available += (nodes-2);
        }
    }
    cout<<ans<<endl;
}

int main()
{
    int t; cin>>t;
    while(t--)solve();
    return 0;
}
