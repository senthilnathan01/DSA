/*
Given a Directed Graph with V vertices (Numbered from 0 to V-1) and E edges,
check whether it contains any cycle or not.
The graph is represented as an adjacency list, where adj[i] contains a list of 
vertices that are directly reachable from vertex i. Specifically, 
adj[i][j] represents an edge from vertex i to vertex j.
*/

/*
Intuition:
If the node gets visited again on the same path then we got a cycle.
*/

class Solution {
  public:
    // Function to detect cycle in a directed graph.
    bool isCyclic(int V, vector<vector<int>> adj) {
        // code here
        vector<int> visited (V, 0);
        vector<int> pathVisited (V, 0);
        
        for(int i = 0; i < V; i++)
        {
            if(!visited[i])
            {
                if(dfsCheck(i, adj, visited, pathVisited) == true) return true;
            }
        }
        return false;
    }
    
    private:
    
    bool dfsCheck(int node, vector<vector<int>> &adj, vector<int> &visited, vector<int> &pathVisited)
    {
        visited[node] = 1;
        pathVisited[node] = 1;
        
        // Traverse for adj nodes
        for(auto it: adj[node])
        {
            // if the node is not visited
            if(!visited[it])
            {
                if(dfsCheck(it, adj, visited, pathVisited) == true) return true;
            }
            
            // if the node has been visited
            else if(pathVisited[it]) return true;
        }
        
        pathVisited[node] = 0;
        return false;
    }
};
