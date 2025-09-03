#include<bits/stdc++.h>
using namespace std;

void solve()
{
    int n, q; cin>>n>>q;
    vector<long long> a(n);
    for(int i = 0; i < n; i++) cin>>a[i];

    if(n==1){
        cout<<a[0]<<endl;
        return;
    }

    long long rem  = a[0];
    for(int i = 1; i < n-1; i++){
        if(i&1) rem = max(rem, a[i]);
        else rem = min(rem, a[i]);
    }

    cout<<min(a[n-1], max(a[n-2], rem))<<endl;   
}

int main()
{
    int t; cin>>t;
    while(t--) solve();
    return 0;
}