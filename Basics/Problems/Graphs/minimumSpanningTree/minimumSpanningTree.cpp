/*
Given a weighted, undirected, and connected graph with V vertices and E edges, your task is to 
find the sum of the weights of the edges in the Minimum Spanning Tree (MST) of the graph. The graph 
is represented by an adjacency list, where each element adj[i] is a vector containing vector of integers. 
Each vector represents an edge, with the first integer denoting the endpoint of the edge and the second 
integer denoting the weight of the edge.
*/

// We use Prim's algorithm here
class Solution {
  public:
    // Function to find sum of weights of edges of the Minimum Spanning Tree.
    typedef pair<int, int> P;
    int spanningTree(int V, vector<vector<int>> adj[]) {
        // code here
        priority_queue<P, vector<P>, greater<P>> pq;
        vector<int> visited(V, 0);
        // {wt, node}
        pq.push({0,0});
        int sum = 0;
        while(!pq.empty())
        {
            int node = pq.top().second;
            int wt = pq.top().first;
            pq.pop();
            
            if(visited[node]) continue;
            // add node to MST
            visited[node] = 1;
            sum += wt;
            for(auto it: adj[node])
            {
                int adjNode = it[0];
                int edW = it[1];
                if(!visited[adjNode])
                {
                    pq.push({edW, adjNode});
                }
            }
        }
        return sum;
    }
};
