#include<iostream>
#include<vector>

using namespace std;

/*
There are n cities. Some of them are connected, while some are not. If city a is connected directly with city b, and city b is connected directly with city c, then city a is connected indirectly with city c.

A province is a group of directly or indirectly connected cities and no other cities outside of the group.

You are given an n x n matrix isConnected where isConnected[i][j] = 1 if the ith city and the jth city are directly connected, and isConnected[i][j] = 0 otherwise.

Return the total number of provinces.
*/

// Approach 2
// Using DFS
// TC = O(n^2)
// SC = O(n)
class Solution
{
public:
    void dfs(int n, int i, bool visited[], vector<vector<int>> &isConnected)
    {
        visited[i] = true;
        for(int j = 0; j<n; j++)
        {
            if(isConnected[i][j]==1)
            {
                if(visited[j]==false)
                {
                    dfs(n, j, visited, isConnected);
                }
            }
        }
    }
    int findCircleNum(vector<vector<int>>& isConnected)
    {
        int n = isConnected.size();
        bool *visited = new bool[n];
        for(int i = 0; i<n; i++) visited[i] = false;
        int count = 0;
        for(int i = 0; i<n; i++)
        {
            if(visited[i]==false)
            {
                count++;
                dfs(n, i, visited, isConnected);
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
