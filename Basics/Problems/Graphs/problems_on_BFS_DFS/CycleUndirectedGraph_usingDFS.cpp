#include<iostream>
#include<vector>
#include<queue>

using namespace std;

/*
Given an undirected graph with V vertices labelled from 0 to V-1 and E edges, 
check whether the graph contains any cycle or not. The Graph is represented as 
an adjacency list, where adj[i] contains all the vertices that are directly connected to vertex i.

NOTE: The adjacency list represents undirected edges, meaning that if there is 
an edge between vertex i and vertex j, both j will be adj[i] and i will be in adj[j].
*/

// Using DFS

class Solution {
    private:
    bool dfs(int node, int parent, bool visited[], vector<vector<int>> &adj)
    {
        visited[node] = true;
        for(auto adjNode: adj[node])
        {
            if(!visited[adjNode])
            {
                if(dfs(adjNode, node, visited, adj)) return true;
            }
            else if(adjNode != parent) return true;
        }
        return false;
    }

    public:
    bool isCycle(vector<vector<int>> &adj)
    {
        int V = adj.size();
        bool visited[V] ={false};
        for(int i = 0; i < V; i++)
        {
            if(!visited[i])
            {
                if(dfs(i, -1, visited, adj)) return true;
            }
        }
        return false;
    }

};

int main()
{
    vector<vector<int>> adj  = {{1}, 
                                {0,2,4},
                                {1,3},
                                {2,4},
                                {1,3}};
    
    Solution obj;
    cout<<obj.isCycle(adj);

    return 0;
}

// OUTPUT:
// 1
