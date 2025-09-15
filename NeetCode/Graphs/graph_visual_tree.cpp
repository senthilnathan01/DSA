/*
Given n nodes labeled from 0 to n - 1 and a list of undirected edges (each edge is a pair of nodes), 
write a function to check whether these edges make up a valid tree.
*/

class Solution {
public:
    vector<bool> visited;
    void dfs(int i, vector<vector<int>> &adj){
        visited[i] = true;
        for(auto it: adj[i]){
            if(!visited[it]) dfs(it, adj);
        }
    }
    bool validTree(int n, vector<vector<int>>& edges) {
        if(edges.size()!=n-1) return false;
        visited.assign(n, false);
        vector<vector<int>> adj(n);
        for(auto it: edges){
            adj[it[0]].push_back(it[1]);
            adj[it[1]].push_back(it[0]);
        }

        dfs(0, adj);
        for(int i = 0; i < n; i++) if(!visited[i]) return false;
        return true;
    }
};
