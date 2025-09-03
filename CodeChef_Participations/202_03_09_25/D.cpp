#include<bits/stdc++.h>
using namespace std;

void solve()
{
    int n; cin>>n;
    vector<int> a(n);
    for(int i = 0; i < n; i++) cin>>a[i];
    for(int i = 0; i <= n-2; i++){
        if(a[i+1]<a[i]){
            cout<<i+1<<" "<<i+2<<endl;
            return;
        }
    }
    cout<<-1<<endl;
}

int main()
{
    int t; cin>>t;
    while(t--) solve();
    return 0;
}