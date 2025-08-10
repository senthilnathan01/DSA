#include<bits/stdc++.h>
using namespace std;
#define fast ios_base::sync_with_stdio(false); cin.tie(NULL);

void solve()
{
    int n; cin>>n;

    int u, v;
    // trivial case
    if(n<=2)
    {
        if(n==2)
        {
            cin>>u>>v;
        }
        cout<<0<<'\n';
        return;
    }

    // adj matrix
    vector<vector<int>> adj(n);
    vector<int> degree(n, 0);

    // n - 1 lines only
    for(int i = 0; i < n - 1; i++)
    {
        cin>>u>>v;
        adj[u-1].push_back(v-1);
        adj[v-1].push_back(u-1);
        degree[u-1]++;
        degree[v-1]++;
    }

    // Count tot leaves
    int tot_leaves = 0;
    for(int i = 0; i < n; i++)
    {
        if(degree[i] == 1) tot_leaves++;
    }

    // max no of leaves adj to any node
    int max_save = 0;
    for(int i = 0; i < n; i++)
    {
        int curr_save = 0;
        for(int neighbor: adj[i])
        {
            if(degree[neighbor] == 1) curr_save++;
        }
        max_save = max(max_save, curr_save);
    }

    cout<<tot_leaves - max_save<<'\n';
}

int main()
{
    fast
    int t; cin>>t;
    while(t--) solve();
    return 0;
}

