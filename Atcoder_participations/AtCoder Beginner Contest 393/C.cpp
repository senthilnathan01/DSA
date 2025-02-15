#include<bits/stdc++.h>

using namespace std;

int main()
{
    int n, m;
    cin>>n>>m;
    // No edges -> Nothing to remove
    if(m==0)
    {
        cout<<0;
        return 0;
    }

    vector<vector<int>> adj (n+1);
    int u, v;
    for(int i = 0; i < m; i++)
    {
        cin>>u>>v;
        adj[u].push_back(v);
        adj[v].push_back(u);
    }

    int ans = 0;
    set<int> findDuplicates;
    for(int i = 1; i <= n; i++)
    {
        findDuplicates.clear();
        for(int it: adj[i])
        {
            if(it==i) ans++;
            else
            {
                if(findDuplicates.find(it)==findDuplicates.end())
                {
                    findDuplicates.insert(it);
                }
                else ans++;
            }
        }
    }
    cout<<ans/2;
    return 0;
}