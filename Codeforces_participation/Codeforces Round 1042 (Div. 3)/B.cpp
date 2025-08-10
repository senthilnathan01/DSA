#include <bits/stdc++.h>
using namespace std;
#define fast ios_base::sync_with_stdio(false); cin.tie(NULL);

void solve()
{
    int n; cin>>n;
    vector<long long> a(n);
    
    if(n%2 == 0)
    {
        int num_p = (n-2)/2;
        for(int i = 0; i < num_p; i++) cout<<-1<<" "<<3<<" ";
        cout<<-1<<" "<<2<<"\n";
    }
    else 
    {
        int num_p = (n-1)/2;
        for(int i = 0; i < num_p; i++) cout<<-1<<" "<<3<<" ";
        cout<<-1<<"\n";
    }
}

int main() {
    fast
    int t;
    cin >> t;
    while (t--) solve();
    return 0;
}
