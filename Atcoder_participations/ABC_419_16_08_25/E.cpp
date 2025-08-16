#include<bits/stdc++.h>
using namespace std;
#define fast ios_base::sync_with_stdio(false); cin.tie(NULL);
#define ll long long

const ll INF = 1e18;

int main()
{
    fast
    int n, m, l; cin>>n>>m>>l;
    vector<vector<int>> group(l);
    int temp;
    for(int i = 0; i < n; i++)
    {
        cin>>temp;
        group[i%l].push_back(temp);
    }

    vector<vector<ll>> cost(l, vector<ll>(m, 0));
    for(int i = 0; i < l; i++)
    {
        if(group[i].empty()) continue;

        vector<int> cnts(m, 0);

        ll cost_t0 = 0;
        for(int x: group[i])
        {
            cnts[x%m]++;
            cost_t0 += (0-(x%m)+m) %m;
        }

        cost[i][0] = cost_t0;
        for(int t = 1; t < m; t++)
        {
            cost[i][t] = cost[i][t-1] + group[i].size() - (ll)m * cnts[t];
        }
    }

    vector<long long> dp(m, INF);
    dp[0] = 0;

    for(int i = 0; i < l; i++)
    {
        vector<long long> nextdp(m, INF);
        for(int j = 0; j < m; j++)
        {
            if(dp[j] == INF) continue;
            for(int k = 0; k < m; k++)
            {
                int nextSum = (j+k)%m;
                ll currentCost = dp[j] + cost[i][k];
                nextdp[nextSum] = min(nextdp[nextSum], currentCost);
            }
        }
        dp = nextdp;
    }
    cout<<dp[0];

    return 0;
}