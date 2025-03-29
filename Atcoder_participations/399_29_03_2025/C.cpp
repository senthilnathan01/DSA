#include<bits/stdc++.h>

using namespace std;

void dfs(int u, vector<vector<int>> &adj, vector<bool> &visited)
{
    visited[u] = true;
    for(int v: adj[u])
    {
        if(!visited[v]) dfs(v, adj, visited);
    }
}

int main()
{
    int n, m; cin>>n>>m;

    // Build adj matrix
    vector<vector<int>> adj(n);
    int u = 0, v = 0;
    for(int i = 0; i<m; i++)
    {
        cin>>u>>v;
        adj[u-1].push_back(v-1);
        adj[v-1].push_back(u-1);
    }

    vector<bool> visited(n, false);
    int k = 0;
    for(int i = 0; i < n; i++)
    {
        if(!visited[i])
        {
            dfs(i, adj, visited);
            k++;
        }
    }
    cout<<m-n+k;
    return 0;
}