#include <bits/stdc++.h>
using namespace std;
#define fast ios_base::sync_with_stdio(false); cin.tie(NULL);

using ll = long long;

bool possible(int t1, int t2){
    if(t1>2*(t2+1) || t2>2*(t1+1)) return false;
    return true;
}

void solve() 
{
    int a, b, c, d; cin>>a>>b>>c>>d;

    if(c<a||d<b){
        cout<<"NO\n";
        return;
    }

    if(possible(a, b) && possible(c-a, d-b)){
        cout<<"YES\n";
    }
    else cout<<"NO\n";    
}

int main() {
    fast
    int t; cin>>t;
    while (t--) solve();
    return 0;
}
