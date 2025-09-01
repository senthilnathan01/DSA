#include<bits/stdc++.h>
using namespace std;

using ll = long long;

void solve(){
    int n; cin>>n;
    string a; cin>>a;

    ll totOnes = 0;
    for(char c: a){
        if(c=='1') totOnes++;
    }

    if(n==1){
        cout<<totOnes<<'\n';
        return;
    }

    ll a_1 = a[0] - '0';
    ll a_n = a[n-1] - '0';

    cout<<3*totOnes - a_1 - a_n<<'\n';
}
int main()
{
    int t; cin>>t;
    while(t--) solve();
   return 0;
}
