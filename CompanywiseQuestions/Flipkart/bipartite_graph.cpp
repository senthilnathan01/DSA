/*
Given a Graph with V vertices (Numbered from 0 to V-1) and E edges. Check whether the graph is bipartite or not.

A bipartite graph can be colored with two colors such that no two adjacent vertices share the same color. This means we can divide the graph’s vertices into two distinct sets where:

All edges connect vertices from one set to vertices in the other set.
No edges exist between vertices within the same set.

LINK: https://www.geeksforgeeks.org/problems/bipartite-graph/1
*/

// Using BFS
class Solution {
  public:
    bool isBipartite(int V, vector<vector<int>> &edges) {
        vector<int> colour(V, -1);
        
        vector<vector<int>> adj(V);
        for(auto it: edges){
            adj[it[0]].push_back(it[1]);
            adj[it[1]].push_back(it[0]);
        }
        
        queue<int> q;
        for(int i = 0; i < V; i++){
            if(colour[i]==-1){
                colour[i]= 0;
                q.push(i);
                
                while(!q.empty()){
                    int u = q.front();
                    q.pop();
                    
                    for(auto &v: adj[u]){
                        if(colour[v]==-1){
                            colour[v] = 1 - colour[u];
                            q.push(v);
                        }
                        else if(colour[v]==colour[u]) return false;
                    }
                }
            }
        }
        
        return true;
    }
};

// We can do it using DFS too
