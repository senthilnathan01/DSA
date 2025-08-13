#include<bits/stdc++.h>
using namespace std;

void solve()
{
    int n; cin>>n;
    vector<int> a(n);
    for(int i = 0; i < n; i++) cin>>a[i];

    int curr = 0;
    for(int i = 1; i < n; i++)
    {
        if(a[i]>a[curr]) curr = i;
    }
    cout<<curr+1<<'\n';
}

int main()
{
    int t; cin>>t;
    while(t--) solve();
    return 0;
}
