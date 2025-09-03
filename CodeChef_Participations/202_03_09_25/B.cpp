#include<bits/stdc++.h>
using namespace std;

bool solve()
{
    int x, y; cin>>x>>y;
    if((2*y <= (50 -x)) && ((50 -x) <= (2*y+10))) return true;
    return false;
}

int main()
{
    int t; cin>>t;
    while(t--){
        if(solve()) cout<<"Yes\n";
        else cout<<"No\n";
    }
    return 0;
}