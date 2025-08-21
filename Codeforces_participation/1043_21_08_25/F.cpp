#include <bits/stdc++.h>
using namespace std;
#define fast ios_base::sync_with_stdio(false); cin.tie(NULL);
#define ll long long

void solve() 
{
    int n, m, q; cin>>n>>m>>q;
    vector<ll> a(n), b(m);
    for(int i = 0; i < n; i++) cin>>a[i];
    for(int i = 0; i < m; i++) cin>>b[i];

    sort(a.rbegin(), a.rend());
    sort(b.rbegin(), b.rend());

    vector<ll>p_a(n+1, 0), p_b(m+1, 0);
    for(int i = 0; i < n; i++) p_a[i+1] = p_a[i] + a[i];
    for(int i = 0; i < m; i++) p_b[i+1] = p_b[i] + b[i];

    while(q--)
    {
        ll x, y, z; cin>>x>>y>>z;
        ll v_min = max(0LL, z-y);
        ll v_max = min(x, z);

        ll v_ = 0, l = 0, h = z;

        while(l<=h)
        {
            ll mid = l + (h-l)/2;
            ll vadim;
            if(mid == 0) vadim = LLONG_MAX;
            else if(mid > n) vadim = LLONG_MIN;
            else vadim = a[mid -1];

            ll kostya;
            ll kostya_i = z - mid + 1;
            if(kostya_i <= 0) kostya = LLONG_MAX;
            else if(kostya_i > m) kostya = LLONG_MIN;
            else kostya = b[kostya_i -1];

            if(vadim >= kostya)
            {
                v_ = mid;
                l = mid + 1;
            }
            else h  = mid -1;
        }
        ll v__ = max(v_min, min(v_max, v_));
        ll ans = p_a[v__] + p_b[z - v__];
        cout<<ans<<'\n';
    }
}

int main() {
    fast
    int t; cin>>t;
    while (t--) solve();
    return 0;
}
