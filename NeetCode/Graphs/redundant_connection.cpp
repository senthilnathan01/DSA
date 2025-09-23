/*
In this problem, a tree is an undirected graph that is connected and has no cycles.

You are given a graph that started as a tree with n nodes labeled from 1 to n, with one additional edge added. 
  The added edge has two different vertices chosen from 1 to n, and was not an edge that already existed. 
  The graph is represented as an array edges of length n where edges[i] = [ai, bi] indicates that there is an edge between nodes ai and bi in the graph.

Return an edge that can be removed so that the resulting graph is a tree of n nodes. 
  If there are multiple answers, return the answer that occurs last in the input.

LINK: https://leetcode.com/problems/redundant-connection/description/
*/

// Approach 1:
// For every new edge (in that order) we do DFS to check if the nodes are already connected
// If they are connected return the edge
// TC = O(N^2) as we do DFS everytime
class Solution {
public:
    bool isConnected(int src, int target, vector<bool> &vis, vector<vector<int>> &adj){
        vis[src] = true;
        if(src==target) return true;

        bool found = false;
        for(int node: adj[src]){
            if(!vis[node]) found = found || isConnected(node, target, vis, adj);
            if(found) return true;
        }
        return found;
    }
    vector<int> findRedundantConnection(vector<vector<int>>& edges) {
        int n = edges.size();
        vector<vector<int>> adj(n);
        for(auto edge: edges){
            vector<bool> vis(n, false);
            if(isConnected(edge[0]-1, edge[1]-1, vis, adj)) return edge;

            adj[edge[0]-1].push_back(edge[1]-1);
            adj[edge[1]-1].push_back(edge[0]-1);
        }
        return {};
    }
};

// Approach 2 Using DSU
struct DSU{
    vector<int> parent, size;
    DSU(int n){
        parent.resize(n+1);
        size.assign(n+1, 1);
        for(int i = 0; i <=n; i++) parent[i]=i;
    }

    int find(int x){
        if(parent[x]==x) return x;
        return parent[x] = find(parent[x]);
    }

    bool unite(int a, int b){
        a = find(a), b = find(b);
        if(a==b) return false; // cycle detected
        if(size[a]<size[b]) swap(a, b);
        parent[b] = a;
        size[a]+=size[b];
        return true;
    }
};

class Solution {
public:
    vector<int> findRedundantConnection(vector<vector<int>>& edges) {
        int n = edges.size();
        DSU dsu(n);
        for(auto &e: edges) if(!dsu.unite(e[0], e[1])) return e;
        return {};
    }
};
