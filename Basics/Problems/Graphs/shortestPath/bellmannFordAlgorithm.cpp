/*
Given a weighted and directed graph of v vertices and edges, Find the shortest 
distance of all the vertex's from the source vertex, src and return a list of 
integers where the ith integer denotes the distance of the ith node from the 
source node. If a vertices can't be reach from the s then mark the distance as 10^8.
Note: If there exist a path to a negative weighted cycle from the source node then return {-1}.
  */

class Solution {
  public:
    /*  Function to implement Bellman Ford
     *   edges: vector of vectors which represents the graph
     *   src: source vertex
     *   V: number of vertices
     */
    vector<int> bellmanFord(int V, vector<vector<int>>& edges, int src) {
        // Code here
        vector<int> dist(V, 1e8);
        dist[src] = 0;
        for (int i = 0; i < V; i++)
        {
            for (auto it: edges)
            {
                int u = it[0];
                int v = it[1];
                int wt = it[2];
                if(dist[u] != 1e8 && dist[u] + wt < dist[v])
                {
                    dist[v] = dist[u] + wt;
                }
            }
        }
        // Nth relaxation to check negative cycle
        for(auto it: edges)
        {
            int u = it[0];
            int v = it[1];
            int wt = it[2];
            if(dist[u] != 1e8 && dist[u] + wt < dist[v])
            {
                return {-1};
            }
        }
        return dist;
    }
};
