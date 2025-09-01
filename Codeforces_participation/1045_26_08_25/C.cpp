#include <bits/stdc++.h>
using namespace std;
#define fast ios_base::sync_with_stdio(false); cin.tie(NULL);

#define ll long long

void solve() {
    int n; cin >> n;
    vector<ll> a(n + 1);
    for(int i = 1; i <= n; i++) cin >> a[i];

    ll curr_prefixSum = 0;
    ll max_so_far = 0;
    ll max_upto_i_minus_2 = 0;

    ll ans = 0;

    for(int i = 1; i <= n; i++) {
        bool is_odd_pos = (i & 1);
        ll curr_term = is_odd_pos ? -a[i] : a[i];
        ll tent_prefixSum = curr_prefixSum + curr_term;

        ll required_min = (i >= 2) ? max_upto_i_minus_2 : LLONG_MIN / 2;
        ll deficit = max(0LL, required_min - tent_prefixSum);

        if(deficit > 0) {
            ans += deficit;

            if(is_odd_pos) tent_prefixSum += deficit;
            else 
            {
                curr_prefixSum += deficit;
                if(curr_prefixSum > max_so_far) max_so_far = curr_prefixSum;
                tent_prefixSum += deficit;
            }
        }

        curr_prefixSum = tent_prefixSum;
        ll old_max = max_so_far;
        max_so_far = max(max_so_far, curr_prefixSum);
        max_upto_i_minus_2 = old_max;
    }
    cout << ans << '\n';
}

int main() {
    fast
    int t; cin >> t;
    while(t--) solve();
    return 0;
}
