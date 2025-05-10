#include<bits/stdc++.h>
using namespace std;
#define fast ios_base::sync_with_stdio(false); cin.tie(NULL);

string solve()
{
    int r, x; cin>>r>>x;
    if(x==1)
    {
        if(1600<=r && r<=2999) return "Yes";
        else return "No";
    }
    else
    {
        if(1200<=r && r <= 2399) return "Yes";
        else return "No";
    }
}

int main()
{
    fast
    cout<<solve();
    return 0;
}

