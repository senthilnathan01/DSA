/*
Given a weighted, undirected and connected graph where you have given adjacency list adj. 
You have to find the shortest distance of all the vertices from the source vertex src, and
return a list of integers denoting the shortest distance between each node and source vertex src.

Note: The Graph doesn't contain any negative weight edge.
*/

class Solution {
  public:
    // Function to find the shortest distance of all the vertices
    // from the source vertex src.
    vector<int> dijkstra(vector<vector<pair<int, int>>> &adj, int src) {
        // Code here
        int n = adj.size();
        priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq;
        vector<int> dist(n, 1e9), parent(n);
        for(int i = 0; i < n; i++) parent[i] = i;
        dist[src] = 0;
        pq.push({0, src});
        
        while(!pq.empty())
        {
            auto it = pq.top();
            int node = it.second;
            int dis = it.first;
            pq.pop();
            for(auto it: adj[node])
            {
                int adjNode = it.first;
                int edW = it.second;
                
                if(dis + edW < dist[adjNode])
                {
                    dist[adjNode] = dis + edW;
                    pq.push({dist[adjNode], adjNode});
                    parent[adjNode] = node;
                }
            }
        }
        for(int i = 0; i < n; i++)
        {
            if(dist[i]==1e9) dist[i] = -1;
        }
        return dist;
    }
};

