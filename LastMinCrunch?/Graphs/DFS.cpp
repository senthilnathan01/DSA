/*
Given a connected undirected graph containing V vertices represented by a 2-d adjacency list adj[][], where each adj[i] represents the list of vertices connected to vertex i. Perform a Depth First Search (DFS) traversal starting from vertex 0, visiting vertices from left to right as per the given adjacency list, and return a list containing the DFS traversal of the graph.

Note: Do traverse in the same order as they are in the given adjacency list.

LINK: https://www.geeksforgeeks.org/problems/depth-first-traversal-for-a-graph/1
# Companies: Samsung + Intuit + Goldman Sachs; But this is basics and u gotta know this!
# Difficulty: Easy
*/

// Iterative Approach using stack
class Solution {
  public:
    vector<int> dfs(vector<vector<int>>& adj) {
        int n = adj.size();
        vector<bool> vis(n, false);
        stack<int> st;
        st.push(0);
        vector<int> ans;
        while(!st.empty()){
            int node = st.top();
            st.pop();
            
            if(vis[node]) continue;
            
            ans.push_back(node);
            vis[node] = true;
            
            int sz = adj[node].size();
            for(int j = sz-1; j >=0; j--){
                if(!vis[adj[node][j]]){
                    st.push(adj[node][j]);
                }
            }
        }

        return ans;
    }
};

// Recursive Approach
class Solution {
  public:
    void dfsRec(int node, vector<int> &ans, vector<vector<int>> &adj, vector<bool> &vis){
        if(vis[node]) return;
        vis[node]= true;
        ans.push_back(node);
        for(int m: adj[node]){
            if(!vis[m]) dfsRec(m, ans, adj, vis);
        }
    }

    vector<int> dfs(vector<vector<int>>& adj) {
        int n = adj.size();
        vector<bool> vis(n, false);
        vector<int> ans;
        dfsRec(0, ans, adj, vis);
        return ans;
    }
};
