#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

typedef long long ll;

int main() {
    ll N;
    string S;
    cin >> N >> S;

    vector<ll> ones;
    for (ll i = 0; i < N; ++i) {
        if (S[i] == '1') {
            ones.push_back(i);
        }
    }

    ll m = ones.size();
    ll median = ones[m / 2];  // Median position of 1s

    long long total_swaps = 0;
    for (ll i = 0; i < m; ++i) {
        ll target = median - (m / 2) + i;
        total_swaps += abs(ones[i] - target);
    }

    cout << total_swaps;

    return 0;
}
