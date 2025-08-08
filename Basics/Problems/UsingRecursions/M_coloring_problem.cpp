/*
You are given an undirected graph consisting of V vertices and E edges represented by a list edges[][], along with an integer m. Your task is to determine whether it is possible to color the graph using at most m different colors such that no two adjacent vertices share the same color. Return true if the graph can be colored with at most m colors, otherwise return false.

Note: The graph is indexed with 0-based indexing.

GFG Link: https://www.geeksforgeeks.org/problems/m-coloring-problem-1587115620/1
*/

class Solution {
  public:
    bool isSafe(int node, int color, vector<vector<int>> &adj, vector<int> &colors)
    {
        for (int neighbor : adj[node]) {
            if (colors[neighbor] == color) return false;
        }
        return true;        
    }
    
    bool backtrack(int node, int v, int m, vector<vector<int>> &adj, vector<int> &colors)
    {
        if(node == v)   return true;
        
        for (int color = 0; color < m; color++) 
        {
            if (isSafe(node, color, adj, colors)) 
            {
                colors[node] = color;
                if (backtrack(node + 1, v, m, adj, colors)) return true;
                colors[node] = -1;
            }
        }
        return false;
    }
    
    bool graphColoring(int v, vector<vector<int>> &edges, int m) {
        vector<vector<int>> adj(v);
        for(auto edge: edges)
        {
            adj[edge[0]].push_back(edge[1]);
            adj[edge[1]].push_back(edge[0]);
        }   
        
        vector<int> colors(v, -1);
        
        return backtrack(0, v, m, adj, colors);
        
    }
};
