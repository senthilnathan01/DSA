#include<iostream>
#include<vector>
#include<queue>

using namespace std;

/*
Given a connected undirected graph represented by an adjacency list adj, which is a vector of vectors where each adj[i] represents the list of vertices connected to vertex i. 
Perform a Breadth First Traversal (BFS) starting from vertex 0, visiting vertices from left to right according to the adjacency list, and return a list containing the BFS traversal of the graph.

Note: Do traverse in the same order as they are in the adjacency list.
*/


class Solution {
  public:
    vector<int> bfsOfGraph(vector<vector<int>> &adj) {
        int v = adj.size();
        bool visited[v] = {false};
        visited[0] = true;
        
        queue<int> q;

        q.push(0);
        vector<int> bfs;
        while(!q.empty())
        {
            int node = q.front();
            q.pop();
            bfs.push_back(node);
            for(auto it: adj[node])
            {
                if(!visited[it])
                {
                    visited[it] = true;
                    q.push(it);
                }
            }
        }
        return bfs;
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
    vector<int> ans = obj.bfsOfGraph(adj);
    obj.printAns(ans);
    return 0;

}

// OUTPUT:
// 0 2 3 1 4 