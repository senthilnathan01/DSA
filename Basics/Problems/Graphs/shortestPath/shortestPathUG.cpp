/*
  You are given an adjacency list, adj of Undirected Graph having unit weight of the edges, find
  the shortest path from src to all the vertex and if it is unreachable to reach any vertex, 
  then return -1 for that vertex.
*/

class Solution {
  public:
    // Function to find the shortest path from source to all other nodes
    vector<int> shortestPath(vector<vector<int>>& adj, int src) {
        // code here
        int n = adj.size();
        vector<int> dist (n);
        for(int i = 0; i < n; i++) dist[i] = 1e9; // some big number
        dist[src] = 0;
        queue<int> q;
        q.push(src);
        
        while(!q.empty())
        {
            int node = q.front();
            q.pop();
            for(auto it: adj[node])
            {
                if(dist[node] + 1 < dist[it])
                {
                    dist[it] = 1 + dist[node];
                    q.push(it);
                }
            }
        }
        
        vector<int> ans(n, -1);
        for(int i = 0; i < n; i++)
        {
            if(dist[i] != 1e9)
            {
                ans[i] = dist[i];
            }
        }
        
        return ans;
    }
};
