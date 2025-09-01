#include<bits/stdc++.h>
using namespace std;

void solve()
{
    int n, m; cin>>n>>m;
    string ans = "";
    if(n==0){
        for(int i = 0; i < m-2; i++) ans += "><";
        ans += ">=>";
    }
    else if(m==0){
        for(int i = 0; i < n-2; i++) ans += "<<";
        ans += "<=<";
    }
    else{
        for(int i = 0; i < n; i++) ans += "<<";
        ans += ">";
        for(int i = 0; i < m-1; i++) ans += "<>";
    }
    cout<<ans<<"\n";
}

int main()
{
    int t; cin>>t;
    while(t--) solve();
    return 0;
}