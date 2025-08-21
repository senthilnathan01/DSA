#include <bits/stdc++.h>
using namespace std;
#define fast ios_base::sync_with_stdio(false); cin.tie(NULL);

void solve() 
{
    int n, m;
    string a, b, c;
    cin>>n>>a>>m>>b>>c;

    for(int i = 0; i < c.size(); i++)
    {
        if(c[i]=='D')
        {   
            a.push_back(b[i]);
        }
        else
        {
            a.insert(0, 1, b[i]);
        }
    }
    cout<<a<<'\n';

}

int main() {
    fast
    int t; cin>>t;
    while (t--) solve();
    return 0;
}
