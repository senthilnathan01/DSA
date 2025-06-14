#include<bits/stdc++.h>
using namespace std;

bool solve()
{
    int n, s; cin>>n>>s;
    vector<int> arr(n);
    for(int i = 0; i<n; i++) cin>>arr[i];

    if(2*arr[0]>=2*s + 1) return false;

    for(int i = 1; i < n; i++)
    {
        if(2*(arr[i]-arr[i-1]) >= 2*s + 1) return false;
    }
    return true;
}

int main()
{
    bool ans = solve();
    if(ans) cout<<"Yes";
    else cout<<"No";
    return 0;
}

