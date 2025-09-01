#include <bits/stdc++.h>
using namespace std;
#define fast ios_base::sync_with_stdio(false); cin.tie(NULL);

using ll = long long;

void solve() 
{
    int n; cin>>n;
    vector<int>a(n);
    for(int i = 0; i < n; i++) cin>>a[i];

    vector<vector<int>> pos(n+1);
    vector<int> dp(n+1, 0);

    for(int i = 0; i < n; i++){
        int num = a[i];
        pos[num].push_back(i);
        int candidate = pos[num].size();
        dp[i+1] = dp[i];
        if(candidate>=num){
            int can_add = dp[pos[num][candidate -num]] + num;
            dp[i+1] = max(dp[i+1], can_add);
        }
    }
    cout<<dp[n]<<'\n';
}

int main() {
    fast
    int t; cin>>t;
    while (t--) solve();
    return 0;
}
