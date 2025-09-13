/*
You are given an m x n binary matrix grid. An island is a group of 1's (representing land) connected 
  4-directionally (horizontal or vertical.) You may assume all four edges of the grid are surrounded by water.

The area of an island is the number of cells with a value 1 in the island.

Return the maximum area of an island in grid. If there is no island, return 0.

LINK: https://leetcode.com/problems/max-area-of-island/description/
*/

class Solution {
public:
    int dr[4] = {-1, 1, 0, 0};
    int dc[4] = {0, 0, -1, 1};
    int dfs(int r, int c, int m, int n, vector<vector<int>> &grid){
        grid[r][c] = 0;
        int ans = 0;
        for(int dir = 0; dir < 4; dir++){
            int nr = r + dr[dir], nc = c + dc[dir];
            if(nr < 0 || nr >= m || nc < 0 || nc >= n) continue;
            if(grid[nr][nc]==1) ans += dfs(nr, nc, m, n, grid);
        }
        return 1 + ans;
    }

    int maxAreaOfIsland(vector<vector<int>>& grid) {
        int m = grid.size(), n = grid[0].size();
        int maxi = 0;
        for(int r = 0; r < m; r++){
            for(int c =0; c < n; c++){
                if(grid[r][c]==1) maxi = max(maxi, dfs(r, c, m, n, grid));
                grid[r][c] = 0;
            }
        }
        return maxi;
    }
};
