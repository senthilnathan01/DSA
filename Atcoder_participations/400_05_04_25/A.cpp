#include<bits/stdc++.h>

using namespace std;

int solve()
{
    int a; cin>>a;
    float b = 400.0/a;
    if(b==(int)b) return b;
    return -1;
}

int main()
{
    cout<<solve();
    return 0;
}
