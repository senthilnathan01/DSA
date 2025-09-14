#include <bits/stdc++.h>
using namespace std;
#define fast ios_base::sync_with_stdio(false); cin.tie(NULL);

using ll = long long;

void solve() 
{
    int n; cin>>n;
    vector<ll> oddGuys, evenGuys;
    ll temp;
    for(int i = 0; i < n; i++){
        cin>>temp;
        if(temp&1) oddGuys.push_back(temp);
        else evenGuys.push_back(temp);
    }

    ll ans = 0;
    
    if(oddGuys.empty()){
        cout<<0<<endl;
        return;
    }

    ans += accumulate(evenGuys.begin(), evenGuys.end(), 0LL);

    sort(oddGuys.begin(), oddGuys.end(), greater<ll>());
    int toCut = (oddGuys.size()+1)/2;
    for(int i = 0; i < toCut; i++) ans += oddGuys[i];
    cout<<ans<<endl;
}

int main() {
    fast
    int t; cin>>t;
    while (t--) solve();
    return 0;
}
