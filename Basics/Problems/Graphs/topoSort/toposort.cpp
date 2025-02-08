/*
Given an adjacency list for a Directed Acyclic Graph (DAG) where adj[u] contains a list of all 
vertices v such that there exists a directed edge u -> v. Return topological sort for the given graph.

Topological sorting for Directed Acyclic Graph (DAG) is a linear ordering of vertices such that 
for every directed edge u -> v, vertex u comes before v in the ordering.
Note: As there are multiple Topological orders possible, you may return any of them. If your 
returned Topological sort is correct then the output will be 1 else 0.
*/

  public:
    // Function to return list containing vertices in Topological order.
    vector<int> topologicalSort(vector<vector<int>>& adj) {
        // Your code here
        int nodes = adj.size();
        vector<int> visited (nodes, 0);
        
        stack<int> st;
        for(int node = 0; node < nodes; node++)
        {
            if(!visited[node])
            {
                dfs(node, visited, st, adj);
            }
        }
        
        vector<int> ans;
        while(!st.empty())
        {
            ans.push_back(st.top());
            st.pop();
        }
        
        return ans;
    }
private:
    void dfs(int node, vector<int> &visited, stack<int> &st, vector<vector<int>> &adj)
    {
        visited[node] = 1;
        for(auto it: adj[node])
        {
            if(!visited[it]) dfs(it, visited, st, adj);
        }
        st.push(node);
    }
