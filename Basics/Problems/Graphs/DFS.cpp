#include<iostream>
#include<vector>
#include<queue>

using namespace std;

/*
Given a connected undirected graph represented by an adjacency list adj, which is a vector of vectors where each adj[i] represents the list of vertices connected to vertex i. 
Perform a Depth First Traversal (DFS) starting from vertex 0, visiting vertices from left to right as per the adjacency list, and return a list containing the DFS traversal of the graph.

Note: Do traverse in the same order as they are in the adjacency list.
*/


class Solution {
    private:
    void dfs(int node, vector<vector<int>> &adj, bool visited[], vector<int> &ans)
    {
        visited[node] = true;
        ans.push_back(node);

        // Traverse the neighbours
        for(auto it: adj[node])
        {
            if(!visited[it]) dfs(it, adj, visited, ans);

        }
    }

    public:
    vector<int> dfsOfGraph(vector<vector<int>> &adj) {
        int v = adj.size();
        bool visited[v] = {false};
        visited[0] = true;

        int start = 0;
        vector<int> ans;
        dfs(start, adj, visited, ans);
        return ans;
    }

    void printAns(vector<int> ans)
    {
        for(int num: ans) cout<<num<<" ";
    }
};

int main()
{
    vector<vector<int>> adj = {{2,3,1}, {0}, {0,4}, {0}, {2}};
    Solution obj;
    vector<int> ans = obj.dfsOfGraph(adj);
    obj.printAns(ans);
    return 0;

}

// OUTPUT:
// 0 2 4 3 1