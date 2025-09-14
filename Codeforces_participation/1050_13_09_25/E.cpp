#include <bits/stdc++.h>
using namespace std;
#define fast ios_base::sync_with_stdio(false); cin.tie(NULL);

using ll = long long;

void solve() 
{
    int n, k; cin>>n>>k;
    vector<int> a(n);
    vector<int> cnts(n+1, 0);
    for(int i = 0; i < n; i++){
        cin>>a[i];
        cnts[a[i]]++;
    }

    for(int i = 1; i <= n;i++){
        if(cnts[i]%k!=0){
            cout<<0<<endl;
            return;
        }
    }

    vector<int> target(n+1, 0);
    for(int i = 1; i <= n; i++) target[i] = cnts[i]/k;

    ll ans = 0;
    int r = 0;
    vector<int> subcnts(n+1, 0);

    for(int l = 0; l < n; l++){
        while(r < n){
            int curr = a[r];
            if(subcnts[curr]+1<=target[curr]){
                subcnts[curr]++;
                r++;
            }
            else break;
        }

        ans += (r-l);
        subcnts[a[l]]--;
    }
    cout<<ans<<endl;
}

int main() {
    fast
    int t; cin>>t;
    while (t--) solve();
    return 0;
}
