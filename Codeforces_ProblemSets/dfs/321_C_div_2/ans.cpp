// Approach:
// The task -> Find the number of leaf nodes that can be reached from the root node (1)
// without passing through more than m consecutive cat nodes

// Break this down:
// Tree = Connected graph with no cycles
// Leaf nodes = Nodes connected to only one other node
// For a path, track the number of consecutive nodes with cats
// If we hit a node with no cat then reset the number

// Use DFS -> cuz explores one path completely before backtracking

#include<iostream>
#include<vector>

using namespace std;

int n, m;
vector<int> has_cat;
vector<vector<int>> adj;
int ans = 0; //counter for the final ans

// While traversing we need:
// u = current node
// parent node -> to avoid going back
// cat_count
void dfs(int u, int parent, int cat_count)
{
    // The whole logic:
    // Calculate cat_count, if no cat -> cat_count = 0; else cat_count ++;
    // If cat_count > m -> return
    
    // Do dfs for neigbors except parent
    // Check if it is a leaf
    // Do dfs if it is not
    // If it a nice lead -> ans++

    if(has_cat[u]==1) cat_count++;
    else cat_count = 0;

    if(cat_count>m) return;

    bool can_move_further = false;
    for(int v: adj[u])
    {
        if(v != parent)
        {
            can_move_further = true;
            dfs(v, u, cat_count);
        }
    }
    if(!can_move_further) ans++;
}

int main()
{
    cin>>n>>m;
    has_cat.resize(n+1);
    adj.resize(n+1);
    for(int i = 1; i <= n; i++) cin>>has_cat[i];
    int u, v;
    for(int i = 1; i <= n-1; i++)
    {
        cin>>u>>v;
        adj[u].push_back(v);
        adj[v].push_back(u);
    }

    // Root has no parent -> use dummy value like 0
    dfs(1, 0, 0);
    cout<<ans;
    return 0;
}
