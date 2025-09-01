#include<bits/stdc++.h>
using namespace std;

int main()
{
    int  n; cin>>n;
    vector<string> p(n+1);
    for(int i = 1; i<=n; i++) cin>>p[i];
    int x;cin>>x;
    string y; cin>>y;
    if(p[x]==y) cout<<"Yes";
    else cout<<"No";
    return 0;
}
