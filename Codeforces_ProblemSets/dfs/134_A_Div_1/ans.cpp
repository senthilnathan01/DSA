#include<iostream>
#include<vector>

using namespace std;

#define p pair<int, int>
#define fast ios_base::sync_with_stdio(false); cin.tie(NULL);

int n;
vector<p> nodes;
vector<bool> visited;

void dfs(int index)
{
    visited[index] = true;

    for(int i = 1; i <= n; ++i)
    {
        if(!visited[i])
        {
            if(nodes[index].first == nodes[i].first || nodes[index].second == nodes[i].second)
            {
                dfs(i);
            }
        }
    }
}

int main()
{
    fast
    cin>>n;
    nodes.resize(n+1);
    visited.assign(n+1, false);

    for(int i = 1; i <= n; ++i)
    {
        cin>>nodes[i].first>>nodes[i].second;
    }

    int comp_count = 0;
    for(int i = 1; i<=n; ++i)
    {
        if(!visited[i])
        {
            dfs(i);
            comp_count++;
        }
    }

    cout<< comp_count - 1;
    return 0;
}
