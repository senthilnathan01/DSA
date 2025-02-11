/*
Given a Directed Acyclic Graph of V vertices from 0 to n-1 and a 2D Integer array(or vector) edges[ ][ ] 
of length E, where there is a directed edge from edge[i][0] to edge[i][1] with a distance of edge[i][2] for all i.

Find the shortest path from src(0) vertex to all the vertices and if it is impossible to reach any vertex, then return -1 for that vertex.
*/

class Solution {
    private:
    void topoSort(int node, vector<vector<pair<int, int>>> &adj, vector<int> &visited, stack<int> &st)
    {
        visited[node] = 1;
        for(auto it: adj[node])
        {
            int v = it.first;
            if(!visited[v])
            {
                topoSort(v, adj, visited, st);
            }
        }
        st.push(node);
    }
  public:
    vector<int> shortestPath(int V, int E, vector<vector<int>>& edges) {
        // code here
        vector<vector<pair<int, int>>> adj (V);
        for(int i = 0; i < E; i++)
        {
            int u = edges[i][0];
            int v = edges[i][1];
            int wt = edges[i][2];
            
            adj[u].push_back({v, wt});
        }
        
        // Find the topo sort
        vector<int> visited (V, 0);
        stack<int> st;
        for(int i = 0; i < V; i++)
        {
            if(!visited[i])
            {
                topoSort(i, adj, visited, st);
            }
        }
        
        // find the shortest distance
        vector<int> dist(V, 1e9);
        dist[0] = 0; // dist of src to be set as 0
        while(!st.empty())
        {
            int node = st.top();
            st.pop();
            
            for(auto it: adj[node])
            {
                int v = it.first;
                int wt = it.second;
                
                if(dist[node] + wt < dist[v])
                {
                    dist[v] = dist[node] + wt;
                }
            }
        }
        
        vector<int> ans (V, -1);
        for(int i = 0; i<V; i++)
        {
            if(dist[i]!=1e9) ans[i] = dist[i];
        }
        
        return ans;
        
    }
};
