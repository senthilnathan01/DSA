#include<bits/stdc++.h>
using namespace std;
#define fast ios_base::sync_with_stdio(false); cin.tie(NULL);

void solve()
{
    int n;
    long long k, temp, rem, element;
    cin>>n>>k;

    map<long long, int> s_freq, t_freq;
    for (int i = 0; i < n; ++i) {
        cin >> temp;
        rem = temp % k;
        element = min(rem, (k - rem));
        s_freq[element]++;
    }

    for (int i = 0; i < n; ++i) {
        cin >> temp;
        rem = temp % k;
        element = min(rem, (k - rem));
        t_freq[element]++;
    }

    if (s_freq == t_freq) {
        cout << "YES\n";
    } else {
        cout << "NO\n";
    }
}

int main()
{
    fast
    int t; cin>>t;
    while(t--) solve();
    return 0;
}

