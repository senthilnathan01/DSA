#include <bits/stdc++.h>
using namespace std;
#define fast ios_base::sync_with_stdio(false); cin.tie(NULL);

using ll = long long;

void solve() 
{
    int n, m, x, y; cin>>n>>m>>x>>y;
    int temp;
    for(int i = 0; i < n; i++) cin>>temp;
    for(int i = 0; i < m; i++) cin>>temp;
    cout<<n+m<<endl;
}

int main() {
    fast
    int t; cin>>t;
    while (t--) solve();
    return 0;
}
