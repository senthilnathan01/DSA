/*
Given an undirected graph with V vertices numbered from 0 to V-1 and E edges, represented as a 2D array edges[][], where each entry edges[i] = [u, v] denotes an edge between vertices u and v.

Your task is to return a list of all connected components. Each connected component should be represented as a list of its vertices, with all components returned in a collection where each component is listed separately.

Note: You can return the components in any order, driver code will print the components in sorted order.

LINK: https://www.geeksforgeeks.org/problems/connected-components-in-an-undirected-graph/1
*/

class Solution {
  public:
    vector<vector<int>> adj;
    vector<bool> vis;
    
    void dfs(int i,vector<int> &toAdd){
        vis[i] = true;
        toAdd.push_back(i);
        for(int it: adj[i]) if(!vis[it]) dfs(it, toAdd);
    }
    vector<vector<int>> getComponents(int V, vector<vector<int>>& edges) {
        vector<vector<int>> ans;
        adj.resize(V);
        vis.assign(V, false);
        for(auto it: edges){
            adj[it[0]].push_back(it[1]);
            adj[it[1]].push_back(it[0]);
        }
        
        for(int i = 0; i<V; i++){
            if(!vis[i]){
                vector<int> toAdd;
                dfs(i, toAdd);
                ans.push_back(toAdd);
            }
        }
        return ans;
    }
};
