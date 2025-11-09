/*
Given a Directed Acyclic Graph (DAG) of V (0 to V-1) vertices and E edges represented as a 2D list of edges[][], where each entry edges[i] = [u, v] denotes a directed edge u -> v. Return the topological sort for the given graph.

Topological sorting for Directed Acyclic Graph (DAG) is a linear ordering of vertices such that for every directed edge u -> v, vertex u comes before v in the ordering.
Note: As there are multiple Topological orders possible, you may return any of them. If your returned Topological sort is correct then the output will be true else false.

LINK: https://www.geeksforgeeks.org/problems/topological-sort/1
*/
class Solution {
  public:
    vector<int> topoSort(int V, vector<vector<int>>& edges) {
        // code here
        vector<int> inDegree(V, 0);
        vector<vector<int>> adj(V);
        for(auto e: edges){
            inDegree[e[1]]++;
            adj[e[0]].push_back(e[1]);
        }
        
        queue<int> q;
        for(int i =0; i < V; i++){
            if(inDegree[i]==0) q.push(i);
        }
        vector<int> ans;
        while(!q.empty()){
            int it = q.front();
            q.pop();
            ans.push_back(it);
            
            for(auto neighbour: adj[it]){
                inDegree[neighbour]--;
                if(inDegree[neighbour]==0) q.push(neighbour);
            }
        }
        
        return ans;
    }
};
