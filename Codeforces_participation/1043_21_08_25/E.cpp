#include <bits/stdc++.h>
using namespace std;
#define fast ios_base::sync_with_stdio(false); cin.tie(NULL);
#define ll long long

vector<ll> pow10, tot_len, sum_till_pow10_minus_1;

void precompute()
{
    const int MAX_NUM = 17;
    pow10.resize(MAX_NUM);
    pow10[0] = 1;
    for(int i = 1; i < MAX_NUM; i++) pow10[i] = pow10[i-1]*10;

    tot_len.resize(MAX_NUM);
    tot_len[0] = 0;
    for(int d = 1; d < MAX_NUM; d++)
    {
        ll nums_block = 9LL * pow10[d-1];
        ll block_len = (ll)d*nums_block;
        tot_len[d] = tot_len[d-1] + block_len;
    }

    sum_till_pow10_minus_1.resize(MAX_NUM);
    sum_till_pow10_minus_1[0] = 0;
    for(int d = 1; d < MAX_NUM; d++) sum_till_pow10_minus_1[d] = (ll)d*45LL*pow10[d-1];
}

ll sum_process(ll n);

ll sum_process(ll n)
{
    if(n<0) return 0;
    if(n < 10) return n*(n+1)/2;

    string s = to_string(n);
    int len = s.length();

    ll d_pow = pow10[len-1];
    ll a = n / d_pow;
    ll rem = n % d_pow;

    ll ans = a*sum_till_pow10_minus_1[len-1];
    ans += (a*(a-1)/2)*d_pow;

    ans += a*(rem+1);
    ans += sum_process(rem);

    return ans;
}

void solve() 
{
    ll k; cin>>k;
    int d = 1;
    while(d < 17 && k > tot_len[d]) d++;

    k -= tot_len[d-1];

    ll a = pow10[d-1];
    ll n_i = (k-1)/d;
    ll N = a + n_i;

    int digit_i = (k-1)%d;
    ll ans = 0;
    if(N>0) ans = sum_process(N-1);

    string ss = to_string(N);
    for(int i = 0; i<=digit_i; i++) ans += ss[i]-'0';

    cout<<ans<<'\n';
}

int main() {
    fast
    precompute();
    int t; cin>>t;
    while (t--) solve();
    return 0;
}
