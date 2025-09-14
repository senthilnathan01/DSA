#include<bits/stdc++.h>
using namespace std;
using ll = long long;
using ull = unsigned long long;

int main()
{
    int n, q; cin>>n>>q;
    vector<ll> a(n+1), p1(n+1, 0), p2(n+1, 0), p3(n+1, 0);

    for(ll i =1; i <= n; i++){
        cin>>a[i];
        p1[i] = p1[i-1] + a[i];
        p2[i] = p2[i - 1] + i*a[i];
        p3[i] = p3[i - 1] + i*i*a[i];
    }

    while(q--){
        ll l, r; cin>>l>>r;
        ll t1 = p1[r] - p1[l-1];
        ll t2 = p2[r] - p2[l-1];
        ll t3 = p3[r] - p3[l-1];
        ll ans = -t3 + (l+r)*t2 + (r+1-l-l*r)*t1;
        cout<<ans<<endl;
    }
    return 0;
}