#include<bits/stdc++.h>
using namespace std;

#define fast ios_base::sync_with_stdio(false); cin.tie(NULL);

int main()
{
    fast

    int n; cin>>n;
    long long rmin = 1e9, rmax = 1, cmin = 1e9, cmax = 1;

    for(int i = 0; i< n; i++)
    {
        long long r, c; cin>>r>>c;
        rmin = min(rmin, r);
        rmax = max(rmax, r);
        cmin = min(cmin, c);
        cmax = max(cmax, c);
    }

    cout<<(max(rmax-rmin, cmax-cmin) + 1)/2;

    return 0;
}