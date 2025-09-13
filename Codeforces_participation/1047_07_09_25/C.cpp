#include <bits/stdc++.h>
using namespace std;
#define fast ios_base::sync_with_stdio(false); cin.tie(NULL);

using ll = long long;

void solve() 
{
    ll a, b; cin>>a>>b;
    bool aOdd = (a&1==1);
    bool bOdd = (b&1==1);

    if(aOdd && bOdd){cout<<max(a+b, a*b+1)<<endl;}
    else if(!aOdd && bOdd){cout<<-1<<endl;}
    else if(aOdd && !bOdd){
        if(b%4!=0){cout<<-1<<endl;}
        else{cout<<max(2*a+b/2, a*(b/2)+2)<<endl;}
    }
    else{cout<<max(a+b, a*(b/2)+2)<<endl;}
}

int main() {
    fast
    int t; cin>>t;
    while (t--) solve();
    return 0;
}
