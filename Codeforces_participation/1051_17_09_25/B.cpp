#include <bits/stdc++.h>
using namespace std;
using ll = long long;
void solve(){
    int n, k; cin>>n>>k;
    vector<ll> a(n);
    ll tot = 0;
    for(int i = 0; i < n; i++){cin>>a[i]; tot+=a[i];}
    vector<int> b(k);
    for(int i = 0; i < k; i++) cin>>b[i];
    sort(a.rbegin(), a.rend());
    sort(b.begin(), b.end());
    ll saved = 0;
    int ptr = 0;
    for(int i = 0; i < k; i++){
        int size = b[i];
        if(ptr + size > n) break;
        saved += a[ptr + size -1];
        ptr += size;
    }
    cout<<tot - saved<<endl;
}

int main() {
	int t; cin>>t;
	while(t--)solve();
	return 0;
}
