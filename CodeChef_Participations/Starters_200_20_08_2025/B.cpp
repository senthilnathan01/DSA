#include<bits/stdc++.h>
using namespace std;

void solve()
{
    int n; cin>>n;
    int ans = 1, temp;
    int lastState = -1;
    cin>>temp;
    if(n==1)
    {
        cout<<ans<<'\n';
        return;
    }

    lastState = temp&1;
    for(int i = 1; i < n; i++)
    {
        cin>>temp;
        int s = temp&1;
        if(s!=lastState)
        {
            ans++;
            lastState = s;
        }
    }
    cout<<ans<<'\n';
}

int main()
{
    int t; cin>>t;
    while(t--) solve();
    return 0;
}
