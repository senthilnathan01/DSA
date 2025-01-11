#include<iostream>
#include<vector>
#include<queue>
using namespace std;

/*
There are n cities. Some of them are connected, while some are not. If city a is connected directly with city b, and city b is connected directly with city c, then city a is connected indirectly with city c.

A province is a group of directly or indirectly connected cities and no other cities outside of the group.

You are given an n x n matrix isConnected where isConnected[i][j] = 1 if the ith city and the jth city are directly connected, and isConnected[i][j] = 0 otherwise.

Return the total number of provinces.
*/

// Approach 1
// Using BFS
// TC = O(n^2)
// SC = O(n)
class Solution {
public:
    void bfs(int node, vector<vector<int>> &isConnected, vector<bool> &visited)
    {
        queue<int> q;
        q.push(node);

        visited[node] = true;

        while(!q.empty())
        {
            node = q.front();
            q.pop();

            for(int i = 0; i < isConnected.size(); i++)
            {
                if(isConnected[node][i] && !visited[i])
                {
                    q.push(i);
                    visited[i] = true;
                }
            }
        }
    }

    int findCircleNum(vector<vector<int>>& isConnected)
    {
        int n = isConnected.size();
        int count = 0;
        vector<bool> visited(n);

        for(int i = 0; i<n; i++)
        {
            if(!visited[i])
            {
                count++;
                bfs(i, isConnected, visited);
            }
        }

        return count;
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
