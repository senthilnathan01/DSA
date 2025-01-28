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

// Using BFS

class Solution {
    private: 
    bool detect(int source, vector<vector<int>> &adj, vector<int> &visited)
    {
        visited[source] = 1;
        queue<pair<int, int>> q;
        q.push({source, -1});
        
        while(!q.empty())
        {
            int node = q.front().first;
            int parent = q.front().second;
            
            q.pop();
            
            for(auto adjNode: adj[node])
            {
                if(!visited[adjNode])
                {
                    visited[adjNode] = 1;
                    q.push({adjNode, node});
                }
                else if(adjNode!=parent) return true;
            }
        }
        return false;
    }
    public:
    // Function to detect cycle in an undirected graph.
    bool isCycle(vector<vector<int>>& adj) {
        // Code here
        int n = adj.size();
        vector<int> visited (n, 0);
        
        for(int i = 0; i<n; i++)
        {
            if(!visited[i]) 
            {
                if(detect(i, adj, visited)) return true;
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
