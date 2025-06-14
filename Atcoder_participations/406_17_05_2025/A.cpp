#include<bits/stdc++.h>
using namespace std;
#define fast ios_base::sync_with_stdio(false); cin.tie(NULL);

string solve()
{
    int a, b, c, d;
    cin>>a>>b>>c>>d;
    if(c*60 + d < a*60 + b ) return "Yes";
    else return "No";
}

int main()
{
    fast
    cout<<solve();
    return 0;
}

