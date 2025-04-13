#include <bits/stdc++.h>
using namespace std;

#define fast ios_base::sync_with_stdio(false); cin.tie(NULL);

void solve() {
    int n, m, l, r;
    cin >> n >> m >> l >> r;
    if(m<r)
    {
        cout<<0<<" "<<m<<endl;
    }
    else
    {
        cout<<r-m<<" "<<r<<endl;
    }
}

int main() {
    fast;
    int t;
    cin >> t;
    while (t--) {
        solve();
    }
    return 0;
}
