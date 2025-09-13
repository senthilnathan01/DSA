#include <bits/stdc++.h>
using namespace std;
#define fast ios_base::sync_with_stdio(false); cin.tie(NULL);

using ll = long long;

void solve() 
{
    int k, x; cin>>k>>x;
    while(k--){
        if((x-1)%3==0 && ((x-1)/3)%2!=0) x = (x-1)/3;
        else x *= 2;
    }
    cout<<x<<endl;
}

int main() {
    fast
    int t; cin>>t;
    while (t--) solve();
    return 0;
}
