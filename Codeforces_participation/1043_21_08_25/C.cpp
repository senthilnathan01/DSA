#include <bits/stdc++.h>
using namespace std;
#define fast ios_base::sync_with_stdio(false); cin.tie(NULL);
#define ll long long

vector<ll> costs;

void precompute()
{
    costs.resize(20);
    costs[0] = 3;
    ll a = 1;
    for(int i = 1; i < 20; i++)
    {
        ll b = a*9;
        costs[i] = b + i*a;
        a*=3;
    }
}

void solve() 
{
    ll n; cin>>n;
    ll tot_cost = 0;
    int k = 0;
    while(n>0)
    {
        int rem = n%3;
        if(rem!=0) tot_cost += (ll)rem*costs[k];
        n/=3;
        k++;
    }
    cout<<tot_cost<<'\n';
    
}

int main() {
    fast
    precompute();
    int t; cin>>t;
    while (t--) solve();
    return 0;
}

