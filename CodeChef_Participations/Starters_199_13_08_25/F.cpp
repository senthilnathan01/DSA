#include<bits/stdc++.h>
using namespace std;

void solve() {
    int n; cin>>n;
    vector<int> a(n), b(n);
    for (int i = 0; i < n; ++i) cin >> a[i];
    for (int i = 0; i < n; ++i) cin >> b[i];

    vector<int> min_val(n), max_val(n);
    for (int i = 0; i < n; ++i) {
        min_val[i] = min(a[i], b[i]);
        max_val[i] = max(a[i], b[i]);
    }

    vector<vector<int>> farthest(n, vector<int>(2));

    farthest[n - 1][0] = n - 1;
    farthest[n - 1][1] = n - 1;

    //DP
    for (int i = n - 2; i >= 0; --i) {
        int current_val_min = min_val[i];
        bool can_go_to_next_min = (min_val[i + 1] > current_val_min);
        bool can_go_to_next_max = (max_val[i + 1] > current_val_min);

        if (can_go_to_next_min && can_go_to_next_max) 
        {
            farthest[i][0] = max(farthest[i + 1][0], farthest[i + 1][1]);
        } 
        else if (can_go_to_next_min) 
        {
            farthest[i][0] = farthest[i + 1][0];
        } 
        else if (can_go_to_next_max) 
        {
            farthest[i][0] = farthest[i + 1][1];
        } 
        else 
        {
            farthest[i][0] = i;
        }

        int current_val_max = max_val[i];
        can_go_to_next_min = (min_val[i + 1] > current_val_max);
        can_go_to_next_max = (max_val[i + 1] > current_val_max);

        if (can_go_to_next_min && can_go_to_next_max) 
        {
            farthest[i][1] = max(farthest[i + 1][0], farthest[i + 1][1]);
        } 
        else if (can_go_to_next_min) 
        {
            farthest[i][1] = farthest[i + 1][0];
        } 
        else if (can_go_to_next_max) 
        {
            farthest[i][1] = farthest[i + 1][1];
        } 
        else 
        {
            farthest[i][1] = i;
        }
    }

    long long ans = 0;
    for (int i = 0; i < n; ++i) {
        int max_r = max(farthest[i][0], farthest[i][1]);
        ans += (long long)(max_r - i + 1);
    }

    cout<<ans<<'\n';
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int t;
    cin >> t;
    while (t--) solve();
    return 0;
}
