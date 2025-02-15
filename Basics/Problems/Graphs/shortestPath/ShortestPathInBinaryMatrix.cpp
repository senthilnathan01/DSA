/*
Given an n x n binary matrix grid, return the length of the shortest clear path in the matrix. If there is no clear path, return -1.

A clear path in a binary matrix is a path from the top-left cell (i.e., (0, 0)) to the bottom-right cell (i.e., (n - 1, n - 1)) such that:

All the visited cells of the path are 0.
All the adjacent cells of the path are 8-directionally connected (i.e., they are different and they share an edge or a corner).
The length of a clear path is the number of visited cells of this path.
*/

class Solution {
public:
    typedef pair<int, pair<int, int>> P;
    int shortestPathBinaryMatrix(vector<vector<int>>& grid) {
        int n = grid.size();
        if(n==0 || grid[0][0] != 0 || grid[n-1][n-1] != 0) return -1;

        queue<P> q;

        q.push({1, {0, 0}});
        vector<vector<bool>> visited (n, vector<bool> (n, false));
        visited[0][0] = true;
        vector<pair<int, int>> directions = {{0, -1}, {0, 1}, {1, 0}, {-1, 0}, {-1, -1}, {1, 1}, {-1, 1}, {1, -1}};

        while(!q.empty())
        {
            int dis = q.front().first;
            auto cell = q.front().second;
            q.pop();

            if(cell.first == n-1 && cell.second == n-1) return dis;

            for(auto dir: directions)
            {
                int x = cell.first + dir.first, y = cell.second + dir.second;
                if(x>=0 && y>=0 && x<=n-1 && y<=n-1 && visited[x][y]==false && grid[x][y]==0)
                {
                    visited[x][y] = true;
                    q.push({dis + 1, {x, y}});
                }
                
            }
        }

        return -1;
    }
};
