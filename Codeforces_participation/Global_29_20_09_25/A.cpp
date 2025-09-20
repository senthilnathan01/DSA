#include <bits/stdc++.h>
using namespace std;

using ll = long long;

void solve(){
    ll x, y; cin>>x>>y;

    for(ll k = 2; k <= 200000; k++){
        ll nOdd = (k+1)/2;
        ll nEven = k/2;
        
        ll temp = nEven;
        
        ll minX = nOdd*nOdd;
        ll minY = nEven*(nEven+1);
        
        if(x < minX || y < minY) continue;
        
        if(k&1){if(x < y+temp+1) continue;} 
        else{if(y < x+temp) continue;}
    
        cout<<k<<endl;
        return;
    }
    cout<<-1<<endl;
}

int main() {
	int t; cin>>t;
	while(t--)solve();
	return 0;
}
