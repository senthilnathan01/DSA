#include <bits/stdc++.h>
using namespace std;
#define fast ios_base::sync_with_stdio(false); cin.tie(NULL);
#define ll long long

const int MAX_NUM = 21;

vector<ll> costs;
vector<ll> pows3;

void precompute()
{
    costs.resize(MAX_NUM);
    pows3.resize(MAX_NUM);

    pows3[0]  = 1;
    for(int i = 1; i < MAX_NUM; i++) pows3[i] = pows3[i-1]*3;

    costs[0] = 3;
    for(int i = 1; i < MAX_NUM-1; i++)
    {
        costs[i] = pows3[i+1] + (ll)i*pows3[i-1];
    }
}

void solve() 
{
    ll n, k; cin>>n>>k;

    vector<ll> rem(MAX_NUM, 0);
    ll temp = n;
    int max_i = 0;
    for(int i = 0; i < MAX_NUM && temp > 0; i++)
    {
        rem[i] = temp %3;
        temp /=3;
        if(rem[i] > 0) max_i = i;
    }

    ll min_deals = 0;
    for(ll num: rem) min_deals += num;

    if(min_deals > k)
    {
        cout<<-1<<'\n';
        return;
    }

    ll curr_cost = 0;
    for(int i = 0; i <= max_i; i++) curr_cost += rem[i]*costs[i];

    ll more_left = k - min_deals;

    for(int i = max_i; i >= 1; i--)
    {
        if(more_left<=0) break;
        ll possible = more_left /2;
        ll deals = min(rem[i], possible);

        if(deals>0)
        {
            curr_cost -= deals*pows3[i-1];
            more_left -= deals*2;

            rem[i] -= deals;
            rem[i-1] += deals*3;
        }
    }
    cout<<curr_cost<<'\n';
}

int main() {
    fast
    precompute();
    int t; cin>>t;
    while (t--) solve();
    return 0;
}

