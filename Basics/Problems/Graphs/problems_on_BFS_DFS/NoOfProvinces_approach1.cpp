#include<iostream>
#include<vector>

using namespace std;

/*
There are n cities. Some of them are connected, while some are not. If city a is connected directly with city b, and city b is connected directly with city c, then city a is connected indirectly with city c.

A province is a group of directly or indirectly connected cities and no other cities outside of the group.

You are given an n x n matrix isConnected where isConnected[i][j] = 1 if the ith city and the jth city are directly connected, and isConnected[i][j] = 0 otherwise.

Return the total number of provinces.
*/

// Approach 1
class Solution
{
    private:
    vector<vector<int>> connectedComps(vector<vector<int>>& adj)
    {
        vector<vector<int>> ans;

        int n = adj.size();
        bool *visited = new bool[n];
        for(int i = 0; i<n; i++) visited[i] = false;

        for(int i = 0; i<n; i++)
        {
            if(visited[i]==false)
            {
                vector<int> connectedComponent;
                DFSUtil(i, visited, connectedComponent, adj);
                ans.push_back(connectedComponent);
            }
        }
        return ans;
    }

    void DFSUtil(int i, bool visited[], vector<int> &connectedComponent, vector<vector<int>> &adj)
    {
        visited[i] = true;
        connectedComponent.push_back(i);
        
        for(auto it = adj[i].begin(); it != adj[i].end(); ++it)
        {
            if(!visited[*it]) DFSUtil(*it, visited, connectedComponent, adj);
        }
    }

    public:
    int findCircleNum(vector<vector<int>>& isConnected) {
        // Find the number of connected components
        int n = isConnected.size();
        vector<vector<int>> adj(n);
        for(int i = 0; i<n; i++)
        {
            for(int j = 0; j<n; j++)
            {
                if(isConnected[i][j]==1)
                {
                    adj[i].push_back(j);
                    adj[j].push_back(i);
                }
            }
        }
        vector<vector<int>> ans = connectedComps(adj);
        return ans.size();
    }

};

int main()
{
    vector<vector<int>> isConnected =  {{1,1,0}, {1,1,0}, {0,0,1}};
    Solution obj;
    cout<< obj.findCircleNum(isConnected);
    return 0;
}

// OUTPUT:
// 2
