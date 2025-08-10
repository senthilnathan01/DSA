#include <bits/stdc++.h>
using namespace std;
#define fast ios_base::sync_with_stdio(false); cin.tie(NULL);

void solve() {
    int n;
    cin >> n;
    vector<int> a(n), b(n);
    for (int i = 0; i < n; i++) cin >> a[i];
    for (int i = 0; i < n; i++) cin >> b[i];

    int cnt = 1;
    while (true) {
        int idx1 = -1;
        for (int i = 0; i < n; i++) {
            if (a[i] > b[i]) {
                idx1 = i;
                break;
            }
        }
        if (idx1 == -1) break; // no such index → stop
        a[idx1]--;

        int idx2 = -1;
        for (int i = 0; i < n; i++) {
            if (a[i] < b[i]) {
                idx2 = i;
                break;
            }
        }
        if (idx2 != -1) a[idx2]++;

        cnt++;
    }
    cout << cnt << "\n";
}

int main() {
    fast
    int t;
    cin >> t;
    while (t--) solve();
    return 0;
}
