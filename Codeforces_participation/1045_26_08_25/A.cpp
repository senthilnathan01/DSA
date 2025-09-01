#include <bits/stdc++.h>
using namespace std;
#define fast ios_base::sync_with_stdio(false); cin.tie(NULL);

bool solve() 
{
    long long n, a, b; cin>>n>>a>>b;
    if((n&1) != (b&1)) return false;

    return (a <= b) || ((n&1) == (a&1));
}

int main() {
    fast
    int t; cin>>t;
    while (t--)
    {
        if(solve()) cout<<"YES\n";
        else cout<<"NO\n";
    }
    return 0;
}
