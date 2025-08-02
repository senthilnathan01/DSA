#include <bits/stdc++.h>
using namespace std;
#define ll long long

// O(N*Q) Approach
// This is the brute force approach
// Could not do better than this
int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int n;
    cin >> n;

    vector<vector<ll>> presents(n, vector<ll>(3));
    for (int i = 0; i < n; i++) {
        cin >> presents[i][0] >> presents[i][1] >> presents[i][2];
    }

    int q;
    cin >> q;

    for (int i = 0; i < q; i++) {
        ll mood;
        cin >> mood;

        for (int j = 0; j < n; j++) {
            if (mood <= presents[j][0]) {
                mood += presents[j][1];
            } else {
                if (mood > presents[j][2]) {
                    mood -= presents[j][2];
                } else {
                    mood = 0;
                }
            }
        }
        cout << mood << '\n';
    }

    return 0;
}
