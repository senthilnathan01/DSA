#include<bits/stdc++.h>
using namespace std;

int solve()
{
    int a, b; cin>>a>>b;
    float c = (float)(a * 1.0/b);
    int ans = a/b;
    if(c-ans < ans + 1 - c) return ans;
    else return ans + 1;
}

int main()
{
    cout<<solve();
    return 0;
}

