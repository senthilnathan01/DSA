#include<iostream>
#include<vector>

using namespace std;

long long n, m;
vector<long long> cost;
vector<vector<long long>> adj;
vector<bool> visited;

long long dfs(long long node)
{
    visited[node] = true;
    long long cost_region = cost[node];
    for(auto it: adj[node])
    {
        if(!visited[it])    cost_region = min(cost_region, dfs(it));
    }
    return cost_region;
}

int main()
{
    cin>>n>>m;
    cost.resize(n+1);
    adj.resize(n+1);
    for(long long i = 1; i <= n; i++) cin>>cost[i];
    long long u, v;
    for(long long i = 0; i < m; i++)
    {
        cin>>u>>v;
        adj[u].push_back(v);
        adj[v].push_back(u);
    }
    visited.assign(n+1, false);

    long long ans = 0;

    for(long long i = 1; i <= n; i++)
    {
        if(!visited[i])
        {
            ans += dfs(i);
        }
    }

    cout<<ans;
    return 0;
}
